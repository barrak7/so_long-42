/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:48:52 by hbarrak           #+#    #+#             */
/*   Updated: 2022/11/01 16:27:55 by hbarrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_app(long nb, char *dst, int dc)
{
	while (nb)
	{
		dst[dc] = nb % 10 + 48;
		nb /= 10;
		dc--;
	}
}

int	ft_putnbr(long int nb)
{
	int		dc;
	char	*p;
	long	n;

	n = nb;
	if (n == 0)
		return (ft_putstr_sp("0", 0, 1));
	if (n < 0)
	{
		dc = ft_dc(n * -1, 10);
		p = malloc(dc + 2);
		p[0] = '-';
		p[dc + 1] = 0;
		ft_app(n * -1, p, dc);
	}
	else
	{
		dc = ft_dc(nb, 10);
		p = malloc(dc + 1);
		p[dc] = 0;
		ft_app(nb, p, dc - 1);
	}
	dc = ft_putstr_sp(p, 0, 0);
	free(p);
	return (dc);
}
