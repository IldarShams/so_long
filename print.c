/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaegan <smaegan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:36:07 by smaegan           #+#    #+#             */
/*   Updated: 2022/03/12 19:36:20 by smaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_PM *pm, t_xyij xyij)
{
	if (pm->map[xyij.y][xyij.x] == '1')
		mlx_put_image_to_window(pm->mlx, pm->w, pm->img[0],
			xyij.i * 64 - 96, xyij.j * 64 + 1);
	else if (pm->map[xyij.y][xyij.x] == '0')
		mlx_put_image_to_window(pm->mlx, pm->w, pm->img[1],
			xyij.i * 64 - 96, xyij.j * 64 + 1);
	else if (pm->map[xyij.y][xyij.x] == 'C')
		mlx_put_image_to_window(pm->mlx, pm->w, pm->img[3],
			xyij.i * 64 - 96, xyij.j * 64 + 1);
	else if (pm->map[xyij.y][xyij.x] == 'E')
		mlx_put_image_to_window(pm->mlx, pm->w, pm->img[4],
			xyij.i * 64 - 96, xyij.j * 64 + 1);
}

void	center_scrin_print(t_PM *pm)
{
	t_xyij	xyij;

	xyij.x = pm->x - 11;
	xyij.i = 0;
	mlx_put_image_to_window(pm->mlx, pm->w, pm->img[5], 0, 0);
	while (xyij.i < 27)
	{
		xyij.j = 0;
		xyij.y = pm->y - 5;
		while (xyij.j < 11)
		{
			if (xyij.x >= 0 && xyij.x < pm->width
				&& xyij.y >= 0 && xyij.y < pm->height)
				put_img(pm, xyij);
			xyij.j++;
			xyij.y++;
		}
		xyij.i++;
		xyij.x++;
	}
	mlx_put_image_to_window(pm->mlx, pm->w, pm->img[2], 608, 318);
}
