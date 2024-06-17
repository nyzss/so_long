/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:30:44 by okoca             #+#    #+#             */
/*   Updated: 2024/06/17 09:51:23 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_handle_char(char *c)
{
	if (*c != FILL_CHAR && *c != WALL_CHAR
		&& *c != EXIT_CHAR)
	{
		*c = FILL_CHAR;
		return (1);
	}
	return (0);
}

void	sl_flood_fill(t_vec2 p_pos, char **arr)
{
	t_vec2	new_pos;

	if (sl_handle_char(&(arr[p_pos.y][p_pos.x])) == 0)
		return ;
	new_pos = (t_vec2){p_pos.x, p_pos.y - 1, 0};
	sl_flood_fill(new_pos, arr);
	new_pos = (t_vec2){p_pos.x, p_pos.y + 1, 0};
	sl_flood_fill(new_pos, arr);
	new_pos = (t_vec2){p_pos.x - 1, p_pos.y, 0};
	sl_flood_fill(new_pos, arr);
	new_pos = (t_vec2){p_pos.x + 1, p_pos.y, 0};
	sl_flood_fill(new_pos, arr);
}

char	**sl_get_filled_map(t_vec2 p_pos, char **arr)
{
	int		i;
	int		column;
	char	**filled_arr;

	i = 0;
	column = 0;
	while (arr[column])
		column++;
	filled_arr = (char **)malloc(sizeof(char *) * (column + 1));
	if (!filled_arr)
		sl_clear_map(arr);
	while (i < column)
	{
		filled_arr[i] = ft_strdup(arr[i]);
		i++;
	}
	filled_arr[i] = NULL;
	sl_flood_fill(p_pos, filled_arr);
	return (filled_arr);
}
