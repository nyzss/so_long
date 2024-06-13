/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:48:22 by okoca             #+#    #+#             */
/*   Updated: 2024/06/13 16:15:32 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map_data	*sl_read_map(char *path)
{
	int			fd;
	t_map_data	*map_data;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		sl_error_exit(EXIT_FAILURE, "Map not found!");
	map_data = malloc(sizeof(t_map_data));
	return (map_data);
}