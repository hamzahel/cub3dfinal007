/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsradd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 14:39:38 by hel-ayac          #+#    #+#             */
/*   Updated: 2021/02/23 12:27:05 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_lstadd_front(t_sprite **alst, t_sprite *new, t_cub *cub)
{
	if (new)
	{
		new->next = *alst;
		cub->spritecount++;
		*alst = new;
	}
}
