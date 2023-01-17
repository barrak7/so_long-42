/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parser_help.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:10:58 by hbarrak           #+#    #+#             */
/*   Updated: 2023/01/17 17:52:27 by hbarrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_elems(t_elem *elems, int length)
{
	elems->c = 0;
	elems->p = 0;
	elems->e = 0;
	elems->x = length;
}

void	check_boundaries(char *line, t_elem elems)
{
	int	i;

	i = 0;
	while (i < elems.x)
	{
		if (line[i] != '1')
			exit(1);
		i++;
	}
}

void	err_n_exit(char *s)
{
	ft_putstr_fd(s, 2);
	exit(1);
}

void	check_line(char *line, size_t length, int l, t_elem *elems)
{
	int	i;

	if (ft_strlen(line) - 1 != length)
		exit(1);
	if (l == 0)
		init_elems(elems, length);
	if (l == 0 || l == elems->y - 1)
		check_boundaries(line, *elems);
	i = 0;
	while (i < elems->x)
	{
		if (line[i] == 'P')
			elems->p += 1;
		else if (line[i] == 'C')
			elems->c += 1;
		else if (line[i] == 'E')
			elems->e += 1;
		if ((line[i] != '0' && line[i] != '1' && line[i] != 'P'
				&& line[i] != 'C' && line[i] != 'E') || ((i == 0
					|| i == elems->x - 1) && line[i] != '1'))
			err_n_exit("ERROR\nInvalid map!\n");
		i++;
	}
}

int	count_lines(int fd)
{
	int		i;
	char	*ptr;

	i = 1;
	while (1)
	{
		ptr = get_next_line(fd);
		if (!ptr)
			break ;
		free(ptr);
		i++;
	}
	if (!i)
		err_n_exit("ERROR\nInvalid map!\n");
	close(fd);
	return (i);
}
