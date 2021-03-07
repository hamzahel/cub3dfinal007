/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:23:59 by hel-ayac          #+#    #+#             */
/*   Updated: 2021/02/27 15:01:22 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		creatergb(t_rgb *color)
{
	return (color->r << 16 | color->g << 8 | color->b);
}

void	wallrendering(t_cub *cub)
{
	cub->tex_y = (int)cub->texpos;
	cub->texpos += cub->step;
	if (cub->side == 0)
		cub->col = cub->textu[2].data[cub->tex_x + cub->tex_y
			* cub->textu[2].w];
	else if (cub->side == 1)
		cub->col = cub->textu[3].data[cub->tex_x + cub->tex_y
			* cub->textu[3].w];
	else if (cub->side == 2)
		cub->col = cub->textu[0].data[cub->tex_x + cub->tex_y
			* cub->textu[0].w];
	else if (cub->side == 3)
		cub->col = cub->textu[1].data[cub->tex_x + cub->tex_y
			* cub->textu[1].w];
	cub->img.data[cub->img.h * cub->win.w + cub->ray] = cub->col;
	if (cub->argc == 3)
	{
		cub->image[(cub->ray + (cub->drawend - cub->b_pos) * cub->win.w)
			* 3 + 2] = cub->col >> 16;
		cub->image[(cub->ray + (cub->drawend - cub->b_pos) * cub->win.w)
			* 3 + 1] = cub->col >> 8;
		cub->image[(cub->ray + (cub->drawend - cub->b_pos) * cub->win.w)
			* 3 + 0] = cub->col;
		cub->b_pos++;
	}
}
