/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:29:12 by okoca             #+#    #+#             */
/*   Updated: 2024/06/14 11:31:08 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# include "mlx.h"
# include "libft.h"

typedef struct s_map_data
{
	int	player_count;
	int	collectibles;
	int	exit;
	int	height;
	int	width;
}	t_map_data;

void	sl_error_exit(int code, char *message);

void	sl_parse_arg(char *arg);

char	**sl_get_map(char *path);

int		sl_get_height(char *path);

void	sl_clear_map(char **array);

int		sl_count_char(char *str, char c);

void	sl_check_map(char **arr);

int		sl_strlen(char *str);

#endif