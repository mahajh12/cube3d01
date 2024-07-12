/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhamel <malhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:04:14 by malhamel          #+#    #+#             */
/*   Updated: 2023/01/31 14:15:24 by malhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line_bonus.h"

char	*get_line_str(char *saved)
{
	char	*line_str;

	if (saved)
	{
		line_str = ft_strdup(saved);
		free (saved);
		saved = NULL;
	}
	else
		line_str = ft_strdup("");
	return (line_str);
}

char	*read_line(int fd, char *buffer, char *saved)
{
	int		i;
	char	*str;
	char	*line_str;

	line_str = get_line_str(saved);
	i = 1;
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
			break ;
		buffer[i] = '\0';
		str = ft_strjoin(line_str, buffer);
		free(line_str);
		line_str = ft_strdup(str);
		free(str);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (line_str);
}

char	*get_saved(char *str)
{
	int		i;
	char	*saved;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	saved = ft_substr(str, i + 1, ft_strlen(str));
	return (saved);
}

char	*get_line(char *line)
{
	char	*gnl;
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			break ;
		i++;
	}
	if (ft_strlen(line) == 0)
	{
		if (line)
			free(line);
		return (0);
	}
	gnl = ft_substr(line, 0, i + 1);
	free(line);
	if (ft_strlen(gnl) == 0)
		free(gnl);
	return (gnl);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*save[4096];
	size_t		overflow;
	char		*gnl;

	overflow = (size_t)BUFFER_SIZE;
	if (overflow <= 0 || fd < 0 || overflow > 16711568)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (overflow + 1));
	if (!buffer)
		return (NULL);
	line = read_line(fd, buffer, save[fd]);
	free (buffer);
	save[fd] = get_saved(line);
	if (ft_strlen(save[fd]) == 0 && save[fd])
	{
		free (save[fd]);
		save[fd] = NULL;
	}
	gnl = get_line(line);
	return (gnl);
}
