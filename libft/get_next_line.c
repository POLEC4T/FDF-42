/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:06:28 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/19 18:09:52 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*extract_line(char *buffer)
{
	int		nl_idx;
	char	*line;

	if (!buffer)
		return (NULL);
	nl_idx = ft_strchr_idx((const char *)buffer, '\n');
	line = ft_strndup(buffer, nl_idx + (nl_idx >= 0));
	return (line);
}

void	rm_line(char *buffer)
{
	int	nl_idx;
	int	i;

	if (!buffer)
		return ;
	nl_idx = ft_strchr_idx(buffer, '\n');
	if (!buffer[nl_idx])
	{
		buffer[0] = '\0';
		return ;
	}
	i = 0;
	while (buffer[nl_idx + i + 1])
	{
		buffer[i] = buffer[nl_idx + i + 1];
		i++;
	}
	buffer[i] = '\0';
}

char	*read_file(char *str, char *buffer, int fd)
{
	ssize_t	bytes_read;
	char	*new_str;

	bytes_read = -1;
	while (ft_strchr_idx(buffer, '\n') == -1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(str);
			buffer[0] = '\0';
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		new_str = ft_strjoin(str, buffer);
		free(str);
		str = new_str;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = NULL;
	if (buffer[0] != '\0')
	{
		str = ft_strndup(buffer, ft_strlen(buffer));
		if (!str)
			return (NULL);
	}
	str = read_file(str, buffer, fd);
	if (!str)
		return (NULL);
	line = extract_line(str);
	rm_line(buffer);
	free(str);
	return (line);
}
