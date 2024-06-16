/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:53:15 by okoca             #+#    #+#             */
/*   Updated: 2024/06/16 21:20:49 by okoca            ###   ########.fr       */
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
	if (!ctx->textures)
		return (-1);
	ctx->textures[WALL] = sl_create_texture(ctx, WALL_TEXTURE);
	ctx->textures[GROUND] = sl_create_texture(ctx, GROUND_TEXTURE);
	ctx->textures[PLAYER] = sl_create_texture(ctx, PLAYER_TEXTURE);
	ctx->textures[COLLECTIBLE] = sl_create_texture(ctx, COLLECTIBLE_TEXTURE);
	ctx->textures[EXIT] = sl_create_texture(ctx, EXIT_TEXTURE);
	return (0);
}

void	sl_render_collectibles(t_ctx *ctx, int i, int j)
{
	int	k;
	int	x;
	int	y;

	k = 0;
	x = j * TEXTURE_PIXEL;
	y = i * TEXTURE_PIXEL;
	while (k < ctx->map_data->collectibles.count)
	{
		if (ctx->map_data->collectibles.values[k].x == j
			&& ctx->map_data->collectibles.values[k].y == i
			&& ctx->map_data->collectibles.values[k].collected == 0)
		{
			mlx_put_image_to_window(ctx->mlx,
				ctx->window, ctx->textures[COLLECTIBLE].data, x, y);
		}
		k++;
	}
}

void	sl_render_single(t_ctx *ctx, int i, int j, int track)
{
	int		x;
	int		y;

	x = j * TEXTURE_PIXEL;
	y = i * TEXTURE_PIXEL;
	if (ctx->map_data->map[i][j] != WALL_CHAR
		&& ctx->map_data->map[i][j] != EXIT_CHAR)
		mlx_put_image_to_window(ctx->mlx,
			ctx->window, ctx->textures[GROUND].data, x, y);
	if (track == 0)
	{
		if (ctx->map_data->map[i][j] == WALL_CHAR)
			mlx_put_image_to_window(ctx->mlx,
				ctx->window, ctx->textures[WALL].data, x, y);
		if (ctx->map_data->map[i][j] == EXIT_CHAR)
			mlx_put_image_to_window(ctx->mlx,
				ctx->window, ctx->textures[EXIT].data, x, y);
	}
	sl_render_collectibles(ctx, i, j);
	if (ctx->map_data->player_pos.x == j
		&& ctx->map_data->player_pos.y == i)
		mlx_put_image_to_window(ctx->mlx,
			ctx->window, ctx->textures[PLAYER].data, x, y);
}

int	sl_render_tiles(t_ctx *ctx)
{
	int			i;
	int			j;
	static int	track_render;

	i = 0;
	while (i < ctx->map_data->height)
	{
		j = 0;
		while (j < ctx->map_data->width)
		{
			sl_render_single(ctx, i, j, track_render);
			j++;
		}
		i++;
	}
	track_render = 1;
	return (0);
}
