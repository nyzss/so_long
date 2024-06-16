/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:28:37 by okoca             #+#    #+#             */
/*   Updated: 2024/06/16 16:13:03 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_free_all(t_ctx *ctx)
{
	int	i;

	i = 0;
	if (ctx->window)
		mlx_destroy_window(ctx->mlx, ctx->window);
	if (ctx->textures)
	{
		while (i < TEXTURE_COUNT)
		{
			mlx_destroy_image(ctx->mlx, ctx->textures[i].data);
			i++;
		}
		free(ctx->textures);
	}
	mlx_loop_end(ctx->mlx);
	mlx_destroy_display(ctx->mlx);
	free(ctx->map_data->collectibles.values);
	sl_clear_map(ctx->map_data->map);
	sl_clear_map(ctx->map_data->filled_map);
	free(ctx->map_data);
	free(ctx->mlx);
	return (0);
}

t_map_data	*sl_get_map_data(char *path)
{
	char		**map;
	t_map_data	*map_data;

	sl_parse_arg(path);
	map = sl_get_map(path);
	sl_check_map(map);
	map_data = sl_get_data(map);
	sl_debug(map_data);
	return (map_data);
}

int	sl_close_window(int keycode, t_ctx *ctx)
{
	if (keycode == XK_Escape)
	{
		printf("\nupdated player pos: x: %d, y: %d\n",
			ctx->map_data->player_pos.pos_x,
			ctx->map_data->player_pos.pos_y);
		sl_free_all(ctx);
		exit(0);
	}
	return (0);
}

t_texture	sl_create_texture(t_ctx *ctx, char *texture_path)
{
	t_texture	new_texture;

	new_texture.data = mlx_xpm_file_to_image(ctx->mlx, texture_path,
			&(new_texture.width), &(new_texture.height));
	return (new_texture);
}

int	sl_init_textures(t_ctx *ctx)
{
	ctx->textures = malloc(sizeof(t_texture) * TEXTURE_COUNT);
	ctx->textures[WALL] = sl_create_texture(ctx, WALL_TEXTURE);
	ctx->textures[GROUND] = sl_create_texture(ctx, GROUND_TEXTURE);
	ctx->textures[PLAYER] = sl_create_texture(ctx, PLAYER_TEXTURE);
	return (0);
}

int	sl_render_tiles(t_ctx *ctx)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	y = 0;
	while (i < ctx->map_data->height)
	{
		j = 0;
		x = 0;
		while (j < ctx->map_data->width)
		{
			if (ctx->map_data->map[i][j] == WALL_CHAR)
				mlx_put_image_to_window(ctx->mlx,
					ctx->window, ctx->textures[0].data, x, y);
			if (ctx->map_data->map[i][j] == EMPTY_CHAR
				|| ctx->map_data->map[i][j] == PLAYER_CHAR)
				mlx_put_image_to_window(ctx->mlx,
					ctx->window, ctx->textures[1].data, x, y);
			if (ctx->map_data->player_pos.pos_x == j
				&& ctx->map_data->player_pos.pos_y == i)
				mlx_put_image_to_window(ctx->mlx,
					ctx->window, ctx->textures[2].data, x, y);
			x += ctx->textures[0].width;
			j++;
		}
		y += ctx->textures[0].height;
		i++;
	}
	return (0);
}
int	sl_move_to_direction(t_ctx *ctx, int direction)
{
	t_vec2	*player_pos;
	char	**map;

	map = ctx->map_data->map;
	player_pos = &(ctx->map_data->player_pos);
	if (direction == UP
		&& map[player_pos->pos_y - 1][player_pos->pos_x] != WALL_CHAR)
		player_pos->pos_y -= 1;
	if (direction == DOWN
		&& map[player_pos->pos_y + 1][player_pos->pos_x] != WALL_CHAR)
		player_pos->pos_y += 1;
	if (direction == LEFT
		&& map[player_pos->pos_y][player_pos->pos_x - 1] != WALL_CHAR)
		player_pos->pos_x -= 1;
	if (direction == RIGHT
		&& map[player_pos->pos_y][player_pos->pos_x + 1] != WALL_CHAR)
		player_pos->pos_x += 1;
	return (0);
}

int	sl_move_player(int kc, t_ctx *ctx)
{
	if (kc == XK_w || kc == XK_W)
		sl_move_to_direction(ctx, UP);
	if (kc == XK_a || kc == XK_A)
		sl_move_to_direction(ctx, LEFT);
	if (kc == XK_s || kc == XK_S)
		sl_move_to_direction(ctx, DOWN);
	if (kc == XK_d || kc == XK_D)
		sl_move_to_direction(ctx, RIGHT);
	return (0);
}

int	sl_handle_keypress(int keycode, t_ctx *ctx)
{
	sl_move_player(keycode, ctx);
	sl_close_window(keycode, ctx);
	return (0);
}

int	main(int ac, char **av)
{
	t_ctx		ctx;

	if (ac != 2)
		sl_error_exit(EXIT_FAILURE, "not enough arguments");
	ctx.map_data = sl_get_map_data(av[1]);
	ctx.mlx = mlx_init();
	ctx.window = mlx_new_window(ctx.mlx, ctx.map_data->width * 64,
			ctx.map_data->height * 64, "not_so_long");
	sl_init_textures(&ctx);
	mlx_loop_hook(ctx.mlx, sl_render_tiles, &ctx);
	mlx_key_hook(ctx.window, sl_handle_keypress, &ctx);
	mlx_hook(ctx.window, DestroyNotify, StructureNotifyMask, sl_free_all, &ctx);
	mlx_loop(ctx.mlx);
	sl_free_all(&ctx);
}
