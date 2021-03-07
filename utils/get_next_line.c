/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 19:20:18 by hel-ayac          #+#    #+#             */
/*   Updated: 2021/02/27 15:07:47 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		return (ft_strdup(""));
	}
	tmp = (char *)malloc((sizeof(char) * len) + 1);
	if (tmp == NULL)
		return (NULL);
	ft_strlcpy(tmp, s + start, len + 1);
	return (tmp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;
	size_t	len1;
	size_t	len2;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	buffer = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!buffer)
		return (NULL);
	ft_strlcpy(buffer, s1, len1 + 1);
	ft_strlcat(buffer, s2, len2 + len1 + 1);
	return (buffer);
}

int		free_func(char **s, int ret)
{
	free(*s);
	*s = NULL;
	return (ret);
}

char	*store(char **save)
{
	char	*tmp;
	char	*tmp2;
	char	*line;

	if (!(tmp2 = ft_strchr(*save, '\n')))
		return (NULL);
	tmp = *save;
	*save = ft_strdup(tmp2 + 1);
	if ((line = ft_substr(tmp, 0, ft_strlen(tmp) - ft_strlen(*save) - 1)))
	{
		free(tmp);
		return (line);
	}
	free(tmp);
	return (NULL);
}

int		get_next_line(int fd, char **line)
{
	char		*buffer;
	char		*tmp;
	static char	*save[4864];
	int			size;

	if (fd > 4864 || fd < 0 || !(buffer = malloc(BUFFER_SIZE + 1)) || !line)
		return (-1);
	if ((*line = store(&save[fd])) != NULL)
		return (free_func(&buffer, 1));
	while ((size = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[size] = '\0';
		tmp = save[fd];
		save[fd] = (tmp) ? ft_strjoin(tmp, buffer) : ft_strdup(buffer);
		free_func(&tmp, 0);
		if ((*line = store(&save[fd])))
			return (free_func(&buffer, 1));
	}
	if (size == 0 && !ft_strchr(save[fd], '\n'))
	{
		*line = (save[fd]) ? ft_strdup(save[fd]) : ft_strdup("");
		free_func(&buffer, 0);
		return (free_func(&save[fd], 0));
	}
	return (free_func(&buffer, size));
}
