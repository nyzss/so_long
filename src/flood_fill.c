/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:30:44 by okoca             #+#    #+#             */
/*   Updated: 2024/06/14 23:07:34 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define FILL_CHAR 'F'

int	sl_handle_char(char *c)
{
	if (*c != FILL_CHAR && *c != WALL_CHAR)
	{
		*c = 'F';
		return (1);
	}
	return (0);
}

// int	sl_handle_down(char *c)
// {
// 	if (*c != FILL_CHAR && *c != WALL_CHAR)
// 	{
// 		*c = 'F';
// 		return (1);
// 	}
// 	return (0);
// }

// int	sl_handle_left(char *c)
// {
// 	if (*c != FILL_CHAR && *c != WALL_CHAR)
// 	{
// 		*c = 'F';
// 		return (1);
// 	}
// 	return (0);
// }

// int	sl_handle_right(char *c)
// {
// 	if (*c != FILL_CHAR && *c != WALL_CHAR)
// 	{
// 		*c = 'F';
// 		return (1);
// 	}
// 	return (0);
// }

void	sl_flood_fill(t_vec2 p_pos, char **arr)
{
	if (sl_handle_char(&(arr[p_pos.pos_y][p_pos.pos_x + 1])) == 1)
	{
		p_pos.pos_x += 1;
		sl_flood_fill(p_pos, arr);
	}
	if (sl_handle_char(&(arr[p_pos.pos_y][p_pos.pos_x - 1])) == 1)
	{
		p_pos.pos_x -= 1;
		sl_flood_fill(p_pos, arr);
	}
	if (sl_handle_char(&(arr[p_pos.pos_y + 1][p_pos.pos_x])) == 1)
	{
		p_pos.pos_y += 1;
		sl_flood_fill(p_pos, arr);
	}
	if (sl_handle_char(&(arr[p_pos.pos_y - 1][p_pos.pos_x])) == 1)
	{
		p_pos.pos_y -= 1;
		sl_flood_fill(p_pos, arr);
	}
}