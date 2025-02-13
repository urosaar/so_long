/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmoves.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhanfa <oukhanfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:35:43 by oukhanfa          #+#    #+#             */
/*   Updated: 2025/02/13 13:29:11 by oukhanfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(t_all *arg)
{
	int	new_y;
	int	new_x;

	new_y = arg->data->p_y - 1;
	new_x = arg->data->p_x;
	if (new_y >= 0 && is_walkable(arg->data, new_y, new_x))
	{
		check_exit(arg, new_y, new_x);
		move_player(arg, new_y, new_x, up);
	}
}

static void	move_down(t_all *arg)
{
	int	new_y;
	int	new_x;

	new_y = arg->data->p_y + 1;
	new_x = arg->data->p_x;
	if (new_y < arg->data->height && is_walkable(arg->data, new_y, new_x))
	{
		check_exit(arg, new_y, new_x);
		move_player(arg, new_y, new_x, down);
	}
}

static void	move_right(t_all *arg)
{
	int	new_y;
	int	new_x;

	new_y = arg->data->p_y;
	new_x = arg->data->p_x + 1;
	if (new_x < arg->data->width && is_walkable(arg->data, new_y, new_x))
	{
		check_exit(arg, new_y, new_x);
		move_player(arg, new_y, new_x, right);
	}
}

static void	move_left(t_all *arg)
{
	int	new_y;
	int	new_x;

	new_y = arg->data->p_y;
	new_x = arg->data->p_x - 1;
	if (new_x >= 0 && is_walkable(arg->data, new_y, new_x))
	{
		check_exit(arg, new_y, new_x);
		move_player(arg, new_y, new_x, left);
	}
}

int	player_movement(int keycode, t_all *all)
{
	if (keycode == 53)
	{
		free_map(all->data->map, all->data->height);
		exit(0);
	}
	else if (keycode == 126)
		move_up(all);
	else if (keycode == 125)
		move_down(all);
	else if (keycode == 124)
		move_right(all);
	else if (keycode == 123)
		move_left(all);
	return (0);
}
