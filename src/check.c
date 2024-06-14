/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:16:54 by okoca             #+#    #+#             */
/*   Updated: 2024/06/14 16:09:50 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_check_invalid_char(char **arr)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			c = arr[i][j];
			if (c != '0' && c != '1' && c != 'C' && c != 'E'
				&& c != 'P' && c != '\n')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	sl_check_rectangular(char **arr)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (arr[i])
	{
		if ((int)ft_strlen(arr[i]) > len)
			len = (int)ft_strlen(arr[i]);
		i++;
	}
	i = 0;
	while (arr[i])
	{
		if (len != (int)ft_strlen(arr[i]))
			return (1);
		i++;
	}
	return (0);
}

int	sl_check_max_char(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			j++;
		}
		i++;
	}
	return (0);
}

void	sl_check_map(char **arr)
{
	if (sl_check_invalid_char(arr) != 0)
	{
		sl_clear_map(arr);
		sl_error_exit(EXIT_FAILURE, "Invalid character in map.");
	}
	else if (sl_check_rectangular(arr) != 0)
	{
		sl_clear_map(arr);
		sl_error_exit(EXIT_FAILURE, "Map is not rectangular.");
	}
	else if (sl_check_if_closed(arr) != 0)
	{
		sl_clear_map(arr);
		sl_error_exit(EXIT_FAILURE, "Map is not closed by walls.");
	}
	else if (sl_check_max_char(arr) != 0)
	{
		sl_clear_map(arr);
		sl_error_exit(EXIT_FAILURE, "Map is not rectangular.");
	}
}
