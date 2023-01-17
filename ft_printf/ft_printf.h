/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:32:33 by hbarrak           #+#    #+#             */
/*   Updated: 2022/11/01 17:17:58 by hbarrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_putstr_sp(const char *s, int start, int len);
int		ft_putnbr_hex(unsigned long nb, char ca);
int		ft_dc(unsigned long nb, int base);
int		ft_printf(const char *s, ...);
size_t	ft_strlen(const char *s);
int		ft_putnbr(long int nb);

#endif
