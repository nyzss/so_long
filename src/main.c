/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:28:37 by okoca             #+#    #+#             */
/*   Updated: 2024/06/15 20:58:14 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_free_all(t_ctx *ctx)
{
	if (ctx->window)
		mlx_destroy_window(ctx->mlx, ctx->window);
	if (ctx->image)
		mlx_destroy_image(ctx->mlx, ctx->image);
	mlx_loop_end(ctx->mlx);
	mlx_destroy_display(ctx->mlx);
	free(ctx->map_data->collectibles.values);
	sl_clear_map(ctx->map_data->map);
	sl_clear_map(ctx->map_data->filled_map);
	free(ctx->map_data);
	free(ctx->mlx);
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

int	main(int ac, char **av)
{
	t_ctx		ctx;
	int			img_height;
	int			img_width;

	if (ac != 2)
		sl_error_exit(EXIT_FAILURE, "not enough arguments");
	ctx.map_data = sl_get_map_data(av[1]);
	ctx.mlx = mlx_init();
	ctx.window = mlx_new_window(ctx.mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, "not_so_long");
	ctx.image = NULL;
	ctx.image = mlx_xpm_file_to_image(ctx.mlx, "./test.xpm",
			&img_width, &img_height);
	if (ctx.image)
		mlx_put_image_to_window(ctx.mlx, ctx.window, ctx.image, 0, 0);
	mlx_key_hook(ctx.window, close_window, &ctx);
	mlx_loop(ctx.mlx);
	sl_free_all(&ctx);
}
