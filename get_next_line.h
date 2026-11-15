/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: shicai <shicai@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/09 12:17:17 by shicai        #+#    #+#                 */
/*   Updated: 2026/11/15 16:54:41 by shicai        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

# include <sys/types.h> /* for ssize_t */
# include <unistd.h> /* read(), close() */
# include <fcntl.h>  /* open() */
# include <stdio.h> /* printf() */
# include <stdlib.h> /* free() */

/* The main functions */
char	*get_next_line(int fd);
char	*extract_line(char *stash);
/* Allocate a buffer of BUFFER_SIZE + 1.
Read bytes using read().
Null-terminate the buffer.
Append the buffer to stash using ft_strjoin().
Continue until a newline is found or EOF is reached.
Free the temporary buffer.
Return the updated stash. */
char	*read_to_stash(int fd, char *stash);
char	*append_buffer(char *stash, char *buffer);
char	*get_remainder(char *stash);
/* The helper functions */
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, size_t start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

#endif