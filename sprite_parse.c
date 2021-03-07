/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:38:22 by hel-ayac          #+#    #+#             */
/*   Updated: 2021/02/27 15:02:34 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	createsprite(int x, int y, t_cub *cub)
{
	t_sprite	*snew;

	snew = ft_lstnew(x, y, cub->tex.s_fd);
	ft_lstadd_front(&cub->sprite, snew, cub);
}

void	spriteswap(t_sprite *head, t_sprite *next)
{
	int		tmp;
	double	disttmp;

	tmp = next->mapx;
	next->mapx = head->mapx;
	head->mapx = tmp;
	tmp = next->mapy;
	next->mapy = head->mapy;
	head->mapy = tmp;
	disttmp = next->spdistane;
	next->spdistane = head->spdistane;
	head->spdistane = disttmp;
}

void	sortsprite(t_sprite *first, int count)
{
	t_sprite	*next;
	t_sprite	*sprite;
	t_sprite	*res;
	int			iswap;

	sprite = first;
	iswap = 1;
	while (iswap)
	{
		iswap = 0;
		while (sprite && sprite->next)
		{
			next = sprite->next;
			if (sprite->spdistane < next->spdistane)
			{
				spriteswap(sprite, next);
				iswap = 1;
			}
			sprite = next;
		}
		sprite = first;
	}
}
