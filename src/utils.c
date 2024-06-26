/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:54:01 by okoca             #+#    #+#             */
/*   Updated: 2024/06/16 20:41:50 by okoca            ###   ########.fr       */
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
	if (!array)
		return ;
	while (array[i] != NULL)
		free(array[i++]);
	free(array);
}

int	sl_strchr(char *str, int c)
{
	int				i;
	unsigned char	cast;

	i = 0;
	cast = (unsigned char) c;
	while (str[i])
	{
		if (str[i] == cast)
			return (i);
		i++;
	}
	if (str[i] == cast)
		return (i);
	return (0);
}

int	sl_next_strchr(char *str, int c)
{
	static int		i;
	unsigned char	cast;

	cast = (unsigned char) c;
	while (str[i])
	{
		if (str[i] == cast)
		{
			i++;
			return (i - 1);
		}
		i++;
	}
	if (str[i] == cast)
		return (i);
	return (0);
}
