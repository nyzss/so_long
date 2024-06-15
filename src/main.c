/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:28:37 by okoca             #+#    #+#             */
/*   Updated: 2024/06/15 23:02:47 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_free_all(t_ctx *ctx)
{
	if (ctx->window)
		mlx_destroy_window(ctx->mlx, ctx->window);
	if (ctx->textures)
	{
		mlx_destroy_image(ctx->mlx, ctx->textures[0].data);
		mlx_destroy_image(ctx->mlx, ctx->textures[1].data);
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

int	close_window(int keycode, t_ctx *ctx)
{
	if (keycode == XK_Escape)
	{
		sl_free_all(ctx);
		exit(0);
	}
	return (0);
}

void	sl_render_tiles(t_ctx *ctx)
{
	int 		i;
	int 		j;
	int			x;
	int			y;

	ctx->textures = malloc(sizeof(t_texture) * 2);
	ctx->textures[0].data = mlx_xpm_file_to_image(ctx->mlx,
			"./textures/left.xpm",
			&(ctx->textures[0].width), &(ctx->textures[0].height));
	if (!(ctx->textures[0].data))
		return ;
	ctx->textures[1].data = mlx_xpm_file_to_image(ctx->mlx,
			"./textures/ground.xpm",
			&(ctx->textures[1].width), &(ctx->textures[1].height));
	if (!(ctx->textures[1].data))
		return ;
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
			else if (ctx->map_data->map[i][j] == EMPTY_CHAR)
				mlx_put_image_to_window(ctx->mlx,
					ctx->window, ctx->textures[1].data, x, y);
			x += ctx->textures[0].width;
			j++;
		}
		y += ctx->textures[0].height;
		i++;
	}
	printf("x + y; %d\n", x + y);
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
	sl_render_tiles(&ctx);
	mlx_key_hook(ctx.window, close_window, &ctx);
	mlx_hook(ctx.window, DestroyNotify, StructureNotifyMask, sl_free_all, &ctx);
	mlx_loop(ctx.mlx);
	sl_free_all(&ctx);
}
