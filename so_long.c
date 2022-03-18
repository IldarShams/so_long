/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaegan <smaegan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:58:58 by smaegan           #+#    #+#             */
/*   Updated: 2022/03/18 14:27:51 by smaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	**images_load(void *mlx)
{
	int		img_w;
	int		img_h;
	void	**img;

	img_w = 64;
	img_h = 64;
	img = malloc(6 * sizeof(void *));
	img[0] = mlx_png_file_to_image(mlx, "./sprites/wall.png", &img_w, &img_h);
	img[1] = mlx_png_file_to_image(mlx, "./sprites/Ground.png", &img_w, &img_h);
	img[2] = mlx_png_file_to_image(mlx, "./sprites/Player.png", &img_w, &img_h);
	img[3] = mlx_png_file_to_image(mlx, "./sprites/pig.png", &img_w, &img_h);
	img[4] = mlx_png_file_to_image(mlx, "./sprites/door.png", &img_w, &img_h);
	img_w = 1280;
	img_h = 720;
	img[5] = mlx_png_file_to_image(mlx, "./sprites/space.png", &img_w, &img_w);
	return (img);
}

void	*window_init(void *mlx, char **map)
{
	int		width;
	int		height;
	int		i;
	int		img_w;
	int		img_h;

	img_w = 64;
	img_h = 64;
	i = 0;
	width = (ft_strlen(map[0]) - 1);
	height = 0;
	while (map[i++] != NULL)
		height++;
	return (mlx_new_window(mlx, 1280, 720, "so_long"));
}

void	init_pm(t_PM *pm)
{
	int	i;
	int	j;

	pm->height = -1;
	while (pm->map[++(pm->height)] != NULL)
		;
	pm->width = ft_strlen(pm->map[0]) - 1;
	pm->collectables = 0;
	pm->steps = 0;
	i = -1;
	while (++i < pm->height)
	{
		j = -1;
		while (pm->map[i][++j] != '\0')
		{
			if (pm->map[i][j] == 'P')
			{
				pm->x = j;
				pm->y = i;
				pm->map[i][j] = '0';
			}
			if (pm->map[i][j] == 'C')
				pm->collectables++;
		}
	}
}

void	init(t_PM *pm)
{
	init_pm(pm);
	pm->mlx = mlx_init();
	pm->w = window_init(pm->mlx, pm->map);
	pm->img = images_load(pm->mlx);
}

int	main(int argc, char **argv)
{
	t_PM	pm;
	int		fd;
	int		i;
	char	*ber;

	if (argc != 2)
		return (write(1, "Map error\n", 10));
	ber = ft_substr(argv[1], ft_strlen(argv[1]) - 4, 4);
	i = ft_strncmp(ber, ".ber", 4);
	free(ber);
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0 || i != 0)
		return (write(1, "Map error\n", 10));
	map_load(fd, &pm);
	close(fd);
	if (map_check(pm))
	{
		free_map(pm.map);
		return (write(1, "Map error\n", 10));
	}
	init(&pm);
	center_scrin_print(&pm);
	mlx_key_hook(pm.w, key_handler, (void *) &pm);
	mlx_hook(pm.w, 17, 0, exit_handler, &pm);
	mlx_loop(pm.mlx);
}
