/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmadouan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 16:30:14 by mmadouan          #+#    #+#             */
/*   Updated: 2026/01/30 16:30:20 by mmadouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(char *buff)
{
	char	*line;
	int		i;

	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (buff[i] == '\n')
		i++;
	line = ft_substr(buff, 0, i);
	return (line);
}

char	*read_nline(char **buff, int fd)
{
	ssize_t	count;
	char	*buff_free;
	char	*tmp;

	count = 1;
	while (ft_strchr(*buff) == -1 && count != 0)
	{
		tmp = malloc(BUFFER_SIZE + 1);
		count = read(fd, tmp, BUFFER_SIZE);
		if (count == -1)
			return (free(tmp), NULL);
		tmp[count] = '\0';
		buff_free = *buff;
		*buff = ft_strjoin(buff_free, tmp);
		free(buff_free);
		free(tmp);
	}
	return (*buff);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	int		length;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	length = ft_strlen(s);
	if (start > length)
		return (ft_strdup(""));
	if (len > length - start)
		len = length - start;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char		*buff;
	char			*line;
	char			*buff_free;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (!buff)
		buff = ft_strdup("");
	read_nline(&buff, fd);
	if (!buff[0])
		return (free(buff), buff = 0, NULL);
	line = read_line(buff);
	buff_free = ft_substr(buff, ft_strlen(line), ft_strlen(buff)
			- ft_strlen(line));
	free(buff);
	buff = buff_free;
	return (line);
}
