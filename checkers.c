/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 14:34:05 by hel-ayac          #+#    #+#             */
/*   Updated: 2021/02/27 14:34:12 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		countwords(char const *str, char c)
{
	int	len;

	len = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str == 0)
			break ;
		while (*str && *str != c)
			str++;
		len++;
	}
	return (len);
}

int		isnotnum(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			return (1);
		}
		str++;
	}
	return (0);
}

void	init_player_pos(t_cub *cub, double dir, double pln)
{
	cub->dirx = dir;
	if (dir == 1 || dir == -1)
		cub->diry = 0;
	else
		cub->diry = pln / fabs(pln);
	cub->planex = pln;
	if (dir == 0)
		cub->planey = 0;
	else
		cub->planey = dir * PLANE * -1;
}

void	player_pos(char pos, int y, int x, t_cub *cub)
{
	cub->posy = (double)x + 0.5;
	cub->posx = (double)y + 0.5;
	cub->map.tab[y][x] = '0';
	if (pos == 'N')
	{
		init_player_pos(cub, DIR, 0);
	}
	else if (pos == 'S')
	{
		init_player_pos(cub, -DIR, 0);
	}
	else if (pos == 'E')
	{
		init_player_pos(cub, 0, PLANE);
	}
	else if (pos == 'W')
	{
		init_player_pos(cub, 0, -PLANE);
	}
}
