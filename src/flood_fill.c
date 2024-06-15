/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:30:44 by okoca             #+#    #+#             */
/*   Updated: 2024/06/15 10:00:11 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define FILL_CHAR 'F'

int	sl_handle_char(char *c)
{
	if (*c != FILL_CHAR && *c != WALL_CHAR
		&& *c != EXIT_CHAR && *c != COLLECTIBLE_CHAR)
	{
		*c = FILL_CHAR;
		return (1);
	}
	return (0);
}

void	sl_flood_fill(t_vec2 p_pos, char **arr)
{
	t_vec2	new_pos;

	if (sl_handle_char(&(arr[p_pos.pos_y][p_pos.pos_x])) == 0)
		return ;
	new_pos = (t_vec2){p_pos.pos_x, p_pos.pos_y - 1};
	sl_flood_fill(new_pos, arr);
	new_pos = (t_vec2){p_pos.pos_x, p_pos.pos_y + 1};
	sl_flood_fill(new_pos, arr);
	new_pos = (t_vec2){p_pos.pos_x - 1, p_pos.pos_y};
	sl_flood_fill(new_pos, arr);
	new_pos = (t_vec2){p_pos.pos_x + 1, p_pos.pos_y};
	sl_flood_fill(new_pos, arr);
}
