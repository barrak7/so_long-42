/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:57:32 by hbarrak           #+#    #+#             */
/*   Updated: 2023/01/17 18:03:09 by hbarrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	{
		p[sl1] = s2[i];
		i++;
		sl1++;
	}
	p[sl1] = 0;
	return (p);
}
