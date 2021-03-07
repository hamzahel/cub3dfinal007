/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:09:19 by hel-ayac          #+#    #+#             */
/*   Updated: 2021/03/01 10:43:36 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bmp(t_cub *cub)
{
	if (cub->argc == 3)
	{
		if (!ft_strncmp(cub->save, "--save", ft_strlen("--save")))
			bmp_save(cub);
		else
		{
			ft_print("ERROR\nsave error!");
			clean(cub);
			exit(1);
		}
		exit(0);
	}
}
