/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:38:26 by ml-hote           #+#    #+#             */
/*   Updated: 2025/02/24 19:30:44 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_previous(const char *s)
{
	int		i;
	char	*ptr;

	if (s == NULL || s[0] == '\0')
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	ptr = malloc((i + 1 + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
	{
		ptr[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		ptr[i] = '\n';
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_next(char *s)
{
	int		n;
	int		i;
	char	*ptr;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\0')
	{
		safe_free(s);
		return (NULL);
	}
	n = ft_strlen(s);
	ptr = malloc((n - i) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	n = 0;
	i++;
	while (s[i] != '\0')
		ptr[n++] = s[i++];
	ptr[n] = '\0';
	safe_free(s);
	return (ptr);
}

int	ft_newline(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_read(int fd, char *buffer, char *tmp, char *s)
{
	int		bytes_read;

	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		buffer[bytes_read] = '\0';
		tmp = s;
		if (tmp == NULL)
		{
			tmp = malloc(sizeof(char));
			if (tmp == NULL)
				return (NULL);
			tmp[0] = '\0';
		}
		s = ft_strjoin(tmp, buffer);
		safe_free(tmp);
		if (ft_newline(s) == GNL_NEWLINE || bytes_read == GNL_END_OF_FILE)
			break ;
	}
	safe_free(buffer);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*buffer;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	tmp = NULL;
	s = ft_read(fd, buffer, tmp, s);
	if (s == NULL)
	{
		free(buffer);
		return (NULL);
	}
	line = ft_previous(s);
	s = ft_next(s);
	return (line);
}
