/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaska <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:31:13 by nfaska            #+#    #+#             */
/*   Updated: 2024/12/15 22:59:44 by nfaska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

size_t	ft_strlen(char *s);
int		search(char *s);
char	*ft_strcpy(char *dst, char *src);
char	*ft_strjoin(char *s1, char *s2);
void	copy(char **p, char *s);

#endif
