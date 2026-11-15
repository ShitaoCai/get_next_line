/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: shicai <shicai@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/09 12:16:49 by shicai        #+#    #+#                 */
/*   Updated: 2026/11/15 16:52:44 by shicai        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*stash;
	char			read_checker;
	char			*line;
	char			*rest;

	if (fd < 0 || BUFFER_SIZE <= 0
		|| read(fd, &read_checker, 0) < 0)
		return (free(stash), stash = NULL, NULL);
	stash = read_to_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	if (!line)
		return (free(stash), stash = NULL, NULL);
	rest = get_remainder(stash);
	if (ft_strchr(stash, '\n') && ft_strlen(ft_strchr(stash, '\n') + 1) > 0
		&& !rest)
		return (free(line), free(stash), stash = NULL, NULL);
	free(stash);
	stash = rest;
	return (line);
}

char	*append_buffer(char *stash, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(stash, buffer);
	free(stash);
	return (temp);
}

char	*read_to_stash(int fd, char *stash)
{
	char		*buffer;
	ssize_t		bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(stash), NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(stash), NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		stash = append_buffer(stash, buffer);
		if (!stash)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (stash);
}

char	*get_remainder(char *stash)
{
	size_t	len;
	char	*newline;
	char	*remainder;

	if (!stash)
		return (NULL);
	newline = ft_strchr(stash, '\n');
	if (!newline)
		return (NULL);
	len = ft_strlen(newline + 1);
	if (len == 0)
		return (NULL);
	remainder = ft_substr(newline + 1, 0, len);
	return (remainder);
}
