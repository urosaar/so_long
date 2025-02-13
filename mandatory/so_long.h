/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhanfa <oukhanfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:01:26 by oukhanfa          #+#    #+#             */
/*   Updated: 2025/02/13 18:12:19 by oukhanfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/ft_printf/ft_printf.h"
# include "libft/get_next_line/get_next_line.h"
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>

typedef struct s_images
{
	void	*wall;
	void	*floor;
	void	*exite;
	void	*collect;
	void	*player;
	void	*enemy;
	void	*player_up;
	void	*player_down;
	void	*player_left;
	void	*player_right;
	int		moving;
}					t_images;

typedef struct s_data
{
	void			*mlx;
	void			*mlx_win;
	char			**map;
	int				height;
	int				width;
	int				p_x;
	int				p_y;
	int				collect;
	int				move;
	char			*file;
}					t_data;

typedef struct s_ecp
{
	int	x;
	int	y;
	int	c;
	int	e;
	int	p;
	int	n;
}					t_ecp;

typedef struct s_all
{
	t_data		*data;
	t_images	*images;
}				t_all;

void	free_map(char **map, int height);
void	validate_walls(t_data *data);
void	validate_rectangular(t_data *data);
void	validate_chars(t_data *data);
void	parsing(t_data *data);
void	up(t_all *all, int x, int y);
void	down(t_all *all, int x, int y);
void	left(t_all *all, int x, int y);
void	right(t_all *all, int x, int y);
int		close_game(t_all *all);
int		player_movement(int keycode, t_all *all);
void	check_file_extension(char *file);
char	**readmap(char *file, t_data *data);
void	put_map(t_data *data, t_images *images);
int		is_walkable(t_data *data, int y, int x);
void	move_player(t_all *arg, int new_y, int new_x,
			void (*move_func)(t_all *, int, int));
void	check_exit(t_all *all, int x, int y);
void	exit_error(char *message, char **map);
void	error_exit(t_data *data, char *message);
void	init_mlx(t_data *data, t_images *images, t_all *all);
void	validate_path(char **map, int height, int width);
char	**copy_map(t_data *data);
#endif