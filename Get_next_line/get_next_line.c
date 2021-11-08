/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 07:47:47 by abrun             #+#    #+#             */
/*   Updated: 2021/11/08 09:46:55 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

int	ft_strchr(char *s, char c)
{
	int	counter;

	if (!s)
		return (0);
	counter = 0;
	while (s[counter] && s[counter] != c)
		counter++;
	if (s[counter])
		return (1);
	return (0);
}

char	*init_buf(char *buf)
{
	if (!buf)
	{
		buf = malloc(BUFFER_SIZE + 1);
		*buf = 0;
	}
	return (buf);
}

char	*ft_strjoin_free(char *line, char *buf)
{
	char	*res;
	size_t	line_len;
	size_t	buf_len;
	int		counter;

	line_len = ft_strlen(line);
	buf_len = ft_strlen(buf);
	if (!line_len && !buf_len)
		return (NULL);
	res = malloc(line_len + buf_len + 1);
	if (!res)
		return (NULL);
	counter = 0;
	while (line_len && line[counter])
	{
		res[counter] = line[counter];
		counter++;
	}
	while (buf_len && buf[counter - line_len] != '\n'
			&& buf[counter - line_len])
	{
		res[counter] = buf[counter - line_len];
		counter++;
	}
	if (line)
		free(line);
	if (buf[counter - line_len])
		res[counter++] = '\n';
	res[counter] = 0;
	return (res);
}

char	*get_new_buf(char *buf, int ret)
{
	char	*new;
	int		c_1;
	int		c_2;

	if (ret < 0)
	{
		if (buf)
			free(buf);
		return (NULL);
	}
	c_1 = 0;
	while (buf[c_1] && buf[c_1] != '\n')
		c_1++;
	new = malloc(BUFFER_SIZE + 1);
	if (!new)
	{
		if (buf)
			free(buf);
		return (NULL);
	}
	c_2 = 0;
	c_1++;
	while (buf[c_1])
	{
		new[c_2] = buf[c_1];
		c_1++;
		c_2++;
	}
	new[c_2] = 0;
	free(buf);
	return (new);
}

char	*get_next_line(int fd)
{
	char		*line;
	int		ret;
	static char	*buf = NULL;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = init_buf(buf);
	if (!buf)
		return (NULL);
	ret = 1;
	line = NULL;
	if (*buf)
	{
		line = ft_strjoin_free(line, buf);
		if (!line)
			ret = -1;
	}
	while (ret > 0 && !ft_strchr(buf, '\n'))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret >= 0)
		{
			buf[ret] = 0;
			line = ft_strjoin_free(line, buf);
			if (!line)
				ret = -1;
		}
	}
	buf = get_new_buf(buf, ret);
	return (line);
}

int	main(int ac, char **av)
{
	int	fd;
	char	*line;

	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (2);
	int n = 3;
	while ((line = get_next_line(fd)) && n--)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
