/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaegan <smaegan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:48:17 by smaegan           #+#    #+#             */
/*   Updated: 2022/03/18 14:27:02 by smaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "./get_next_line/get_next_line.h"
# include "./Libft/libft.h"
# include "./minilibx_mms_20200219/mlx.h"

typedef struct s_PlayerMap
{
	int						x;
	int						y;
	char					**map;
	int						height;
	int						width;
	int						collectables;
	unsigned long long		steps;
	void					*mlx;
	void					*w;
	void					**img;
}	t_PM;

typedef struct s_xyij
{
	int	x;
	int	y;
	int	i;
	int	j;
}	t_xyij;

void	init(t_PM *pm);
void	free_map(char **m);
void	show_map(char **m);
int		copy(char **m, char **temp);
void	map_load(int fd, t_PM *pm);
int		b_c(char *line, int flag);
int		map_check(t_PM pm);
void	go_left(t_PM *pm);
void	go_right(t_PM *pm);
void	go_down(t_PM *pm);
void	go_up(t_PM *pm);
int		key_handler(int keycode, void *param);
int		exit_handler(void *param);
void	**images_load(void *mlx);
void	*window_init(void *mlx, char **map);
void	center_scrin_print(t_PM *pm);
void	put_img(t_PM *pm, t_xyij xyij);
void	init_pm(t_PM *pm);
int		invalid_symbol_check(char *line);
int		map_square_check(t_PM pm);

#endif
