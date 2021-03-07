/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 18:31:59 by hel-ayac          #+#    #+#             */
/*   Updated: 2021/02/27 14:32:09 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	look(t_cub *cub)
{
	cub->olddirx = cub->dirx;
	if (cub->keyboard[123])
	{
		cub->dirx = cub->dirx * cos(cub->rotspeed) - cub->diry
			* sin(cub->rotspeed);
		cub->diry = cub->olddirx * sin(cub->rotspeed) + cub->diry
			* cos(cub->rotspeed);
		cub->oldplanex = cub->planex;
		cub->planex = cub->planex * cos(cub->rotspeed) - cub->planey
			* sin(cub->rotspeed);
		cub->planey = cub->oldplanex * sin(cub->rotspeed) + cub->planey
			* cos(cub->rotspeed);
	}
	if (cub->keyboard[124])
	{
		cub->dirx = cub->dirx * cos(-cub->rotspeed) - cub->diry
			* sin(-cub->rotspeed);
		cub->diry = cub->olddirx * sin(-cub->rotspeed) + cub->diry
			* cos(-cub->rotspeed);
		cub->oldplanex = cub->planex;
		cub->planex = cub->planex * cos(-cub->rotspeed) - cub->planey
			* sin(-cub->rotspeed);
		cub->planey = cub->oldplanex * sin(-cub->rotspeed) + cub->planey
			* cos(-cub->rotspeed);
	}
}

int		keyclose(t_cub *cub)
{
	mlx_clear_window(cub->mlx_ptn, cub->mlx_win);
	ft_putstr_fd("GAME OVER!\n", 2);
	exit(0);
	return (0);
}
