/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:52:45 by hel-ayac          #+#    #+#             */
/*   Updated: 2021/02/28 11:51:34 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rgbcheck(t_cub *cub)
{
	char **rgb;

	rgb = cub->parse.rgb;
	if (cub->parse.spliter[2] || !cub->parse.spliter[1]
		|| countwords(cub->parse.spliter[1], ',') != 3 || isnotnum(rgb[0])
		|| isnotnum(rgb[1]) || isnotnum(rgb[2]) || range_color(rgb))
	{
		ft_print("ERROR\ncolor not valide");
		clean(cub);
		exit(1);
	}
}

int		range_color(char **x)
{
	int	tmp;
	int i;

	i = 0;
	while (i <= 2)
	{
		tmp = ft_atoi(x[i]);
		if (tmp < 0 || tmp > 255)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int		is_space(char c)
{
	return (c == ' ' || c == '\0' || c == '\n' || c == '\t');
}

int		position_check(char c)
{
	return (c == 'N' || c == 'E' || c == 'W' || c == 'S');
}

int		notempty_tex(t_cub *cub)
{
	return ((cub->tex.ea_fd > 0 && cub->tex.no_fd > 0 && cub->tex.s_fd > 0
			&& cub->tex.so_fd > 0 && cub->tex.we_fd > 0));
}
