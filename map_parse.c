/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 16:31:08 by hel-ayac          #+#    #+#             */
/*   Updated: 2021/02/27 15:03:50 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_map(t_cub *cub, int x, int y, int max)
{
	char **map;

	map = cub->map.tab;
	if ((!validechar(map[x][y])) || ((map[x][y] == '0' || map[x][y]
				== '2' || position_check(map[x][y])) && (x == 0
				|| y == 0 || max == x + 1 || is_space(map[x][y - 1])
				|| is_space(map[x][y + 1]) || is_space(map[x - 1][y])
				|| is_space(map[x + 1][y]))))
	{
		ft_print("ERROR !\nmap not valide");
		clean(cub);
		exit(0);
	}
}

int		validechar(char c)
{
	return (c == '0' || c == '1' || c == '2' || c == 'S' || c == 'N'
		|| c == 'E' || c == 'W' || c == '\t' || c == ' ');
}

void	error_player(t_cub *cub)
{
	if (!cub->map.rep || cub->map.rep > 1)
	{
		ft_print("ERROR!\nplayer position not found");
		clean(cub);
		exit(0);
	}
}

void	map_checker(t_cub *cub)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	cub->map.tab = ft_split(cub->map.line, '\n');
	while (cub->map.tab[x] && cub->map.index > x)
	{
		while (cub->map.tab[x][y])
		{
			error_map(cub, x, y, cub->map.index);
			if (position_check(cub->map.tab[x][y]))
			{
				player_pos(cub->map.tab[x][y], x, y, cub);
				cub->map.rep++;
			}
			if (cub->map.tab[x][y] == '2')
				createsprite(x, y, cub);
			y++;
		}
		y = 0;
		x++;
	}
	error_player(cub);
}

void	get_map(t_cub *cub)
{
	char	*tmp;

	if (!cub->win.rep || !cub->tex.rep || cub->color.rep != 2)
	{
		ft_print("ERROR\nfile not valide!");
		clean(cub);
		exit(1);
	}
	tmp = cub->map.line;
	cub->map.line = (!tmp) ? ft_strdup(cub->file.line) :
		ft_strjoin(tmp, cub->file.line);
	free(tmp);
	tmp = cub->map.line;
	cub->map.line = ft_strjoin(tmp, "\n");
	free(tmp);
	cub->map.index++;
}
