/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:44:09 by okoca             #+#    #+#             */
/*   Updated: 2024/06/15 17:52:41 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_debug(t_map_data *map)
{
	int	i;

	i = 0;
	ft_printf("pos_x: %d, pos_y: %d\n",
		map->player_pos.pos_x, map->player_pos.pos_y);
	ft_printf("Real map: \n");
	sl_print_map(map->map);
	ft_printf("Filled map: \n");
	sl_print_map(map->filled_map);
	while (i < map->collectibles.count)
	{
		ft_printf("collectible: %d -> x: %d, y: %d\n", i,
			map->collectibles.values[i].pos_x,
			map->collectibles.values[i].pos_y);
		i++;
	}
	ft_printf("player_pos -> x: %d, y: %d\n",
		map->player_pos.pos_x, map->player_pos.pos_y);
	ft_printf("exit_pos -> x: %d, y: %d\n",
		map->exit_pos.pos_x, map->exit_pos.pos_y);
	ft_printf("map info ->  height: %d, width: %d\n", map->height, map->width);
}