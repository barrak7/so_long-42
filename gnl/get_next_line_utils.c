/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:31:17 by hbarrak           #+#    #+#             */
/*   Updated: 2023/01/17 18:00:47 by hbarrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strtrim_nl(char *str)
{
	int		i;
	int		len;
	char	*p;

	i = 0;
	len = 0;
	while (str && str[len] && str[len] != '\n')
		len++;
	if (str[len] != '\n')
		return (str);
	p = malloc(len + 2);
	if (p)
	{
		while (str[i] && i < len + 1)
		{
			p[i] = str[i];
			i++;
		}
		p[i] = 0;
	}
	free(str);
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	sl1;
	size_t	sl2;
	char	*p;

	i = 0;
	sl1 = ft_strlen(s1);
	sl2 = ft_strlen(s2);
	p = malloc(sl1 + sl2 + 1);
	if (!p)
		return (0);
	while (i < sl1 && s1 && s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < sl2 && s2 && s2[i])
		p[sl1++] = s2[i++];
	p[sl1] = 0;
	if (s1)
		free(s1);
	return (p);
}

char	*ft_substr(char *src, int start, size_t len)
{
	int		i;
	char	*p;

	i = 0;
	p = malloc(len + 1);
	if (!p)
		return (0);
	while (src[start])
	{
		p[i] = src[start];
		start++;
		i++;
	}
	p[i] = 0;
	return (p);
}

int	found_nl(char *dst, char **leftovers)
{
	int	i;

	i = 0;
	if (*leftovers)
	{
		free(*leftovers);
		*leftovers = 0;
	}
	while (dst && dst[i] && dst[i] != '\n')
		i++;
	if (dst && dst[i] == '\n' && dst[i + 1])
	{
		*leftovers = ft_substr(dst, i + 1, ft_strlen(&dst[i + 1]));
		return (1);
	}
	if (dst && dst[i] == '\n')
		return (1);
	return (0);
}
