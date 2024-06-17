/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:48:22 by okoca             #+#    #+#             */
/*   Updated: 2024/06/17 11:25:17 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_get_height(char *path)
{
	int		fd;
	char	buf;
	int		height;
	int		char_count;

	height = 1;
	char_count = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		sl_error_exit(EXIT_FAILURE, "Map not found!");
	while (read(fd, &buf, 1))
	{
		if (buf == '\n')
			height++;
		char_count++;
	}
	close(fd);
	if (char_count == 0 || buf == '\n')
		return (-1);
	return (height + 1);
}

char	**sl_fill_table(int fd, int height)
{
	char	*line;
	char	**table;
	int		i;

	i = 0;
	table = (char **)malloc(sizeof(char *) * (height));
	if (!table)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		table[i] = line;
		if (i + 1 == height && table[i] == NULL)
			break ;
		else if (i + 1 != height && table[i] == NULL)
			sl_clear_map(table);
		i++;
	}
	i = 0;
	while (table[i] && table[i][ft_strlen(table[i]) - 1] == '\n')
	{
		table[i][ft_strlen(table[i]) - 1] = '\0';
		i++;
	}
	return (table);
}

char	**sl_get_map(char *path)
{
	int		fd;
	char	**table;
	int		height;

	height = sl_get_height(path);
	if (height == -1)
		sl_error_exit(EXIT_FAILURE, "Map doesn't have enough characters!");
	fd = open(path, O_RDONLY);
	table = sl_fill_table(fd, height);
	close(fd);
	return (table);
}
