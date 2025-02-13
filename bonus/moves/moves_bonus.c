/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhanfa <oukhanfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:52:55 by oukhanfa          #+#    #+#             */
/*   Updated: 2025/02/13 12:31:24 by oukhanfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	up(t_all *all, int x, int y)
{
	char	target;

	target = all->data->map[x - 1][y];
	check_enemy_collision(target);
	if (target == '0' || target == 'C')
	{
		if (target == 'C')
			all->data->collect--;
		all->data->map[x][y] = '0';
		all->data->map[x - 1][y] = 'P';
		all->images->moving = 1;
		mlx_put_image_to_window(all->data->mlx, all->data->mlx_win,
			all->images->floor, y * 64, x * 64);
		mlx_put_image_to_window(all->data->mlx, all->data->mlx_win,
			all->images->floor, y * 64, (x - 1) * 64);
		mlx_put_image_to_window(all->data->mlx, all->data->mlx_win,
			all->images->player_up, y * 64, (x - 1) * 64);
		display_moves(all);
	}
	all->data->p_y = x - 1;
	all->data->p_x = y;
}

void	down(t_all *all, int x, int y)
{
	char	target;

	target = all->data->map[x + 1][y];
	check_enemy_collision(target);
	if (target == '0' || target == 'C')
	{
		if (target == 'C')
			all->data->collect--;
		all->data->map[x][y] = '0';
		all->data->map[x + 1][y] = 'P';
		all->images->moving = 2;
		mlx_put_image_to_window(all->data->mlx, all->data->mlx_win,
			all->images->floor, y * 64, x * 64);
		mlx_put_image_to_window(all->data->mlx, all->data->mlx_win,
			all->images->floor, y * 64, (x + 1) * 64);
		mlx_put_image_to_window(all->data->mlx, all->data->mlx_win,
			all->images->player_down, y * 64, (x + 1) * 64);
		display_moves(all);
	}
	all->data->p_y = x + 1;
	all->data->p_x = y;
}

void	left(t_all *all, int x, int y)
{
	char	target;

	target = all->data->map[x][y - 1];
	check_enemy_collision(target);
	if (target == '0' || target == 'C')
	{
		if (target == 'C')
			all->data->collect--;
		all->data->map[x][y] = '0';
		all->data->map[x][y - 1] = 'P';
		all->images->moving = 3;
		mlx_put_image_to_window(all->data->mlx, all->data->mlx_win,
			all->images->floor, y * 64, x * 64);
		mlx_put_image_to_window(all->data->mlx, all->data->mlx_win,
			all->images->floor, (y - 1) * 64, x * 64);
		mlx_put_image_to_window(all->data->mlx, all->data->mlx_win,
			all->images->player_left, (y - 1) * 64, x * 64);
		display_moves(all);
	}
	all->data->p_x = y - 1;
	all->data->p_y = x;
}

void	right(t_all *all, int x, int y)
{
	char	target;

	target = all->data->map[x][y + 1];
	check_enemy_collision(target);
	if (target == '0' || target == 'C')
	{
		if (target == 'C')
			all->data->collect--;
		all->data->map[x][y] = '0';
		all->data->map[x][y + 1] = 'P';
		all->images->moving = 4;
		mlx_put_image_to_window(all->data->mlx, all->data->mlx_win,
			all->images->floor, y * 64, x * 64);
		mlx_put_image_to_window(all->data->mlx, all->data->mlx_win,
			all->images->floor, (y + 1) * 64, x * 64);
		mlx_put_image_to_window(all->data->mlx, all->data->mlx_win,
			all->images->player_right, (y + 1) * 64, x * 64);
		display_moves(all);
	}
	all->data->p_x = y + 1;
	all->data->p_y = x;
}

int	close_game(t_all *all)
{
	mlx_destroy_window (all->data->mlx, all->data->mlx_win);
	exit (0);
}
