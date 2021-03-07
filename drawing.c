/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 11:12:52 by hel-ayac          #+#    #+#             */
/*   Updated: 2021/03/01 12:55:26 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	drawing(t_cub *cub)
{
	cub->img.ptn = mlx_new_image(cub->mlx_ptn, cub->win.w, cub->win.h);
	cub->img.data = (int *)mlx_get_data_addr(cub->img.ptn, &cub->img.bpp,
			&cub->img.line, &cub->img.endian);
	cub->ray = 0;
	cub->texwidth = 64;
	cub->texheight = 64;
	cub->rotspeed = 0.05;
	cub->movespeed = 0.15;
	cub->b_pos = 0;
	while (cub->ray < cub->win.w)
	{
		calc(cub);
		sidedist(cub);
		hit(cub);
		wall(cub);
		rendering(cub);
	}
	if (cub->spritecount)
		sprite(cub);
	mlx_put_image_to_window(cub->mlx_ptn, cub->mlx_win, cub->img.ptn, 0, 0);
}
