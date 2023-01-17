/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:25:47 by hbarrak           #+#    #+#             */
/*   Updated: 2023/01/17 11:39:41 by hbarrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
}			t_data;

typedef struct s_elem
{
	int		c;
	int		p;
	int		e;
	int		*p_p;
	int		x;
	int		y;
}			t_elem;

typedef struct s_params
{
	t_data	*mlx;
	t_elem	*elems;
	char	**map;
	int		collected;
	int		moves;
}			t_params;

char		**pars_map(char **argv, int argc, t_elem *elems);
void		init_elems(t_elem *elems, int length);
void		check_boundaries(char *line, t_elem elems);
void		check_line(char *line, size_t length, int l, t_elem *elems);
int			count_lines(int fd);
int			*get_position(char **map);
void		err_n_exit(char *s);
void		put_image(char c, int y, int x, t_data mlx);
void		display_map(char **map, t_elem elems, t_data mlx);
int			exit_f(void);
void		aff_moves(t_data *data, int moves);
int			check_dest(t_params *params, char target);

#endif
