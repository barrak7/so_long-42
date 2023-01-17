/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:37:13 by hbarrak           #+#    #+#             */
/*   Updated: 2023/01/17 11:38:34 by hbarrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(char c, int y, int x, t_data mlx)
{
	char	*path;
	void	*img;
	int		width;
	int		height;

	if (c == '1')
		path = "pictures/wall.xpm";
	else if (c == '0')
		path = "pictures/ground.xpm";
	else if (c == 'P')
		path = "pictures/player.xpm";
	else if (c == 'C')
		path = "pictures/collectible.xpm";
	else
		path = "pictures/exit.xpm";
	img = mlx_xpm_file_to_image(mlx.mlx, path, &width, &height);
	if (!img)
	{
		write(2, "Error\nInvalid xpm file!\n", 24);
		exit(1);
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, img, x * 50, y * 50);
}

void	display_map(char **map, t_elem elems, t_data mlx)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (j < elems.x)
		{
			put_image(map[i][j], i, j, mlx);
			j++;
		}
		i++;
	}
}

int	exit_f(void)
{
	exit(0);
}

void	aff_moves(t_data *data, int moves)
{
	char	*number;

	number = ft_itoa(moves);
	put_image('1', 0, 0, *data);
	mlx_string_put(data->mlx, data->win, 10, 10, 16777215, number);
	ft_printf("Current number of moves: %d\r", moves);
	free(number);
}

int	check_dest(t_params *params, char target)
{
	if (target == '0')
	{
		params->moves += 1;
		aff_moves(params->mlx, params->moves);
		return (1);
	}
	else if (target == 'C')
	{
		params->collected += 1;
		params->moves += 1;
		aff_moves(params->mlx, params->moves);
		return (1);
	}
	else if (target == 'e' && params->collected == params->elems->c)
	{
		aff_moves(params->mlx, params->moves + 1);
		exit(0);
	}
	return (0);
}
