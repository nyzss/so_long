/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:53:15 by okoca             #+#    #+#             */
/*   Updated: 2024/06/16 16:59:48 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	ctx->textures[COLLECTIBLE] = sl_create_texture(ctx, COLLECTIBLE_TEXTURE);
	ctx->textures[EXIT] = sl_create_texture(ctx, EXIT_TEXTURE);
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
					ctx->window, ctx->textures[WALL].data, x, y);
			if (ctx->map_data->map[i][j] == EMPTY_CHAR
				|| ctx->map_data->map[i][j] == PLAYER_CHAR)
				mlx_put_image_to_window(ctx->mlx,
					ctx->window, ctx->textures[GROUND].data, x, y);
			if (ctx->map_data->map[i][j] == COLLECTIBLE_CHAR)
				mlx_put_image_to_window(ctx->mlx,
					ctx->window, ctx->textures[COLLECTIBLE].data, x, y);
			if (ctx->map_data->map[i][j] == EXIT_CHAR)
				mlx_put_image_to_window(ctx->mlx,
					ctx->window, ctx->textures[EXIT].data, x, y);
			if (ctx->map_data->player_pos.pos_x == j
				&& ctx->map_data->player_pos.pos_y == i)
				mlx_put_image_to_window(ctx->mlx,
					ctx->window, ctx->textures[PLAYER].data, x, y);
			x += ctx->textures[0].width;
			j++;
		}
		y += ctx->textures[0].height;
		i++;
	}
	return (0);
}
