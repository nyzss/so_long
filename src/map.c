/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:48:22 by okoca             #+#    #+#             */
/*   Updated: 2024/06/13 17:33:01 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		sl_get_height(char *path)
{
	int		fd;
	char	buf;
	int		height;

	height = 1;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		sl_error_exit(EXIT_FAILURE, "Map not found!");
	while (read(fd, &buf, 1))
	{
		if (buf == '\n')
			height++;
	}
	close(fd);
	return (height);
}

char	**sl_get_map(char *path)
{
	char	*line;
	char	**table;
	int		i;
	int		fd;

	i = 0;
	table = (char **)malloc(sizeof(char *) * (sl_get_height(path)));
	fd = open(path, O_RDONLY);
	if (fd < 0)
		sl_error_exit(EXIT_FAILURE, "Map not found!");
	line = get_next_line(fd);
	while (line != NULL)
	{
		table[i] = line;
		line = get_next_line(fd);
		i++;
	}
	table[i] = NULL;
	close(fd);
	return (table);
}
