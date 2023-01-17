/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:47:27 by hbarrak           #+#    #+#             */
/*   Updated: 2022/11/01 16:27:18 by hbarrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_app(unsigned long nb, char *dst, int base, char ca)
{
	char	*h;
	char	*l;
	int		dc;

	dc = ft_dc(nb, base);
	h = "0123456789ABCDEF";
	l = "0123456789abcdef";
	if (ca == 'p')
		dc += 2;
	if (ca == 'x' || ca == 'p')
	{
		while (nb)
		{
			dc--;
			dst[dc] = l[nb % base];
			nb /= base;
		}
		return ;
	}
	while (nb)
	{
		dc--;
		dst[dc] = h[nb % base];
		nb /= base;
	}
}

int	ft_putnbr_hex(unsigned long nb, char ca)
{
	int		i;
	int		dc;
	char	*p;

	i = 0;
	dc = ft_dc(nb, 16);
	if (ca == 'p')
	{
		p = malloc(dc + 3);
		p[0] = '0';
		p[1] = 'x';
		p[2] = '0';
		p[dc + 2] = 0;
		ft_app(nb, p, 16, 'p');
	}
	else
	{
		p = malloc(dc + 1);
		p[dc] = '\0';
		p[0] = '0';
		ft_app(nb, p, 16, ca);
	}
	dc = ft_putstr_sp(p, 0, 0);
	free(p);
	return (dc);
}
