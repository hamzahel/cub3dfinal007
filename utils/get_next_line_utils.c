/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:55:10 by hel-ayac          #+#    #+#             */
/*   Updated: 2021/02/23 17:07:57 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	tmp = (char *)malloc(ft_strlen((char *)s1) * sizeof(char) + 1);
	if (tmp == NULL || s1 == NULL)
		return (NULL);
	while (s1[i])
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lensrc;

	if (src == NULL || dst == NULL)
		return (0);
	lensrc = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (lensrc);
	while (size - 1 > i && lensrc > 0)
	{
		dst[i] = src[i];
		i++;
		lensrc--;
	}
	if (i < size)
		dst[i] = '\0';
	return (lensrc + i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (!dst && !size)
		return (ft_strlen(src));
	i = ft_strlen(dst);
	if (size < i)
		i = size;
	j = 0;
	while ((int)(j) < (int)(size - i - 1) && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i + j < size)
		dst[i + j] = 0;
	return (i + ft_strlen((char *)src));
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if ((char)c == str[i])
		return ((char *)&str[i]);
	return (NULL);
}
