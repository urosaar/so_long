/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhanfa <oukhanfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:23:43 by oukhanfa          #+#    #+#             */
/*   Updated: 2025/02/13 18:35:19 by oukhanfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	flood_fill(char **map, int x, int y, t_data *data)
{
	if (x < 0 || x >= data->height || y < 0 || y >= data->width)
		return ;
	if (map[x][y] == '1' || map[x][y] == 'N')
		return ;
	if (map[x][y] == 'E')
	{
		map[x][y] = '1';
		return ;
	}
	if (map[x][y] != '1')
	{
		map[x][y] = '1';
		flood_fill(map, x + 1, y, data);
		flood_fill(map, x - 1, y, data);
		flood_fill(map, x, y + 1, data);
		flood_fill(map, x, y - 1, data);
	}
}

void	init(t_ecp *ecp)
{
	ecp->x = 0;
	ecp->y = 0;
	ecp->c = 0;
	ecp->e = 0;
	ecp->p = 0;
	ecp->n = 0;
}

void	count_ecp(t_data *data, t_ecp *ecp, char cell)
{
	if (cell == 'E')
		ecp->e++;
	else if (cell == 'C')
		ecp->c++;
	else if (cell == 'N')
	{
		ecp->n++;
		return ;
	}
	else if (cell == 'P')
	{
		ecp->p++;
		data->p_x = ecp->y;
		data->p_y = ecp->x;
	}
	else if (cell != '0' && cell != '1')
	{
		ft_printf("Error: Invalid character\n");
		free_map(data->map, data->height);
		exit(1);
	}
}

void	parse_ecp(t_data *data)
{
	t_ecp	ecp;

	init(&ecp);
	while (ecp.x < data->height)
	{
		ecp.y = 0;
		while (ecp.y < data->width)
		{
			count_ecp(data, &ecp, data->map[ecp.x][ecp.y]);
			ecp.y++;
		}
		ecp.x++;
	}
	if (ecp.e != 1 || ecp.c < 1 || ecp.p != 1 || ecp.n < 1)
	{
		ft_printf("Error: Invalid E or C or P or N count\n");
		free_map(data->map, data->height);
		exit(1);
	}
	data->collect = ecp.c;
}

void	parsing(t_data *data)
{
	char	**map_copy;

	validate_walls(data);
	validate_rectangular(data);
	parse_ecp(data);
	validate_chars(data);
	map_copy = copy_map(data);
	flood_fill(map_copy, data->p_y, data->p_x, data);
	validate_path(map_copy, data->height, data->width);
	free_map(map_copy, data->height);
}
