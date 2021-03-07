/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 11:45:13 by hel-ayac          #+#    #+#             */
/*   Updated: 2021/03/01 10:45:32 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean(t_cub *cub)
{
	spliter_clean(cub);
	rgb_clean(cub);
	map_clean(cub);
	if (cub->file.line)
	{
		free(cub->file.line);
		cub->file.line = NULL;
	}
}

void	spliter_clean(t_cub *cub)
{
	int	i;

	i = 0;
	if (cub->parse.spliter && !cub->map.line)
	{
		while (cub->parse.spliter[i])
		{
			free(cub->parse.spliter[i]);
			cub->parse.spliter[i] = NULL;
			i++;
		}
		free(cub->parse.spliter);
		cub->parse.spliter = NULL;
	}
}

void	rgb_clean(t_cub *cub)
{
	int	i;

	i = 0;
	if (cub->parse.rgb != NULL)
	{
		while (cub->parse.rgb[i])
		{
			free(cub->parse.rgb[i]);
			cub->parse.rgb[i] = NULL;
			i++;
		}
		free(cub->parse.rgb);
		cub->parse.rgb = NULL;
	}
}

void	map_clean(t_cub *cub)
{
	int	i;

	i = 0;
	if (cub->map.line && cub->file.eof)
	{
		free(cub->map.line);
		cub->map.line = NULL;
	}
	if (cub->map.tab)
	{
		while (cub->map.tab[i] && i < cub->map.index)
		{
			free(cub->map.tab[i]);
			cub->map.tab[i] = NULL;
			i++;
		}
		free(cub->map.tab);
		cub->map.tab = NULL;
	}
}
