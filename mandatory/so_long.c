/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhanfa <oukhanfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:54:31 by oukhanfa          #+#    #+#             */
/*   Updated: 2025/02/13 18:13:09 by oukhanfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(t_data *data, char *message)
{
	ft_printf("Error: %s\n", message);
	if (data->map)
		free_map(data->map, data->height);
	exit(1);
}

void	exit_error(char *message, char **map)
{
	if (message)
		ft_printf("Error: %s\n", message);
	if (map)
		free_map(map, 0);
	exit(1);
}

void	p_x_y(t_data *data)
{
	int	found;
	int	i;
	int	j;

	found = 0;
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->map[i][j] == 'P')
			{
				if (found)
					error_exit(data, "Multiple players in map");
				data->p_x = j;
				data->p_y = i;
				found = 1;
			}
			j++;
		}
		i++;
	}
	if (!found)
		error_exit(data, "No player found in map");
}

void	check_fd(int fd)
{
	if (fd < 0)
	{
		ft_printf("Error\n");
		exit(0);
	}
}

int	main(int ac, char **av)
{
	t_data		data;
	t_images	images;
	t_all		all;

	if (ac != 2)
		error_exit(NULL, "ERROR try use : ./so_long <map.ber>");
	data.file = av[1];
	check_file_extension(av[1]);
	data.map = readmap(av[1], &data);
	p_x_y(&data);
	parsing(&data);
	init_mlx(&data, &images, &all);
	mlx_hook(data.mlx_win, 2, 1L << 0, player_movement, &all);
	mlx_hook(data.mlx_win, 17, 1L << 17, close_game, &all);
	mlx_loop(data.mlx);
	return (0);
}
