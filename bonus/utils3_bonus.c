/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhanfa <oukhanfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:06:03 by oukhanfa          #+#    #+#             */
/*   Updated: 2025/02/07 19:16:21 by oukhanfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	handle_player_movement(t_all *all)
{
	static int	counter = 0;

	if (all->images->moving != 0)
	{
		all->images->idle_frame = 0;
		counter = 0;
		return (0);
	}
	counter++;
	if (counter % 4000 == 0)
	{
		all->images->idle_frame = (all->images->idle_frame + 1) % 4;
		return (1);
	}
	return (0);
}

void	update_animation(t_all *all)
{
	int	win_x;
	int	win_y;

	win_x = all->data->p_x * 64;
	win_y = all->data->p_y * 64;
	mlx_put_image_to_window(all->data->mlx, all->data->mlx_win,
		all->images->floor, win_x, win_y);
	if (all->images->idle_frame == 0)
		mlx_put_image_to_window(all->data->mlx, all->data->mlx_win,
			all->images->player, win_x, win_y);
	else if (all->images->idle_frame == 1)
		mlx_put_image_to_window(all->data->mlx, all->data->mlx_win,
			all->images->idle1, win_x, win_y);
	else if (all->images->idle_frame == 2)
		mlx_put_image_to_window(all->data->mlx, all->data->mlx_win,
			all->images->idle2, win_x, win_y);
	else if (all->images->idle_frame == 3)
		mlx_put_image_to_window(all->data->mlx, all->data->mlx_win,
			all->images->idle3, win_x, win_y);
}
