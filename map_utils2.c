/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaegan <smaegan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:10:37 by smaegan           #+#    #+#             */
/*   Updated: 2022/03/17 18:27:47 by smaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_check(t_PM pm)
{
	int	flag[3];
	int	i;
	int	j;

	i = -1;
	while (pm.map != NULL && pm.map[++i] != NULL)
	{
		j = 0;
		if (((i == 0 || pm.map[i + 1] == NULL)
				&& b_c(pm.map[i], 0)) || b_c(pm.map[i], 1))
			return (1);
		while (pm.map[i][j] != '\0')
		{
			if (pm.map[i][j] == 'P')
				flag[0] = 1;
			if (pm.map[i][j] == 'E')
				flag[1] = 1;
			if (pm.map[i][j] == 'C')
				flag[2] = 1;
			j++;
		}
	}
	if (flag[0] != 1 || flag[1] != 1 || flag[2] != 1)
		return (1);
	return (0);
}

int	get_map_height(char **map)
{	
	int		height;

	height = 0;
	while (map[height] != NULL)
		height++;
	return (height);
}

int	invalid_symbol_check(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] != '1' && line[i] != '0'
			&& line[i] != 'C' && line[i] != 'E'
			&& line[i] != 'P')
			return (1);
		i++;
	}
	return (0);
}
