/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:28:37 by okoca             #+#    #+#             */
/*   Updated: 2024/06/16 21:20:13 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_free_exit_helper(t_ctx *ctx)
{
	int	i;

	i = 0;
	if (ctx->textures)
	{
		while (i < TEXTURE_COUNT)
		{
			mlx_destroy_image(ctx->mlx, ctx->textures[i].data);
			i++;
		}
		free(ctx->textures);
	}
	return (0);
}

int	sl_free_exit(t_ctx *ctx)
{
	if (ctx->map_data)
	{
		sl_clear_map(ctx->map_data->filled_map);
		sl_clear_map(ctx->map_data->map);
		free(ctx->map_data->collectibles.values);
		free(ctx->map_data);
	}
	if (ctx->mlx)
	{
		sl_free_exit_helper(ctx);
		mlx_loop_end(ctx->mlx);
		if (ctx->window)
			mlx_destroy_window(ctx->mlx, ctx->window);
		mlx_destroy_display(ctx->mlx);
		free(ctx->mlx);
	}
	exit(0);
}

t_map_data	*sl_get_map_data(char *path)
{
	char		**map;
	t_map_data	*map_data;

	sl_parse_arg(path);
	map = sl_get_map(path);
	sl_check_map(map);
	map_data = sl_get_data(map);
	return (map_data);
}

t_ctx	sl_init_ctx(void)
{
	t_ctx	new_ctx;

	new_ctx.map_data = NULL;
	new_ctx.mlx = NULL;
	new_ctx.window = NULL;
	new_ctx.textures = NULL;
	new_ctx.movement_count = 0;
	return (new_ctx);
}

int	main(int ac, char **av)
{
	t_ctx		ctx;

	if (ac != 2)
		sl_error_exit(EXIT_FAILURE, "not enough arguments");
	ctx = sl_init_ctx();
	ctx.map_data = sl_get_map_data(av[1]);
	ctx.mlx = mlx_init();
	if (!ctx.mlx)
		sl_free_exit(&ctx);
	ctx.window = mlx_new_window(ctx.mlx, ctx.map_data->width * TEXTURE_PIXEL,
			ctx.map_data->height * TEXTURE_PIXEL, "not_so_long");
	if (sl_init_textures(&ctx) < 0)
		sl_free_exit(&ctx);
	sl_render_tiles(&ctx);
	mlx_key_hook(ctx.window, sl_handle_keypress, &ctx);
	mlx_hook(ctx.window, DestroyNotify,
		StructureNotifyMask, sl_free_exit, &ctx);
	mlx_loop(ctx.mlx);
	return (0);
}
