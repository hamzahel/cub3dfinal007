/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:08:27 by hel-ayac          #+#    #+#             */
/*   Updated: 2021/03/01 10:45:02 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing(t_cub *cub)
{
	cub->file.ret = 1;
	while (cub->file.ret)
	{
		cub->file.ret = get_next_line(cub->file.fd, &cub->file.line);
		if (*cub->file.line == 'R' && !cub->win.rep)
			get_window(cub);
		else if ((*cub->file.line == 'N' || *cub->file.line == 'S' ||
			*cub->file.line == 'W' || *cub->file.line == 'E') && !cub->tex.rep)
			get_textures(cub);
		else if ((*cub->file.line == 'F' || *cub->file.line == 'C')
			&& cub->color.rep != 2)
			get_colors(cub);
		else if ((*cub->file.line == ' ' || *cub->file.line == '1'))
			get_map(cub);
		else if (*cub->file.line)
		{
			ft_print("ERROR!\nparsing error!");
			clean(cub);
			exit(1);
		}
		clean(cub);
	}
	cub->file.eof = 1;
}

void	get_window(t_cub *cub)
{
	cub->parse.spliter = ft_split(cub->file.line, ' ');
	if (countwords(cub->file.line, ' ') != 3 || cub->file.line[1] != ' '
		|| isnotnum(cub->parse.spliter[1]) || isnotnum(cub->parse.spliter[2]))
	{
		ft_print("ERROR\nfile map error!");
		clean(cub);
		exit(1);
	}
	cub->win.w = (ft_atoi(cub->parse.spliter[1]) > 2650) ? 2650 :
		ft_atoi(cub->parse.spliter[1]);
	cub->win.h = (ft_atoi(cub->parse.spliter[2]) > 1440) ? 1440 :
		ft_atoi(cub->parse.spliter[2]);
	cub->win.rep = 1;
	if (cub->argc == 3)
		cub->image = malloc(sizeof(int) * cub->win.w * cub->win.h);
}

void	get_colors(t_cub *cub)
{
	cub->parse.spliter = ft_split(cub->file.line, ' ');
	cub->parse.rgb = ft_split(cub->parse.spliter[1], ',');
	rgbcheck(cub);
	if (*cub->parse.spliter[0] == 'F')
	{
		cub->color.f.r = ft_atoi(cub->parse.rgb[0]);
		cub->color.f.g = ft_atoi(cub->parse.rgb[1]);
		cub->color.f.b = ft_atoi(cub->parse.rgb[2]);
		cub->color.rep++;
	}
	else if (*cub->parse.spliter[0] == 'C')
	{
		cub->color.c.r = ft_atoi(cub->parse.rgb[0]);
		cub->color.c.g = ft_atoi(cub->parse.rgb[1]);
		cub->color.c.b = ft_atoi(cub->parse.rgb[2]);
		cub->color.rep++;
	}
}

void	get_textures(t_cub *cub)
{
	cub->parse.spliter = ft_split(cub->file.line, ' ');
	if (*cub->file.line == 'S' && cub->file.line[1] != 'O')
	{
		insert_textures(cub, &cub->path.s, &cub->tex.s_fd);
		cub->sprite_buffer = (double *)malloc((cub->win.w + 1) * 8);
	}
	else if (*cub->file.line == 'S' && cub->file.line[1] == 'O')
		insert_textures(cub, &cub->path.so, &cub->tex.so_fd);
	else if (*cub->file.line == 'N' && cub->file.line[1] == 'O')
		insert_textures(cub, &cub->path.no, &cub->tex.no_fd);
	else if (*cub->file.line == 'W' && cub->file.line[1] == 'E')
		insert_textures(cub, &cub->path.we, &cub->tex.we_fd);
	else if (*cub->file.line == 'E' && cub->file.line[1] == 'A')
		insert_textures(cub, &cub->path.ea, &cub->tex.ea_fd);
	if (notempty_tex(cub))
		cub->tex.rep = 1;
}
