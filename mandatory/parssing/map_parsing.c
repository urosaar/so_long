/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhanfa <oukhanfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:23:43 by oukhanfa          #+#    #+#             */
/*   Updated: 2025/02/06 17:41:26 by oukhanfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	flood_fill(t_data *data, int x, int y)
{
	if (x < 0 || x >= data->height || y < 0 || y >= data->width)
		return ;
	if (data->map[x][y] == 'E')
		data->map[x][y] = '1';
	if (data->map[x][y] != '1')
	{
		data->map[x][y] = '1';
		flood_fill(data, x + 1, y);
		flood_fill(data, x - 1, y);
		flood_fill(data, x, y + 1);
		flood_fill(data, x, y - 1);
	}
}

void	init(t_ecp *ecp)
{
	ecp->x = 0;
	ecp->y = 0;
	ecp->c = 0;
	ecp->e = 0;
	ecp->p = 0;
}

void	count_ecp(t_data *data, t_ecp *ecp, char cell)
{
	if (cell == 'E')
		ecp->e++;
	else if (cell == 'C')
		ecp->c++;
	else if (cell == 'P')
	{
		ecp->p++;
		data->p_x = ecp->x;
		data->p_y = ecp->y;
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
	if (ecp.e != 1 || ecp.c < 1 || ecp.p != 1)
	{
		ft_printf("Error: Invalid E or C or P count\n");
		free_map(data->map, data->height);
		exit(1);
	}
	data->collect = ecp.c;
}

void	parsing(t_data *data)
{
	validate_walls(data);
	validate_rectangular(data);
	parse_ecp(data);
	validate_chars(data);
	flood_fill(data, data->p_x, data->p_y);
	free_map(data->map, data->height);
	data->map = readmap(data->file, data);
}
