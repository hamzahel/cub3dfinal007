/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_cont.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 16:59:47 by hel-ayac          #+#    #+#             */
/*   Updated: 2021/02/27 15:00:32 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		keypressed(int key, t_cub *cub)
{
	cub->keyboard[key] = 1;
	return (0);
}

int		keyreleased(int key, t_cub *cub)
{
	cub->keyboard[key] = 0;
	return (0);
}

void	movesupdown(t_cub *cub)
{
	if (cub->keyboard[13])
	{
		if (cub->map.tab[(int)(cub->posx + cub->dirx * cub->movespeed)]
			[(int)(cub->posy)] == '0')
			cub->posx += cub->dirx * cub->movespeed;
		if (cub->map.tab[(int)(cub->posx)][(int)(cub->posy + cub->diry *
				cub->movespeed)] == '0')
			cub->posy += cub->diry * cub->movespeed;
	}
	if (cub->keyboard[1])
	{
		if (cub->map.tab[(int)(cub->posx - cub->dirx * cub->movespeed)]
			[(int)(cub->posy)] == '0')
			cub->posx -= cub->dirx * cub->movespeed;
		if (cub->map.tab[(int)(cub->posx)][(int)(cub->posy - cub->diry *
			cub->movespeed)] == '0')
			cub->posy -= cub->diry * cub->movespeed;
	}
}

void	movesides(t_cub *cub)
{
	if (cub->keyboard[0])
	{
		if (cub->map.tab[(int)(cub->posx - cub->planex * cub->movespeed)]
			[(int)(cub->posy)] == '0')
			cub->posx -= cub->planex * cub->movespeed;
		if (cub->map.tab[(int)(cub->posx)]
			[(int)(cub->posy - cub->planey * cub->movespeed)] == '0')
			cub->posy -= cub->planey * cub->movespeed;
	}
	if (cub->keyboard[2])
	{
		if (cub->map.tab[(int)(cub->posx + cub->planex * cub->movespeed)]
			[(int)(cub->posy)] == '0')
			cub->posx += cub->planex * cub->movespeed;
		if (cub->map.tab[(int)(cub->posx)]
			[(int)(cub->posy + cub->planey * cub->movespeed)]
			== '0')
			cub->posy += cub->planey * cub->movespeed;
	}
}

int		dealkey(t_cub *cub)
{
	mlx_destroy_image(cub->mlx_ptn, cub->img.ptn);
	mlx_clear_window(cub->mlx_ptn, cub->mlx_win);
	movesupdown(cub);
	movesides(cub);
	look(cub);
	if (cub->keyboard[53])
		keyclose(cub);
	drawing(cub);
	return (0);
}
