/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 09:31:21 by hbarrak           #+#    #+#             */
/*   Updated: 2022/12/29 17:37:01 by hbarrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strtrim_nl(char *str);
int		found_nl(char *dst, char **leftovers);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *src, int start, size_t len);

#endif
