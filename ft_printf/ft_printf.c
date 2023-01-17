/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:35:35 by hbarrak           #+#    #+#             */
/*   Updated: 2022/11/01 16:08:47 by hbarrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_conv(char c)
{
	int		i;
	char	*p;

	i = 0;
	p = "cspdiuxX\045";
	while (p[i])
	{
		if (p[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_pr_app(va_list ap, const char *s, int *pr)
{
	char	c;

	if (*(s + 1) == 'c')
	{
		c = va_arg(ap, int);
		(*pr) += write(1, &c, 1);
	}
	else if (*(s + 1) == '%')
		(*pr) += write(1, "%", 1);
	else if (*(s + 1) == 's')
		(*pr) += ft_putstr_sp(va_arg(ap, char *), 0, 0);
	else if (*(s + 1) == 'd' || *(s + 1) == 'i')
		(*pr) += ft_putnbr(va_arg(ap, int));
	else if (*(s + 1) == 'u')
		(*pr) += ft_putnbr(va_arg(ap, unsigned int));
	else if (*(s + 1) == 'x' || *(s + 1) == 'X')
		(*pr) += ft_putnbr_hex(va_arg(ap, unsigned int), *(s + 1));
	else if (*(s + 1) == 'p')
		(*pr) += ft_putnbr_hex(va_arg(ap, unsigned long), 'p');
	return (2);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		pr;
	int		j;

	va_start(ap, s);
	i = 0;
	pr = 0;
	while (s[i])
	{
		if (s[i] == '%' && is_conv(s[i + 1]))
			i += ft_pr_app(ap, &s[i], &pr);
		else
		{
			if (s[i] == '%')
				i++;
			j = i;
			while (s[i] && s[i] != '%')
				i++;
			pr += ft_putstr_sp(s, j, i - j);
		}
	}
	va_end(ap);
	return (pr);
}
