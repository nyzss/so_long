/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:57:54 by okoca             #+#    #+#             */
/*   Updated: 2024/06/16 18:32:27 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_handle_keypress(int keycode, t_ctx *ctx)
{
	if (keycode == XK_Escape)
		sl_free_exit(ctx);
	sl_move_player(keycode, ctx);
	return (0);
}

int	sl_check_if_on_collectibles(t_ctx *ctx, t_vec2 player)
{
	int	i;

	i = 0;
	while (i < ctx->map_data->collectibles.count)
	{
		if (player.x == ctx->map_data->collectibles.values[i].x)
		{
			if (player.y == ctx->map_data->collectibles.values[i].y)
			{
				ctx->map_data->collectibles.values[i].collected = 1;
				ctx->map_data->collectibles.collected += 1;
			}
		}
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
		&& map[player_pos->y - 1][player_pos->x] != WALL_CHAR)
		player_pos->y -= 1;
	if (direction == DOWN
		&& map[player_pos->y + 1][player_pos->x] != WALL_CHAR)
		player_pos->y += 1;
	if (direction == LEFT
		&& map[player_pos->y][player_pos->x - 1] != WALL_CHAR)
		player_pos->x -= 1;
	if (direction == RIGHT
		&& map[player_pos->y][player_pos->x + 1] != WALL_CHAR)
		player_pos->x += 1;
	sl_check_if_on_collectibles(ctx, *player_pos);
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
