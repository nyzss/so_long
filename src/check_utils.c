/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 10:41:33 by okoca             #+#    #+#             */
/*   Updated: 2024/06/15 10:43:43 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_get_count(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	sl_check_if_path(t_vec2 pos, char **filled_map)
{
	if (filled_map[pos.pos_y][pos.pos_x + 1] != FILL_CHAR
		&& filled_map[pos.pos_y][pos.pos_x - 1] != FILL_CHAR
		&& filled_map[pos.pos_y + 1][pos.pos_x] != FILL_CHAR
		&& filled_map[pos.pos_y - 1][pos.pos_x] != FILL_CHAR)
		return (1);
	return (0);
}