/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:38:28 by hel-ayac          #+#    #+#             */
/*   Updated: 2021/02/28 19:36:08 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc(t_cub *cub)
{
	cub->hit = 0;
	cub->img.h = 0;
	cub->b_pos = 0;
	cub->camerax = 2 * cub->ray / (double)cub->win.w - 1;
	cub->raydirx = cub->dirx + cub->planex * cub->camerax;
	cub->raydiry = cub->diry + cub->planey * cub->camerax;
	cub->mapx = (int)cub->posx;
	cub->mapy = (int)cub->posy;
	cub->deltadistx = sqrt(1 + pow(cub->raydiry, 2) / pow(cub->raydirx, 2));
	cub->deltadisty = sqrt(1 + pow(cub->raydirx, 2) / pow(cub->raydiry, 2));
	if (cub->raydiry == 0)
		cub->deltadistx = 0;
	else if (cub->raydirx == 0)
		cub->deltadistx = 1;
	if (cub->raydirx == 0)
		cub->deltadisty = 0;
	else if (cub->raydiry == 0)
		cub->deltadisty = 1;
}

void	sidedist(t_cub *cub)
{
	if (cub->raydirx < 0)
	{
		cub->stepx = -1;
		cub->sidedistx = (cub->posx - cub->mapx) * cub->deltadistx;
	}
	else
	{
		cub->stepx = 1;
		cub->sidedistx = (cub->mapx + 1.0 - cub->posx) * cub->deltadistx;
	}
	if (cub->raydiry < 0)
	{
		cub->stepy = -1;
		cub->sidedisty = (cub->posy - cub->mapy) * cub->deltadisty;
	}
	else
	{
		cub->stepy = 1;
		cub->sidedisty = (cub->mapy + 1.0 - cub->posy) * cub->deltadisty;
	}
}

void	hit(t_cub *cub)
{
	while (cub->hit == 0)
	{
		if (cub->sidedistx < cub->sidedisty)
		{
			cub->sidedistx += cub->deltadistx;
			cub->mapx += cub->stepx;
			cub->side = 0;
		}
		else
		{
			cub->sidedisty += cub->deltadisty;
			cub->mapy += cub->stepy;
			cub->side = 3;
		}
		if (cub->side == 0 && cub->raydirx > 0)
			cub->side = 2;
		else if (cub->side == 3 && cub->raydiry < 0)
			cub->side = 1;
		if (cub->map.tab[cub->mapx][cub->mapy] == '1')
			cub->hit = 1;
	}
}

void	wall(t_cub *cub)
{
	if (cub->side == 0 || cub->side == 2)
		cub->perpdistwall = (cub->mapx - cub->posx
		+ (1 - cub->stepx) / 2) / cub->raydirx;
	else
		cub->perpdistwall = (cub->mapy - cub->posy
		+ (1 - cub->stepy) / 2) / cub->raydiry;
	cub->lineheight = (int)(cub->win.h / cub->perpdistwall);
	cub->drawstart = (-cub->lineheight / 2) + (cub->win.h / 2);
	if (cub->drawstart < 0)
		cub->drawstart = 0;
	cub->drawend = cub->lineheight / 2 + (cub->win.h / 2);
	if (cub->drawend >= cub->win.h)
		cub->drawend = cub->win.h - 1;
	if (cub->side == 0 || cub->side == 2)
		cub->wallx = cub->posy + cub->perpdistwall * cub->raydiry;
	else
		cub->wallx = cub->posx + cub->perpdistwall * cub->raydirx;
	cub->wallx -= floor((cub->wallx));
	cub->tex_x = (int)(cub->wallx * (double)(cub->texwidth));
	if (cub->side == 0 && cub->raydirx > 0)
		cub->tex_x = cub->texwidth - cub->tex_x - 1;
	if (cub->side == 1 && cub->raydiry < 0)
		cub->tex_x = cub->texwidth - cub->tex_x - 1;
	cub->step = 1.0 * cub->texheight / cub->lineheight;
}

void	rendering(t_cub *cub)
{
	cub->texpos = (cub->drawstart - cub->win.h / 2
	+ cub->lineheight / 2) * cub->step;
	while (cub->img.h < cub->win.h)
	{
		if (cub->img.h < cub->drawstart)
		{
			cub->img.data[cub->img.h * cub->win.w + cub->ray] =
			creatergb(&cub->color.c);
			bmp_filling(cub, &cub->color.f);
		}
		if (cub->img.h >= cub->drawstart && cub->img.h <= cub->drawend)
			wallrendering(cub);
		if (cub->img.h > cub->drawend)
		{
			cub->img.data[cub->img.h * cub->win.w + cub->ray] =
			creatergb(&cub->color.f);
			bmp_filling(cub, &cub->color.c);
		}
		cub->img.h++;
	}
	if (cub->spritecount)
		cub->sprite_buffer[cub->ray] = cub->perpdistwall;
	cub->ray++;
}
