/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:54:01 by okoca             #+#    #+#             */
/*   Updated: 2024/06/14 13:46:24 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_error_exit(int code, char *message)
{
	ft_fprintf(STDERR_FILENO, "Error\n%s\n", message);
	exit(code);
}

void	sl_parse_arg(char *arg)
{
	int		arg_size;

	arg_size = ft_strlen(arg);
	if (arg_size <= 4)
		sl_error_exit(EXIT_FAILURE, "Please enter a valid map.");
	if (ft_strncmp(arg + arg_size - 4, ".ber", 4) != 0)
		sl_error_exit(EXIT_FAILURE, "Please enter a valid map.");
	return ;
}

void	sl_clear_map(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		free(array[i++]);
	free(array);
}
