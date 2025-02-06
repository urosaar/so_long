/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhanfa <oukhanfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:04:16 by oukhanfa          #+#    #+#             */
/*   Updated: 2025/02/06 18:10:06 by oukhanfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_line(char *line)
{
	if (!line)
	{
		ft_printf("Error: Empty line in map file\n");
		exit(1);
	}
}

char	**allocate_map(int height)
{
	char	**map;

	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
	{
		ft_printf("Error: Failed to allocate memory for map\n");
		exit(1);
	}
	return (map);
}

static void	get_width_and_height(char *file, t_data *data)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_error("Failed to open map file", NULL);
	line = get_next_line(fd);
	check_line(line);
	data->width = ft_strlen(line);
	if (data->width > 0 && line[data->width - 1] == '\n')
		line[--data->width - 1] = '\0';
	free(line);
	i = 1;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	data->height = i;
	close(fd);
}

static void	fill_processed_map(char *file, t_data *data, char **map)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_error("Failed to reopen map file", map);
	i = 0;
	while (i < data->height)
	{
		line = get_next_line(fd);
		check_line(line);
		if (ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if ((int)ft_strlen(line) != data->width)
		{
			free(line);
			exit_error("Invalid map try check lines lengths)", map);
		}
		map[i++] = line;
	}
	close(fd);
}

char	**readmap(char *file, t_data *data)
{
	char	**map;

	get_width_and_height(file, data);
	map = allocate_map(data->height);
	fill_processed_map(file, data, map);
	return (map);
}
