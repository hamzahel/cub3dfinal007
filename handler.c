/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:32:23 by hel-ayac          #+#    #+#             */
/*   Updated: 2021/02/27 14:57:31 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print(char *error)
{
	if (error)
	{
		ft_putstr_fd(error, 1);
	}
}

void	check_param(t_cub *cub, int *fd, char *ex, int t)
{
	int	size;
	int	exlen;
	int	check;

	exlen = ft_strlen(ex);
	size = ft_strlen(cub->argv[1]) - exlen;
	check = ft_strncmp(&cub->argv[1][size], ex, exlen + 1);
	*fd = open(cub->argv[1], O_RDONLY);
	if (check != 0 || *(fd) < 0)
	{
		ft_print("ERROR!\nfile not found\n");
		if (t)
		{
			clean(cub);
		}
		exit(1);
	}
}

void	initvalues(t_cub *cub)
{
	cub->parse_sort = 0;
	cub->win.w = 0;
	cub->win.h = 0;
	cub->win.rep = 0;
	cub->file.eof = 0;
	cub->path.rep = 0;
	cub->tex.ea_fd = 0;
	cub->tex.no_fd = 0;
	cub->tex.s_fd = 0;
	cub->tex.so_fd = 0;
	cub->tex.we_fd = 0;
	cub->tex.rep = 0;
	cub->color.f.r = 0;
	cub->color.f.g = 0;
	cub->color.f.b = 0;
	cub->color.c.r = 0;
	cub->color.c.g = 0;
	cub->color.c.b = 0;
	cub->map.rep = 0;
	cub->map.index = 0;
	cub->map.tab = NULL;
	cub->map.line = NULL;
	cub->image = NULL;
}

void	insert_textures(t_cub *cub, char **path, int *fd)
{
	if (cub->parse.spliter[2] || !cub->parse.spliter[1])
	{
		ft_print("ERROR\nfile not valide!");
		clean(cub);
		exit(1);
	}
	cub->argv = cub->parse.spliter;
	check_param(cub, fd, ".xpm", 1);
	*path = ft_strdup(cub->parse.spliter[1]);
}
