/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhanfa <oukhanfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:06:52 by oukhanfa          #+#    #+#             */
/*   Updated: 2025/02/13 13:03:50 by oukhanfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_walkable(t_data *data, int y, int x)
{
	if (data->map[y][x] == '0' || data->map[y][x] == 'C'
		|| data->map[y][x] == 'N' )
		return (1);
	if (data->map[y][x] == 'E' && data->collect == 0)
		return (1);
	return (0);
}

void	move_player(t_all *arg, int new_y, int new_x,
			void (*move_func)(t_all *, int, int))
{
	move_func(arg, arg->data->p_y, arg->data->p_x);
	arg->data->move++;
	arg->data->p_y = new_y;
	arg->data->p_x = new_x;
}

void	xpm_to_img(t_images *images, t_data *data)
{
	int	width;
	int	height;

	data->move = 0;
	images->wall = mlx_xpm_file_to_image(data->mlx,
			"./images/W.xpm", &width, &height);
	images->floor = mlx_xpm_file_to_image(data->mlx,
			"./images/F.xpm", &width, &height);
	images->exite = mlx_xpm_file_to_image(data->mlx,
			"./images/E.xpm", &width, &height);
	images->collect = mlx_xpm_file_to_image(data->mlx,
			"./images/C.xpm", &width, &height);
	load_player_images(images, data);
	xpm_to_img_enemy(images, data);
	images->player_left = mlx_xpm_file_to_image(data->mlx,
			"./images/left.xpm", &width, &height);
	images->player_right = mlx_xpm_file_to_image(data->mlx,
			"./images/right.xpm", &width, &height);
	images->player_down = mlx_xpm_file_to_image(data->mlx,
			"./images/down.xpm", &width, &height);
	images->player_up = mlx_xpm_file_to_image(data->mlx,
			"./images/up.xpm", &width, &height);
	images->moving = 0;
}

void	put_image(t_data *data, t_images *images, int x, int y)
{
	if (data->map[x][y] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win, images->wall,
			y * 64, x * 64);
	if (data->map[x][y] == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win, images->floor,
			y * 64, x * 64);
	if (data->map[x][y] == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win, images->exite,
			y * 64, x * 64);
	if (data->map[x][y] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, images->floor,
			y * 64, x * 64);
		mlx_put_image_to_window(data->mlx, data->mlx_win, images->collect,
			y * 64, x * 64);
		data->collect++;
	}
	if (data->map[x][y] == 'N')
		put_enemy_image(data, images, x, y);
	if (data->map[x][y] == 'P')
		put_player_image(data, images, x, y);
}

void	put_map(t_data *data, t_images *images)
{
	int	i;
	int	j;

	i = 0;
	data->collect = 0;
	xpm_to_img(images, data);
	if (!images->wall || !images->floor || !images->exite || !images->collect
		|| !images->player)
	{
		ft_printf("Error, image didn't load\n");
		exit(0);
	}
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			put_image(data, images, i, j);
			j++;
		}
		i++;
	}
}
