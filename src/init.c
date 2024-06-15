/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 09:42:47 by okoca             #+#    #+#             */
/*   Updated: 2024/06/15 15:39:08 by okoca            ###   ########.fr       */
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

t_vec2	sl_find_next_pos(char **map, char c, int reset)
{
	static int	i;
	static int	j;
	t_vec2		vec;

	vec = (t_vec2){0, 0};
	if (reset == TRUE)
	{
		i = 0;
		return (vec);
	}
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == c)
			{
				vec = (t_vec2){j, i};
				return (j++, vec);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (vec);
}

t_map_data	*sl_get_data(char **map)
{
	t_vec2		player_pos;
	t_map_data	*map_data;
	char		**filled_arr;

	map_data = malloc(sizeof(t_map_data));
	player_pos = sl_find_pos(map, PLAYER_CHAR);
	printf("pos_x: %d, pos_y: %d\n", player_pos.pos_x, player_pos.pos_y);
	filled_arr = sl_get_filled_map(player_pos, map);
	printf("Real map: \n");
	sl_print_map(map);
	printf("Copy map: \n");
	sl_print_map(filled_arr);
	sl_clear_map(filled_arr);

	t_collectibles collectibles = sl_get_all_collectibles(map, TRUE);
	int	i = 0;
	while (i < collectibles.count)
	{
		printf("collectible: %d\nx: %d, y: %d\n", i,
			 collectibles.values[i].pos_x, collectibles.values[i].pos_y);
		i++;
	}
	free(collectibles.values);
	return (map_data);
}
