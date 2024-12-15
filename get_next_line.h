/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaska <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:31:56 by nfaska            #+#    #+#             */
/*   Updated: 2024/12/15 19:24:01 by nfaska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

size_t	ft_strlen(char *s);
int		search(char *s);
char	*ft_strcpy(char *dst, char *src);
void	ft_strncpy(char *dst, char *src, size_t n);
char	*ft_strjoin(char *s1, char *s2);
void	copy(char **p, char *s);

#endif
