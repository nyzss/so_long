/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:16:54 by okoca             #+#    #+#             */
/*   Updated: 2024/06/15 09:57:46 by okoca            ###   ########.fr       */
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

int	sl_get_count(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	sl_check_max_char(char **arr)
{
	if (sl_get_count(arr, PLAYER_CHAR) != 1)
		return (1);
	else if (sl_get_count(arr, EXIT_CHAR) != 1)
		return (1);
	else if (sl_get_count(arr, COLLECTIBLE_CHAR) < 1)
		return (1);
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
		sl_error_exit(EXIT_FAILURE, "Map contains more than 1 player or exit.");
	}
}
