/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_won.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhanfa <oukhanfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:55:42 by oukhanfa          #+#    #+#             */
/*   Updated: 2025/02/13 18:26:09 by oukhanfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_exit(t_all *all, int x, int y)
{
	if (all->data->map[x][y] == 'E' && all->data->collect == 0)
	{
		ft_printf("You win\n");
		exit(0);
	}
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

void	validate_path(char **map, int height, int width)
{
	int	i;
	int	j;

	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
			{
				ft_printf("Error: Player cannot win the game :(\n");
				exit(1);
			}
		}
	}
}

char	**copy_map(t_data *data)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (data->height + 1));
	i = -1;
	while (++i < data->height)
		copy[i] = ft_strdup(data->map[i]);
	copy[i] = NULL;
	return (copy);
}
