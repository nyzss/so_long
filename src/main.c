/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:28:37 by okoca             #+#    #+#             */
/*   Updated: 2024/06/14 23:03:17 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		printf("line: %s\n", map[i]);
		i++;
	}
}

t_vec2	sl_find_x(char **map)
{
	int	i;
	t_vec2 vec;

	i = 0;
	vec.pos_x = 0;
	vec.pos_y = 0;
	while (map[i])
	{
		if (sl_strchr(map[i], 'P') != 0)
		{
			vec.pos_x = sl_strchr(map[i], 'P');
			vec.pos_y = i;
			return (vec);
		}
		i++;
	}
	return (vec);
}

int	main(int ac, char **av)
{
	char	**map;
	t_vec2	player_pos;

	if (ac != 2)
		sl_error_exit(EXIT_FAILURE, "not enough arguments");
	sl_parse_arg(av[1]);
	map = sl_get_map(av[1]);
	sl_print_map(map);
	printf("\nmap link: %s\n", av[1]);
	sl_check_map(map);
	player_pos = sl_find_x(map);
	printf("pos_x: %d, pos_y: %d\n", player_pos.pos_x, player_pos.pos_y);
	sl_flood_fill(player_pos, map);
	sl_print_map(map);
	sl_clear_map(map);
}
