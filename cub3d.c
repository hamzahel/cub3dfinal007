/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:59:03 by hel-ayac          #+#    #+#             */
/*   Updated: 2021/03/01 10:44:08 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub	cub;

	if (argc >= 2 && argc <= 3)
	{
		cub.argc = argc;
		cub.argv = argv;
		cub.save = (argv[2] ? argv[2] : NULL);
		check_param(&cub, &cub.file.fd, ".cub", 0);
		initvalues(&cub);
		parsing(&cub);
		map_checker(&cub);
		add_textures(&cub);
		drawing(&cub);
		bmp(&cub);
		mlx_hook(cub.mlx_win, 2, 0, keypressed, &cub);
		mlx_hook(cub.mlx_win, 3, 0, keyreleased, &cub);
		mlx_hook(cub.mlx_win, 17, 0, keyclose, &cub);
		mlx_loop_hook(cub.mlx_ptn, dealkey, &cub);
		mlx_loop(cub.mlx_ptn);
	}
	else
		ft_print("Error invalid entries!");
	return (0);
}
