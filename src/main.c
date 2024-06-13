/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:28:37 by okoca             #+#    #+#             */
/*   Updated: 2024/06/13 17:31:20 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	if (ac != 2)
		sl_error_exit(EXIT_FAILURE, "not enough arguments");
	sl_parse_arg(av[1]);
	char **map = sl_get_map(av[1]);
	int	i = 0;
	while (map[i] != NULL)
	{
		printf("line: %s", map[i]);
		free(map[i]);
		i++;
	}
	free(map);
	printf("hello: %s\n", av[1]);
}