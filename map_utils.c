/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaegan <smaegan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:01:58 by smaegan           #+#    #+#             */
/*   Updated: 2022/03/17 18:24:38 by smaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **m)
{
	int	i;

	i = 0;
	if (m == NULL)
		return ;
	while (m[i] != NULL)
	{
		free(m[i]);
		i++;
	}
	free(m[i]);
	free(m);
}

void	show_map(char **m)
{
	int	i;

	i = 0;
	if (m == NULL)
		return ;
	while (m[i] != NULL)
	{
		ft_putstr_fd(m[i], 1);
		i++;
	}
}

int	copy(char **m, char **temp)
{
	int		i;

	i = 0;
	while (m[i] != NULL)
	{
		temp[i] = m[i];
		i++;
	}
	return (i);
}

void	map_load(int fd, t_PM *pm)
{
	char	**temp;
	char	*line;
	int		size;

	pm->map = malloc(sizeof(char *));
	if (pm->map == NULL)
		return ;
	pm->map[0] = NULL;
	size = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		temp = malloc(++size * sizeof(char *));
		if (temp == NULL)
			free_map(pm->map);
		if (pm->map == NULL)
			return ;
		copy(pm->map, temp);
		temp[size - 2] = line;
		temp[size - 1] = NULL;
		free(pm->map);
		pm->map = temp;
	}
}

int	b_c(char *line, int flag)
{
	int	i;

	i = 0;
	if (line == NULL || invalid_symbol_check(line))
		return (1);
	if (flag == 0)
	{
		while (line[i] != '\n' && line[i] != '\0')
		{
			if (line[i] != '1')
				return (1);
			i++;
		}
	}
	if (flag == 1 && line[0] != '1')
		return (1);
	if (flag == 1)
	{
		while (*(line + 1) != '\n' && *(line + 1) != '\0')
			line++;
		if (*line != '1')
			return (1);
	}
	return (0);
}
