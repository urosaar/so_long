/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhanfa <oukhanfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:52:55 by oukhanfa          #+#    #+#             */
/*   Updated: 2025/02/06 17:32:16 by oukhanfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	up(t_all *all, int x, int y)
{
	if (all->data->map[x - 1][y] == '0' || all->data->map[x - 1][y] == 'C')
	{
		if (all->data->map[x - 1][y] == 'C')
			all->data->collect--;
		all->data->map[x][y] = '0';
		all->data->map[x - 1][y] = 'P';
		mlx_put_image_to_window(all->data->mlx, all->data->mlx_win,
			all->images->floor, y * 64, x * 64);
		mlx_put_image_to_window(all->data->mlx, all->data->mlx_win,
			all->images->floor, y * 64, (x - 1) * 64);
		mlx_put_image_to_window(all->data->mlx, all->data->mlx_win,
			all->images->player, y * 64, (x - 1) * 64);
	}
}

void	down(t_all *all, int x, int y)
{
	if (all->data->map[x + 1][y] == '0' || all->data->map[x + 1][y] == 'C')
	{
		if (all->data->map[x + 1][y] == 'C')
			all->data->collect--;
		all->data->map[x][y] = '0';
		all->data->map[x + 1][y] = 'P';
		mlx_put_image_to_window(all->data->mlx, all->data->mlx_win,
			all->images->floor, y * 64, x * 64);
		mlx_put_image_to_window(all->data->mlx, all->data->mlx_win,
			all->images->floor, y * 64, (x + 1) * 64);
		mlx_put_image_to_window(all->data->mlx, all->data->mlx_win,
			all->images->player, y * 64, (x + 1) * 64);
	}
}

void	left(t_all *all, int x, int y)
{
	if (all->data->map[x][y - 1] == '0' || all->data->map[x][y - 1] == 'C')
	{
		if (all->data->map[x][y - 1] == 'C')
			all->data->collect--;
		all->data->map[x][y] = '0';
		all->data->map[x][y - 1] = 'P';
		mlx_put_image_to_window(all->data->mlx, all->data->mlx_win,
			all->images->floor, y * 64, x * 64);
		mlx_put_image_to_window(all->data->mlx, all->data->mlx_win,
			all->images->floor, (y - 1) * 64, x * 64);
		mlx_put_image_to_window(all->data->mlx, all->data->mlx_win,
			all->images->player, (y - 1) * 64, x * 64);
	}
}

void	right(t_all *all, int x, int y)
{
	if (all->data->map[x][y + 1] == '0' || all->data->map[x][y + 1] == 'C')
	{
		if (all->data->map[x][y + 1] == 'C')
			all->data->collect--;
		all->data->map[x][y] = '0';
		all->data->map[x][y + 1] = 'P';
		mlx_put_image_to_window(all->data->mlx, all->data->mlx_win,
			all->images->floor, y * 64, x * 64);
		mlx_put_image_to_window(all->data->mlx, all->data->mlx_win,
			all->images->floor, (y + 1) * 64, x * 64);
		mlx_put_image_to_window(all->data->mlx, all->data->mlx_win,
			all->images->player, (y + 1) * 64, x * 64);
	}
}

int	close_game(t_all *all)
{
	mlx_destroy_window (all->data->mlx, all->data->mlx_win);
	exit (0);
}
