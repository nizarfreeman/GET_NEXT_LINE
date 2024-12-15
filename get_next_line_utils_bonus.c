/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaska <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:32:01 by nfaska            #+#    #+#             */
/*   Updated: 2024/12/14 01:27:50 by nfaska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	char	*p;

	p = s;
	while (*s)
		s++;
	return (s - p);
}

void	copy(char **p, char *s)
{
	if (s)
	{
		while (*s)
		{
			**p = *s;
			(*p)++;
			s++;
		}
	}
}

char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	char	*res_2;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = 0;
	s2_len = 0;
	if (!s1 && !s2)
		return (NULL);
	if (s1)
		s1_len = ft_strlen(s1);
	if (s2)
		s2_len = ft_strlen(s2);
	res = (char *) malloc(s1_len + s2_len + 1);
	if (!res)
		return (NULL);
	res_2 = res;
	copy(&res, s1);
	copy(&res, s2);
	free(s1);
	*res = '\0';
	return (res_2);
}

int	search(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
