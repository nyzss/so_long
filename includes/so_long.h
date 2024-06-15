/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:29:12 by okoca             #+#    #+#             */
/*   Updated: 2024/06/15 10:44:19 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# include "mlx.h"
# include "libft.h"

# define PLAYER_CHAR 'P'
# define EMPTY_CHAR '0'
# define WALL_CHAR '1'
# define EXIT_CHAR 'E'
# define COLLECTIBLE_CHAR 'C'

# define FILL_CHAR 'F'

typedef struct s_vec2
{
	int	pos_x;
	int	pos_y;
}	t_vec2;

typedef struct s_map_data
{
	t_vec2	player_pos;
	t_vec2	exit_pos;
	t_vec2	*collectibles;
	int		map_h;
	int		map_w;
	char	**map;
	char	**filled_map;
}	t_map_data;

t_map_data	*sl_get_data(char **map);

t_vec2		sl_find_pos(char **map, char c);

void		sl_error_exit(int code, char *message);

void		sl_parse_arg(char *arg);

char		**sl_get_map(char *path);

int			sl_get_height(char *path);

void		sl_clear_map(char **array);

int			sl_count_char(char *str, char c);

void		sl_check_map(char **arr);

int			sl_check_if_closed(char **arr);

// void		sl_flood_fill(t_vec2 p_pos, char **arr);

char		**sl_get_filled_map(t_vec2 p_pos, char **arr);

int			sl_strchr(char *str, int c);

void		sl_print_map(char **map);

int			sl_get_count(char **map, char c);

int			sl_check_if_path(t_vec2 pos, char **filled_map);

#endif