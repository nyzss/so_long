/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:29:12 by okoca             #+#    #+#             */
/*   Updated: 2024/06/16 18:31:39 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>

# include "mlx.h"
# include "libft.h"

# define WALL_TEXTURE "./textures/left.xpm"
# define GROUND_TEXTURE "./textures/ground.xpm"
# define PLAYER_TEXTURE "./textures/player.xpm"
# define COLLECTIBLE_TEXTURE "./textures/collectible.xpm"
# define EXIT_TEXTURE "./textures/exit.xpm"
# define TEXTURE_COUNT 5
# define TEXTURE_PIXEL 64

# define PLAYER_CHAR 'P'
# define EMPTY_CHAR '0'
# define WALL_CHAR '1'
# define EXIT_CHAR 'E'
# define COLLECTIBLE_CHAR 'C'

# define FILL_CHAR 'F'

# define TRUE 1
# define FALSE 0

# define WINDOW_HEIGHT 600
# define WINDOW_WIDTH 640

# define UP 0
# define DOWN 1
# define LEFT 2
# define RIGHT 3

typedef struct s_vec2
{
	int	x;
	int	y;
	int	collected;
}	t_vec2;

typedef struct s_collectibles
{
	int		count;
	int		collected;
	t_vec2	*values;
}	t_collectibles;

typedef struct s_map_data
{
	t_vec2			player_pos;
	t_vec2			exit_pos;
	t_collectibles	collectibles;
	int				height;
	int				width;
	char			**map;
	char			**filled_map;
}	t_map_data;

typedef enum e_tex_name
{
	WALL,
	GROUND,
	PLAYER,
	COLLECTIBLE,
	EXIT
}	t_tex_name;

typedef struct s_texture
{
	int		id;
	int		height;
	int		width;
	void	*data;
}	t_texture;

typedef struct s_ctx
{
	void		*mlx;
	void		*window;
	t_texture	*textures;
	t_map_data	*map_data;
}	t_ctx;

t_map_data		*sl_get_data(char **map);

t_vec2			sl_find_pos(char **map, char c);

t_vec2			sl_find_next_pos(char **map, char c, int reset);

t_collectibles	sl_get_all_collectibles(char **map, int reset);

t_texture		sl_create_texture(t_ctx *ctx, char *texture_path);

int				sl_init_textures(t_ctx *ctx);

int				sl_render_tiles(t_ctx *ctx);

int				sl_move_to_direction(t_ctx *ctx, int direction);

int				sl_move_player(int kc, t_ctx *ctx);

int				sl_handle_keypress(int keycode, t_ctx *ctx);

int				sl_free_exit(t_ctx *ctx);

void			sl_debug(t_map_data *map);

void			sl_error_exit(int code, char *message);

void			sl_parse_arg(char *arg);

char			**sl_get_map(char *path);

int				sl_get_height(char *path);

void			sl_clear_map(char **array);

int				sl_count_char(char *str, char c);

void			sl_check_map(char **arr);

int				sl_check_if_closed(char **arr);

char			**sl_get_filled_map(t_vec2 p_pos, char **arr);

int				sl_strchr(char *str, int c);

void			sl_print_map(char **map);

int				sl_get_count(char **map, char c);

int				sl_check_if_path(t_vec2 pos, char **filled_map);

int				sl_next_strchr(char *str, int c);

#endif