/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaegan <smaegan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:18:19 by smaegan           #+#    #+#             */
/*   Updated: 2022/03/12 19:40:25 by smaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	go_left(t_PM *pm)
{
	if (0 < pm->x - 1 && pm->x - 1 < pm->width
		&& (pm->map[pm->y][pm->x - 1] != '1'
		&& !(pm->map[pm->y][pm->x -1] == 'E' && pm->collectables != 0)))
	{
		if (pm->map[pm->y][pm->x - 1] == 'C')
			pm->collectables--;
		if (pm->map[pm->y][pm->x - 1] == 'E' && pm->collectables == 0)
			exit_handler(pm);
		pm->map[pm->y][pm->x] = '0';
		pm->steps++;
		pm->x = pm->x - 1;
	}
}

void	go_right(t_PM *pm)
{
	if (0 < pm->x + 1 && pm->x + 1 < pm->width
		&& (pm->map[pm->y][pm->x + 1] != '1'
		&& !(pm->map[pm->y][pm->x + 1] == 'E' && pm->collectables != 0)))
	{
		if (pm->map[pm->y][pm->x + 1] == 'C')
			pm->collectables--;
		if (pm->map[pm->y][pm->x + 1] == 'E' && pm->collectables == 0)
			exit_handler(pm);
		pm->map[pm->y][pm->x] = '0';
		pm->x = pm->x + 1;
		pm->steps++;
	}
}

void	go_down(t_PM *pm)
{
	if (0 < pm->y + 1 && pm->y + 1 < pm->height
		&& (pm->map[pm->y + 1][pm->x] != '1'
		&& !(pm->map[pm->y + 1][pm->x] == 'E' && pm->collectables != 0)))
	{
		if (pm->map[pm->y + 1][pm->x] == 'C')
			pm->collectables--;
		if (pm->map[pm->y + 1][pm->x] == 'E' && pm->collectables == 0)
			exit_handler(pm);
		pm->map[pm->y][pm->x] = '0';
		pm->y = pm->y + 1;
		pm->steps++;
	}
}

void	go_up(t_PM *pm)
{
	if (0 < pm->y - 1 && pm->y - 1 < pm->height
		&& (pm->map[pm->y - 1][pm->x] != '1'
		&& !(pm->map[pm->y - 1][pm->x] == 'E' && pm->collectables != 0)))
	{
		if (pm->map[pm->y - 1][pm->x] == 'C')
			pm->collectables--;
		if (pm->map[pm->y - 1][pm->x] == 'E' && pm->collectables == 0)
			exit_handler(pm);
		pm->map[pm->y][pm->x] = '0';
		pm->y = pm->y - 1;
		pm->steps++;
	}
}
