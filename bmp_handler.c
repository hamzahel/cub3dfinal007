/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 11:33:11 by hel-ayac          #+#    #+#             */
/*   Updated: 2021/02/27 14:36:44 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			bmp_filling(t_cub *cub, t_rgb *fc)
{
	cub->filesize = cub->ray + cub->img.h * cub->win.w;
	if (cub->argc == 3)
	{
		cub->image[(cub->filesize) * 3 + 2] = (char)fc->r;
		cub->image[(cub->filesize) * 3 + 1] = (char)fc->g;
		cub->image[(cub->filesize) * 3 + 0] = (char)fc->b;
	}
}

unsigned char	*bmp_header(int size)
{
	unsigned char	*bmpfileheader;

	bmpfileheader = (unsigned char *)malloc(14);
	ft_memset(bmpfileheader, 0, 14);
	bmpfileheader[0] = (unsigned char)('B');
	bmpfileheader[1] = (unsigned char)('M');
	bmpfileheader[2] = (unsigned char)(size);
	bmpfileheader[3] = (unsigned char)(size >> 8);
	bmpfileheader[4] = (unsigned char)(size >> 16);
	bmpfileheader[10] = (unsigned char)(54);
	return (bmpfileheader);
}

unsigned char	*bmp_info(t_cub *cub)
{
	unsigned char	*bmpinfoheader;

	bmpinfoheader = (unsigned char *)malloc(40);
	ft_memset(bmpinfoheader, 0, 40);
	bmpinfoheader[0] = (unsigned char)(40);
	bmpinfoheader[4] = (unsigned char)(cub->win.w);
	bmpinfoheader[5] = (unsigned char)(cub->win.w >> 8);
	bmpinfoheader[6] = (unsigned char)(cub->win.w >> 16);
	bmpinfoheader[7] = (unsigned char)(cub->win.w >> 24);
	bmpinfoheader[8] = (unsigned char)(cub->win.h);
	bmpinfoheader[9] = (unsigned char)(cub->win.h >> 8);
	bmpinfoheader[10] = (unsigned char)(cub->win.h >> 16);
	bmpinfoheader[11] = (unsigned char)(cub->win.h >> 24);
	bmpinfoheader[12] = (unsigned char)(1);
	bmpinfoheader[14] = (unsigned char)(24);
	cub->bmp.y = -1;
	return (bmpinfoheader);
}

void			bmp_looping(t_cub *cub, int fd, unsigned char *bmppad)
{
	int	abrv;

	while (++cub->bmp.y < cub->win.h)
	{
		abrv = cub->bmp.y * cub->win.w * 3;
		write(fd, cub->image + abrv, cub->win.w * 3);
		write(fd, bmppad, cub->bmp.padding);
	}
}

void			bmp_save(t_cub *cub)
{
	unsigned char	*bmpfileheader;
	unsigned char	*bmpinfoheader;
	unsigned char	*bmppad;
	int				fd;

	cub->bmp.padding = (4 - (cub->win.w * 3) % 4) % 4;
	cub->bmp.filesize = 54 + cub->win.w * cub->win.h * 3;
	bmpfileheader = (unsigned char *)malloc(14);
	bmpinfoheader = (unsigned char *)malloc(40);
	bmppad = (unsigned char *)malloc(3);
	ft_memset(bmppad, 0, 3);
	bmpfileheader = bmp_header(cub->bmp.filesize);
	bmpinfoheader = bmp_info(cub);
	fd = open("save.bmp", O_WRONLY | O_CREAT, 0666);
	write(fd, bmpfileheader, 14);
	write(fd, bmpinfoheader, 40);
	bmp_looping(cub, fd, bmppad);
	close(fd);
	ft_putstr_fd("Screenshot saved!\n", 2);
	exit(0);
}
