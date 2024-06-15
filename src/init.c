/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 09:42:47 by okoca             #+#    #+#             */
/*   Updated: 2024/06/15 10:00:23 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vec2	sl_find_pos(char **map, char c)
{
	int		i;
	t_vec2	vec;

	i = 0;
	vec.pos_x = 0;
	vec.pos_y = 0;
	while (map[i])
	{
		if (sl_strchr(map[i], c) != 0)
		{
			vec.pos_x = sl_strchr(map[i], c);
			vec.pos_y = i;
			return (vec);
		}
		i++;
	}
	return (vec);
}

t_map_data	*sl_get_data(char **map)
{
	t_vec2		player_pos;
	t_map_data	*map_data;

	// map_data = malloc(sizeof(t_map_data));
	map_data = NULL;
	player_pos = sl_find_pos(map, PLAYER_CHAR);
	printf("pos_x: %d, pos_y: %d\n", player_pos.pos_x, player_pos.pos_y);
	sl_flood_fill(player_pos, map);
	sl_print_map(map);
	return (map_data);
}
