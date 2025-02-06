/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhanfa <oukhanfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:02:56 by oukhanfa          #+#    #+#             */
/*   Updated: 2025/02/06 18:09:45 by oukhanfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	validate_walls(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->height)
	{
		if (data->map[i][0] != '1' || data->map[i][data->width - 1] != '1')
		{
			ft_printf("Error: Map not enclosed by walls\n");
			free_map(data->map, data->height);
			exit(1);
		}
		i++;
	}
	while (j < data->width)
	{
		if (data->map[0][j] != '1' || data->map[data->height - 1][j] != '1')
		{
			ft_printf("Error: Map not enclosed by walls\n");
			free_map(data->map, data->height);
			exit(1);
		}
		j++;
	}
}

void	validate_rectangular(t_data *data)
{
	int	i;
	int	expected_width ;

	if (!data->map)
		return ;
	i = 0;
	expected_width = data->width;
	while (i < data->height)
	{
		if ((int)ft_strlen(data->map[i]) != expected_width)
		{
			ft_printf("Error: Map is not rectangular\n");
			free_map(data->map, data->height);
			exit(1);
		}
		i++;
	}
}

void	validate_chars(t_data *data)
{
	int		i;
	int		j;
	char	cell;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			cell = data->map[i][j];
			if (cell != '1' && cell != '0' && cell != 'P'
				&& cell != 'C' && cell != 'E' && cell != 'N')
			{
				ft_printf("Error: Invalid character \n", cell, i, j);
				free_map(data->map, data->height);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	free_map(char **map, int height)
{
	int	i;

	i = 0;
	if (map)
	{
		while (i < height)
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
}

void	check_file_extension(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (i < 4 || file[i - 1] != 'r' || file[i - 2] != 'e'
		|| file[i - 3] != 'b' || file[i - 4] != '.')
	{
		ft_printf("Error: try file end with -> .ber\n");
		exit(0);
	}
}
