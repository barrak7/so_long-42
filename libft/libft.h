/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:19:18 by hbarrak           #+#    #+#             */
/*   Updated: 2023/01/17 11:27:20 by hbarrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

long	ft_atoi(const char *str);

int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		wc(char const *s, char c);

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);

void	ft_bzero(void *s, size_t n);
void	fr_s(char **p);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	ft_putstr_fd(char *s, int fd);

#endif
