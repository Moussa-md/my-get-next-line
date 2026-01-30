#include "get_next_line.h"

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

char	*read_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = ft_substr(buffer, 0, i);
	return (line);
}

char	*read_until_newline(char **buffer, int fd)
{
	ssize_t	counter;
	char	*buffer_to_free;
	char	*tmp;

	counter = 1;
	while (ft_strchr(*buffer) == -1 && counter != 0)
	{
		tmp = malloc(BUFFER_SIZE + 1);
		counter = read(fd, tmp, BUFFER_SIZE);
		if (counter == -1)
			return (free(tmp), NULL);
		tmp[counter] = '\0';
		buffer_to_free = *buffer;
		*buffer = ft_strjoin(buffer_to_free, tmp);
		free(buffer_to_free);
		free(tmp);
	}
	return (*buffer);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*line;
	char			*buffer_to_free;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	read_until_newline(&buffer, fd);
	if (!buffer[0])
		return (free(buffer), buffer = 0, NULL);
	line = read_line(buffer);
	buffer_to_free = ft_substr(buffer, ft_strlen(line), ft_strlen(buffer)
			- ft_strlen(line));
	free(buffer);
	buffer = buffer_to_free;
	return (line);
}
