/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:28:37 by okoca             #+#    #+#             */
/*   Updated: 2024/06/14 15:35:11 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char	**map;
	int		i;

	i = 0;
	map = sl_get_map(av[1]);
	if (ac != 2)
		sl_error_exit(EXIT_FAILURE, "not enough arguments");
	sl_parse_arg(av[1]);
	while (map[i] != NULL)
	{
		printf("line: %s\n", map[i]);
		i++;
	}
	printf("\nmap link: %s\n", av[1]);
	sl_check_map(map);
	sl_clear_map(map);
}
