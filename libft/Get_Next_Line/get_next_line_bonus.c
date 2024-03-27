/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyes <ilyes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:53:16 by isouaidi          #+#    #+#             */
/*   Updated: 2023/08/01 18:27:16 by ilyes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*next_line(char *save)
{
	int		i;
	int		j;
	char	*newsave;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	newsave = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	i++;
	j = 0;
	while (save[i])
		newsave[j++] = save[i++];
	free(save);
	newsave[j] = '\0';
	return (newsave);
}

char	*this_line(char *save)
{
	int		i;
	char	*line;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_free(char *save, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(save, buffer);
	free(save);
	return (temp);
}

char	*read_all(int fd, char *save)
{
	char	*buffer;
	int		bytes;

	if (!save)
		save = ft_strdup("");
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	bytes = -6;
	while (bytes != 0 && !ft_strchr(save, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			free(save);
			return (NULL);
		}
		buffer[bytes] = '\0';
		save = ft_free(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*get_next_line_bonus(int fd)
{
	static char	*save[65534];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save[fd] = read_all(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = this_line(save[fd]);
	save[fd] = next_line(save[fd]);
	if (line[0] == '\0')
	{
		free(save[fd]);
		free(line);
		return (NULL);
	}
	return (line);
}
