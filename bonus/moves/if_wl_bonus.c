/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_wl_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhanfa <oukhanfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:55:42 by oukhanfa          #+#    #+#             */
/*   Updated: 2025/02/06 18:09:12 by oukhanfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	check_exit(t_all *all, int x, int y)
{
	if (all->data->map[x][y] == 'E' && all->data->collect == 0)
	{
		ft_printf("You win\n");
		exit(0);
	}
}

void	check_enemy_collision(char cell)
{
	if (cell == 'N')
	{
		ft_printf("You lose!\n");
		exit(0);
	}
}

void	put_player_image(t_data *data, t_images *images, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		images->floor, y * 64, x * 64);
	if (images->moving == 1)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			images->player_up, y * 64, x * 64);
	else if (images->moving == 2)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			images->player_down, y * 64, x * 64);
	else if (images->moving == 3)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			images->player_left, y * 64, x * 64);
	else if (images->moving == 4)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			images->player_right, y * 64, x * 64);
	else
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			images->player, y * 64, x * 64);
}

void	put_enemy_image(t_data *data, t_images *images, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		images->floor, y * 64, x * 64);
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		images->enemy, y * 64, x * 64);
}

void	init_mlx(t_data *data, t_images *images, t_all *all)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		error_exit(data, "MLX initialization failed");
	data->mlx_win = mlx_new_window(data->mlx, data->width * 64,
			data->height * 64, "so_long");
	if (!data->mlx_win)
		error_exit(data, "Window creation failed");
	put_map(data, images);
	all->data = data;
	all->images = images;
}
