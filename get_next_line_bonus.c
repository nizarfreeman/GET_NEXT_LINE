/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaska <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:31:38 by nfaska            #+#    #+#             */
/*   Updated: 2024/12/14 15:50:01 by nfaska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*get_line(int fd, char **line)
{
	char	*buff;
	ssize_t	i;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	i = 1;
	while (i > 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i < 0)
		{
			free(buff);
			free(*line);
			return (NULL);
		}
		if (i == 0)
			break ;
		buff[i] = '\0';
		*line = ft_strjoin(*line, buff);
		if (search(*line))
			break ;
	}
	free(buff);
	return (*line);
}

char	*make_shyata(char *line)
{
	char	*ret;
	int		index;

	if (!line)
		return (NULL);
	index = search(line);
	ret = malloc(ft_strlen(line + index) + 1);
	if (!ret)
		return (NULL);
	ft_strcpy(ret, line + index + 1);
	return (ret);
}

char	*make_half(char *line)
{
	char	*ret;
	int		index;
	int		i;

	if (!line)
		return (NULL);
	index = search(line);
	ret = malloc(index + 2);
	if (!ret)
		return (NULL);
	ret[index + 1] = '\0';
	i = 0;
	while (i <= index)
	{
		ret[i] = line[i];
		i++;
	}
	return (ret);
}

int	process_shyata(char **line, char **shyata, char **half)
{
	char	*tmp;

	if (!search(*shyata))
	{
		*line = ft_strjoin(*shyata, NULL);
		*shyata = NULL;
		return (0);
	}
	tmp = *shyata;
	*half = make_half(*shyata);
	if (!*half)
		free(*half);
	*shyata = make_shyata(*shyata);
	free(tmp);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*shyata[1024] = {NULL};
	char		*line;
	char		*half;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX
		|| read(fd, 0, 0) < 0)
		return (NULL);
	line = NULL;
	if (shyata[fd])
		if (process_shyata(&line, &shyata[fd], &half))
			return (half);
	line = get_line(fd, &line);
	if (!line)
		return (NULL);
	if (search(line))
	{
		shyata[fd] = make_shyata(line);
		half = make_half(line);
		free(line);
		return (half);
	}
	return (line);
}
