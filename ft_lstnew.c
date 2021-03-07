/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 23:58:57 by hel-ayac          #+#    #+#             */
/*   Updated: 2021/02/23 12:27:40 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprite	*ft_lstnew(int mapx, int mapy, int fd)
{
	t_sprite	*next;

	next = (t_sprite*)malloc(sizeof(t_sprite));
	if (next == NULL)
		return (NULL);
	next->mapx = mapx;
	next->mapy = mapy;
	next->fd = fd;
	next->next = NULL;
	return (next);
}
