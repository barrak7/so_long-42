/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:27:08 by hbarrak           #+#    #+#             */
/*   Updated: 2023/01/17 17:57:14 by hbarrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*get_position(char **map)
{
	int	i;
	int	j;
	int	*pos;

	pos = malloc(sizeof(int *) * 2);
	if (!pos)
		exit(1);
	i = 1;
	while (map[i])
	{
		j = 1;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				pos[0] = j;
				pos[1] = i;
				break ;
			}
			j++;
		}
		i++;
	}
	return (pos);
}

void	move_player(t_params *params, int x, int y)
{
	int	*p;

	p = params->elems->p_p;
	if (params->map[y][x] == 'C')
	{
		params->map[y][x] = '0';
		put_image('0', y, x, *(params->mlx));
	}
	put_image('P', y, x, *(params->mlx));
	put_image('0', p[1], p[0], *(params->mlx));
	params->map[p[1]][p[0]] = '0';
	p[0] = x;
	p[1] = y;
}

int	key_handle(int keycode, t_params *params)
{
	int	*p;

	p = params->elems->p_p;
	if (keycode == 13 && check_dest(params, params->map[p[1] - 1][p[0]]))
		move_player(params, p[0], p[1] - 1);
	else if (keycode == 0 && check_dest(params, params->map[p[1]][p[0] - 1]))
		move_player(params, p[0] - 1, p[1]);
	else if (keycode == 1 && check_dest(params, params->map[p[1] + 1][p[0]]))
		move_player(params, p[0], p[1] + 1);
	else if (keycode == 2 && check_dest(params, params->map[p[1]][p[0] + 1]))
		move_player(params, p[0] + 1, p[1]);
	else if (keycode == 53)
		exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	char		**map;
	t_elem		elems;
	t_data		mlx;
	t_params	param;

	param.elems = &elems;
	param.mlx = &mlx;
	param.moves = 0;
	param.collected = 0;
	map = pars_map(argv, argc, &elems);
	param.map = map;
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		exit(1);
	mlx.win = mlx_new_window(mlx.mlx, elems.x * 50, elems.y * 50, "So Long!");
	if (!mlx.win)
		exit(1);
	display_map(map, elems, mlx);
	mlx_hook(mlx.win, 2, 0, key_handle, &param);
	mlx_hook(mlx.win, 17, 0, exit_f, 0);
	aff_moves(&mlx, 0);
	mlx_loop(mlx.mlx);
	return (0);
}
