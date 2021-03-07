/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:20:54 by hel-ayac          #+#    #+#             */
/*   Updated: 2021/02/28 16:21:05 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calcsprite(t_cub *cub)
{
	t_sprite	*next;

	next = cub->sprite;
	while (next)
	{
		next->spdistane = (pow((cub->posx - next->mapx), 2)
				+ pow((cub->posy - next->mapy), 2));
		next = next->next;
	}
	sortsprite(cub->sprite, cub->spritecount);
}

void	sprite_helper(t_cub *cub, t_sprite *next)
{
	cub->spritex = next->mapx - cub->posx + 0.5;
	cub->spritey = next->mapy - cub->posy + 0.5;
	cub->invdet = 1.0 / (cub->planex * cub->diry - cub->dirx * cub->planey);
	cub->transx = cub->invdet * (cub->diry * cub->spritex -
	cub->dirx * cub->spritey);
}

void	sprite(t_cub *cub)
{
	t_sprite	*next;

	calcsprite(cub);
	next = cub->sprite;
	while (next)
	{
		sprite_helper(cub, next);
		cub->transy = cub->invdet * (-cub->planey * cub->spritex
				+ cub->planex * cub->spritey);
		cub->spritescx = (int)((cub->win.w / 2) * (1 + cub->transx /
				cub->transy));
		cub->spriteheight = abs((int)(cub->win.h / cub->transy));
		cub->drawstarty = -cub->spriteheight / 2 + cub->win.h / 2;
		if (cub->drawstarty < 0)
			cub->drawstarty = 0;
		cub->drawendy = cub->spriteheight / 2 + cub->win.h / 2;
		if (cub->drawendy >= cub->win.h)
			cub->drawendy = cub->win.h - 1;
		cub->spritewidth = abs((int)(cub->win.h / (cub->transy)));
		spriterendering(cub);
		next = next->next;
	}
}

void	spriterendering(t_cub *cub)
{
	cub->drawstartx = -cub->spritewidth / 2 + cub->spritescx;
	if (cub->drawstartx < 0)
		cub->drawstartx = 0;
	cub->drawendx = cub->spritewidth / 2 + cub->spritescx;
	if (cub->drawendx >= cub->win.w)
		cub->drawendx = cub->win.w - 1;
	while (cub->drawstartx < cub->drawendx)
	{
		cub->b_pos = 0;
		cub->tex_x = (int)(256 * (cub->drawstartx - (-cub->spritewidth / 2
			+ cub->spritescx)) * cub->texwidth / cub->spritewidth) / 256;
		if (cub->transy > 0 && cub->drawstartx > 0 && cub->drawstartx
			< cub->win.w && cub->transy < cub->sprite_buffer[cub->drawstartx])
		{
			cub->spriteline = cub->drawstarty;
			while (cub->spriteline < cub->drawendy)
			{
				spriteimage(cub);
				cub->spriteline++;
			}
		}
		cub->drawstartx++;
	}
}

void	spriteimage(t_cub *cub)
{
	cub->data = (cub->spriteline) * 256 - cub->win.h * 128 +
		cub->spriteheight * 128;
	cub->tex_y = ((cub->data * cub->texheight) / cub->spriteheight) / 256;
	if (cub->textu[4].data[cub->tex_x + cub->tex_y * cub->textu[4].w])
	{
		cub->img.data[cub->spriteline * cub->win.w + cub->drawstartx] =
		cub->textu[4].data[cub->tex_x + cub->tex_y * cub->textu[4].w];
		if (cub->argc == 3)
		{
			cub->filesize = ((cub->drawendy - cub->b_pos) * cub->win.w +
				cub->drawstartx);
			cub->image[cub->filesize * 3 + 2] = cub->textu[4].data[cub->tex_x
				+ cub->tex_y * cub->textu[4].w] >> 16;
			cub->image[cub->filesize * 3 + 1] = cub->textu[4].data[cub->tex_x
				+ cub->tex_y * cub->textu[4].w] >> 8;
			cub->image[cub->filesize * 3 + 0] = cub->textu[4].data[cub->tex_x
				+ cub->tex_y * cub->textu[4].w];
		}
	}
	cub->b_pos++;
}
