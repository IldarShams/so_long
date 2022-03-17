/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaegan <smaegan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:17:02 by smaegan           #+#    #+#             */
/*   Updated: 2022/03/17 19:36:32 by smaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_handler(int keycode, void *param)
{
	t_PM	*pm;

	pm = (t_PM *)param;
	if (keycode == 0)
		go_left(pm);
	else if (keycode == 2)
		go_right(pm);
	else if (keycode == 1)
		go_down(pm);
	else if (keycode == 13)
		go_up(pm);
	else if (keycode == 53)
		exit_handler(pm);
	center_scrin_print(pm);
	ft_putnbr_fd(pm->steps, 1);
	write(1, "\n", 1);
	return (1);
}

int	exit_handler(void *param)
{
	int		i;
	t_PM	*pm;

	i = 0;
	pm = (t_PM *)param;
	free_map(pm->map);
	mlx_destroy_window(pm->mlx, pm->w);
	while (i < 6)
	{
		mlx_destroy_image(pm->mlx, pm->img[i]);
		i++;
	}
	free(pm->img);
	exit(0);
}
