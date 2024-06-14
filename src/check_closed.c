/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:41:48 by okoca             #+#    #+#             */
/*   Updated: 2024/06/14 15:49:20 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_check_top(char **arr)
{
	int	i;

	i = 0;
	while (arr[0][i])
	{
		if (arr[0][i] != WALL_CHAR)
			return (1);
		i++;
	}
	return (0);
}

int	sl_check_bottom(int column, char **arr)
{
	int	i;

	i = 0;
	column -= 1;
	while (arr[column][i])
	{
		if (arr[column][i] != WALL_CHAR)
			return (1);
		i++;
	}
	return (0);
}

int	sl_check_left(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] && arr[i][0])
	{
		if (arr[i][0] != WALL_CHAR)
			return (1);
		i++;
	}
	return (0);
}

int	sl_check_right(int row, char **arr)
{
	int	i;

	i = 0;
	row -= 1;
	while (arr[i] && arr[i][row])
	{
		if (arr[i][row] != WALL_CHAR)
			return (1);
		i++;
	}
	return (0);
}

int	sl_check_if_closed(char **arr)
{
	int	row;
	int	column;

	row = 0;
	column = 0;
	while (arr[column] != NULL)
		column++;
	while (arr[0][row])
		row++;
	if (sl_check_top(arr) == 1)
		return (1);
	if (sl_check_bottom(column, arr) == 1)
		return (1);
	if (sl_check_left(arr) == 1)
		return (1);
	if (sl_check_right(row, arr) == 1)
		return (1);
	return (0);
}
