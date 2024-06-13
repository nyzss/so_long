/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:28:37 by okoca             #+#    #+#             */
/*   Updated: 2024/06/13 16:18:20 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	// t_map_data *map_data;
	// map_data = sl_read_map(av[1]);
	if (ac != 2)
		sl_error_exit(EXIT_FAILURE, "not enough arguments");
	sl_parse_arg(av[1]);
	int fd = open(av[1], O_RDONLY);
	if (fd < 0)
		sl_error_exit(EXIT_FAILURE, "wrong file");
	char *line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	printf("hello: %s\n", av[1]);
}