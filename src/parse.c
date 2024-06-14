/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:40:13 by okoca             #+#    #+#             */
/*   Updated: 2024/06/14 11:40:32 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_count_char(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

t_map_data	*sl_parse_map(char **map)
{
	t_map_data	*map_data;
	int			i;

	i = 0;
	map_data = NULL;
	while (map[i] != NULL)
	{
		sl_count_char(map[i], 'C');
		i++;
	}
	return (map_data);
}
