/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:28:37 by okoca             #+#    #+#             */
/*   Updated: 2024/06/16 17:08:51 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_free_all(t_ctx *ctx)
{
	int	i;

	i = 0;
	mlx_loop_end(ctx->mlx);
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

int	main(int ac, char **av)
{
	t_ctx		ctx;

	if (ac != 2)
		sl_error_exit(EXIT_FAILURE, "not enough arguments");
	ctx.map_data = sl_get_map_data(av[1]);
	ctx.mlx = mlx_init();
	ctx.window = mlx_new_window(ctx.mlx, ctx.map_data->width * TEXTURE_PIXEL,
			ctx.map_data->height * TEXTURE_PIXEL, "not_so_long");
	sl_init_textures(&ctx);
	mlx_loop_hook(ctx.mlx, sl_render_tiles, &ctx);
	mlx_key_hook(ctx.window, sl_handle_keypress, &ctx);
	mlx_hook(ctx.window, DestroyNotify, StructureNotifyMask, sl_free_all, &ctx);
	mlx_loop(ctx.mlx);
	sl_free_all(&ctx);
}
