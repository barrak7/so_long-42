/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:28:23 by hbarrak           #+#    #+#             */
/*   Updated: 2023/01/17 17:59:29 by hbarrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_colls(char **map, t_elem elems, int x, int y)
{
	static int	c;

	if (x < 0 || x >= elems.x || y < 0 || y >= elems.y)
		return (c);
	else if (map[y][x] != 'P' && map[y][x] != '0' && map[y][x] != 'C')
		return (c);
	else if (map[y][x] == 'C')
	{
		map[y][x] = 'c';
		c++;
	}
	else if (map[y][x] == '0')
		map[y][x] = 'g';
	else if (map[y][x] == 'P')
		map[y][x] = 'p';
	check_colls(map, elems, x - 1, y);
	check_colls(map, elems, x + 1, y);
	check_colls(map, elems, x, y - 1);
	check_colls(map, elems, x, y + 1);
	return (c);
}

int	check_exit(char **map, t_elem elems, int x, int y)
{
	static int	e;

	if (x < 0 || x >= elems.x || y < 0 || y >= elems.y)
		return (e);
	else if (map[y][x] != 'p' && map[y][x] != 'g' && map[y][x] != 'c'
			&& map[y][x] != 'E')
		return (e);
	else if (map[y][x] == 'c')
		map[y][x] = 'C';
	else if (map[y][x] == 'g')
		map[y][x] = '0';
	else if (map[y][x] == 'p')
		map[y][x] = 'P';
	else if (map[y][x] == 'E')
	{
		map[y][x] = 'e';
		e = 1;
	}
	check_exit(map, elems, x - 1, y);
	check_exit(map, elems, x + 1, y);
	check_exit(map, elems, x, y - 1);
	check_exit(map, elems, x, y + 1);
	return (e);
}

void	check_map(char **map, t_elem *elems)
{
	int	i;
	int	length;

	length = ft_strlen(map[0]) - 1;
	i = 0;
	while (map[i])
	{
		check_line(map[i], length, i, elems);
		i++;
	}
	if (elems->c < 1 || elems->e != 1 || elems->p != 1)
		err_n_exit("ERROR\nInvalid map!\n");
	elems->p_p = get_position(map);
	if (check_colls(map, *elems, elems->p_p[0], elems->p_p[1]) != elems->c
		|| !check_exit(map, *elems, elems->p_p[0], elems->p_p[1]))
		err_n_exit("ERROR\nInvalid map!\n");
}

char	**read_map(char *file, t_elem *elems, int fd)
{
	char	**map;
	int		i;
	int		ln;

	ln = count_lines(fd) - 1;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		write(2, "ERROR\n", 6);
		perror(file);
		exit(1);
	}
	elems->y = ln;
	map = malloc(sizeof(char *) * (ln + 1));
	i = 0;
	while (map && 1)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			break ;
		i++;
	}
	close(fd);
	return (map);
}

char	**pars_map(char **argv, int argc, t_elem *elems)
{
	char	**map;
	int		fd;

	if (argc != 2)
		err_n_exit("ERROR\nToo many arguments!\n");
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 5))
		err_n_exit("ERROR\nInvalid file extension!\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(2, "ERROR\n", 6);
		perror(argv[1]);
		exit(1);
	}
	map = read_map(argv[1], elems, fd);
	if (!map)
		err_n_exit("ERROR\nInvalid map!");
	check_map(map, elems);
	return (map);
}
