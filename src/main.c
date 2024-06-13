/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:28:37 by okoca             #+#    #+#             */
/*   Updated: 2024/06/13 15:00:47 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_parse_arg(char *arg)
{
	int		arg_size;

	arg_size = ft_strlen(arg);
	if (arg_size <= 4)
		sl_error_exit(EXIT_FAILURE, "Please enter a valid map.");
	if (ft_strncmp(arg + arg_size - 4, ".ber", 4) != 0)
		sl_error_exit(EXIT_FAILURE, "Please enter a valid map.");
}
int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("not enough arguments\n");
		return (0);
	}
	sl_parse_arg(av[1]);
	printf("hello: %s\n", av[1]);
}