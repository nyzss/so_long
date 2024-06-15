/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:28:37 by okoca             #+#    #+#             */
/*   Updated: 2024/06/15 10:50:58 by okoca            ###   ########.fr       */
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

int	main(int ac, char **av)
{
	char		**map;
	t_map_data	*map_data;

	if (ac != 2)
		sl_error_exit(EXIT_FAILURE, "not enough arguments");
	sl_parse_arg(av[1]);
	map = sl_get_map(av[1]);
	sl_print_map(map);
	printf("\nmap link: %s\n", av[1]);
	sl_check_map(map);
	map_data = sl_get_data(map);
	free(map_data);
	sl_clear_map(map);
}
