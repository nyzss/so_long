/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:44:09 by okoca             #+#    #+#             */
/*   Updated: 2024/06/15 15:55:27 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_debug(t_map_data *map)
{
	int	i;

	i = 0;
	printf("pos_x: %d, pos_y: %d\n",
		map->player_pos.pos_x, map->player_pos.pos_y);
	printf("Real map: \n");
	sl_print_map(map->map);
	printf("Copy map: \n");
	sl_print_map(map->filled_map);
	while (i < map->collectibles.count)
	{
		printf("collectible: %d\nx: %d, y: %d\n", i,
			map->collectibles.values[i].pos_x,
			map->collectibles.values[i].pos_y);
		i++;
	}
}