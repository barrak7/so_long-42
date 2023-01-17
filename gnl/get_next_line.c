/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:08:47 by hbarrak           #+#    #+#             */
/*   Updated: 2023/01/17 18:01:32 by hbarrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

static char	*gnl_app(char *dst, char **leftovers, int fd)
{
	char	*tmp;
	int		r;

	tmp = 0;
	if (*leftovers)
		tmp = ft_strjoin(0, *leftovers);
	if (found_nl(tmp, leftovers))
		return (tmp);
	dst = malloc(BUFFER_SIZE + 1);
	if (!dst)
		return (0);
	dst[0] = 0;
	while (dst && !found_nl(dst, leftovers))
	{
		r = read(fd, dst, BUFFER_SIZE);
		if (r <= 0)
			break ;
		dst[r] = 0;
		tmp = ft_strjoin(tmp, dst);
	}
	free(dst);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*leftovers;
	char		*dst;

	dst = 0;
	dst = gnl_app(dst, &leftovers, fd);
	if (dst)
		dst = ft_strtrim_nl(dst);
	return (dst);
}
