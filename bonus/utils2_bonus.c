/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhanfa <oukhanfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:27:21 by oukhanfa          #+#    #+#             */
/*   Updated: 2025/02/07 19:25:08 by oukhanfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	xpm_to_img_enemy(t_images *images, t_data *data)
{
	int	width;
	int	height;

	images->enemy = mlx_xpm_file_to_image(data->mlx,
			"./images/N.xpm", &width, &height);
	images->enemy_frame1 = mlx_xpm_file_to_image(data->mlx,
			"./images/frame1.xpm", &width, &height);
	images->enemy_frame2 = mlx_xpm_file_to_image(data->mlx,
			"./images/frame2.xpm", &width, &height);
	images->enemy_frame3 = mlx_xpm_file_to_image(data->mlx,
			"./images/frame3.xpm", &width, &height);
	images->enemy_anim_frame = 0;
	if (!images->enemy || !images->enemy_frame1
		|| !images->enemy_frame2 || !images->enemy_frame3)
		error_exit(data, "Enemy frames failed to load");
}

int	animate_enemy(void *param)
{
	static int	counter = 0;
	t_all		*all;
	int			i;
	int			j;

	all = (t_all *)param;
	counter++;
	if (counter >= 5000)
	{
		counter = 0;
		all->images->enemy_anim_frame = (all->images->enemy_anim_frame + 1) % 4;
		i = 0;
		while (i < all->data->height)
		{
			j = 0;
			while (j < all->data->width)
			{
				if (all->data->map[i][j] == 'N')
					put_enemy_image(all->data, all->images, i, j);
				j++;
			}
			i++;
		}
	}
	return (0);
}

void	load_player_images(t_images *images, t_data *data)
{
	int	width;
	int	height;

	images->player = mlx_xpm_file_to_image(data->mlx, "./images/P.xpm",
			&width, &height);
	images->idle1 = mlx_xpm_file_to_image(data->mlx, "./images/idle1.xpm",
			&width, &height);
	images->idle2 = mlx_xpm_file_to_image(data->mlx, "./images/idle2.xpm",
			&width, &height);
	images->idle3 = mlx_xpm_file_to_image(data->mlx, "./images/idle3.xpm",
			&width, &height);
	if (!images->player || !images->idle1 || !images->idle2 || !images->idle3)
	{
		ft_printf("Error: player animation frames not loaded\n");
		exit(1);
	}
	images->idle_frame = 0;
}

int	animate_player(t_all *all)
{
	if (handle_player_movement(all))
		update_animation(all);
	return (0);
}

int	animate_all(void *param)
{
	static int	counter = 0;
	t_all		*all;

	all = (t_all *)param;
	counter++;
	if (counter >= 1)
	{
		counter = 0;
		animate_enemy(all);
		animate_player(all);
	}
	return (0);
}
