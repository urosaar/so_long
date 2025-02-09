/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhanfa <oukhanfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:10:54 by oukhanfa          #+#    #+#             */
/*   Updated: 2025/02/07 18:19:56 by oukhanfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_moves(t_all *all)
{
	char	*move_count;
	char	*move_text;
	int		text_x ;
	int		text_y ;

	text_x = 80;
	text_y = 20;
	move_count = ft_itoa(all->data->move + 1);
	move_text = ft_strjoin("Moves  ", move_count);
	mlx_put_image_to_window(all->data->mlx, all->data->mlx_win,
		all->images->wall, 0, 0);
	mlx_string_put(all->data->mlx, all->data->mlx_win, 10,
		text_y, 0xFFFFFF, move_text);
	mlx_put_image_to_window(all->data->mlx, all->data->mlx_win,
		all->images->wall, 64, 0);
	mlx_string_put(all->data->mlx, all->data->mlx_win, text_x,
		text_y, 0xFFFFFF, move_count);
	free(move_count);
	free(move_text);
}

void	validate_path(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->height)
	{
		j = -1;
		while (++j < data->width)
		{
			if (data->map[i][j] == 'C' || data->map[i][j] == 'E')
			{
				ft_printf("Error: player can't win the game :(\n");
				free_map(data->map, data->height);
				exit(1);
			}
		}
	}
}

static int	ft_nbrlen(long nbr)
{
	int	len;

	len = 0;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		len++;
	}
	if (nbr == 0)
		len = 1;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nb;

	nb = (long)n;
	len = ft_nbrlen(nb);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		nb = nb * -1;
		str[0] = '-';
	}
	while (nb > 0)
	{
		str[len] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
	return (str);
}

int	key_release(int keycode, t_all *all)
{
	if (keycode == 123
		|| keycode == 124
		|| keycode == 125
		|| keycode == 126)
	{
		mlx_put_image_to_window(all->data->mlx, all->data->mlx_win,
			all->images->floor, all->data->p_x * 64, all->data->p_y * 64);
		mlx_put_image_to_window(all->data->mlx, all->data->mlx_win,
			all->images->player, all->data->p_x * 64, all->data->p_y * 64);
		all->images->moving = 0;
	}
	return (0);
}
