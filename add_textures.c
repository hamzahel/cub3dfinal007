/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:06:50 by hel-ayac          #+#    #+#             */
/*   Updated: 2021/02/28 11:52:18 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	add_textures(t_cub *cub)
{
	cub->mlx_ptn = mlx_init();
	cub->mlx_win = mlx_new_window(cub->mlx_ptn, cub->win.w, cub->win.h,
			"cub3d");
	cub->textu[0].ptn = mlx_xpm_file_to_image(cub->mlx_ptn, cub->path.no,
			&cub->textu[0].w, &cub->textu[0].h);
	cub->textu[0].data = (int *)mlx_get_data_addr(cub->textu[0].ptn,
			&cub->textu[0].bpp, &cub->textu[0].line, &cub->textu[0].endian);
	cub->textu[1].ptn = mlx_xpm_file_to_image(cub->mlx_ptn, cub->path.we,
			&cub->textu[1].w, &cub->textu[1].h);
	cub->textu[1].data = (int *)mlx_get_data_addr(cub->textu[1].ptn,
			&cub->textu[1].bpp, &cub->textu[1].line, &cub->textu[1].endian);
	cub->textu[2].ptn = mlx_xpm_file_to_image(cub->mlx_ptn, cub->path.so,
			&cub->textu[2].w, &cub->textu[2].h);
	cub->textu[2].data = (int *)mlx_get_data_addr(cub->textu[2].ptn,
			&cub->textu[2].bpp, &cub->textu[2].line, &cub->textu[0].endian);
	cub->textu[3].ptn = mlx_xpm_file_to_image(cub->mlx_ptn, cub->path.ea,
			&cub->textu[3].w, &cub->textu[3].h);
	cub->textu[3].data = (int *)mlx_get_data_addr(cub->textu[3].ptn,
			&cub->textu[3].bpp, &cub->textu[3].line, &cub->textu[3].endian);
	cub->textu[4].ptn = mlx_xpm_file_to_image(cub->mlx_ptn, cub->path.s,
			&cub->textu[4].w, &cub->textu[4].h);
	cub->textu[4].data = (int *)mlx_get_data_addr(cub->textu[4].ptn,
			&cub->textu[4].bpp, &cub->textu[4].line, &cub->textu[4].endian);
}
