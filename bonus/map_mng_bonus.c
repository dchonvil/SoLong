/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_mng_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 00:03:34 by dchonvil          #+#    #+#             */
/*   Updated: 2021/11/27 00:03:42 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

int	ud_walls(char **map, int *i, int c, int y)
{
	while (map[c][*i])
	{
		if (map[0][*i] != '1' || map[y - 1][*i] != '1')
			return (0);
		*i += 1;
	}
	return (1);
}

int	check_walls(char **map)
{
	int	c;
	int	i;
	int	x;
	int	y;

	c = 0;
	i = 0;
	x = 0;
	y = 0;
	while (map[y])
		y++;
	while (map[0][x])
		x++;
	if (x == y)
		return (0);
	while (map[c])
	{
		if (!ud_walls(map, &i, c, y))
			return (0);
		if (map[c][0] != '1' || map[c][i - 1] != '1' || i != x)
			return (0);
		i = 0;
		c++;
	}
	return (1);
}

int	check_map_config(char **map, int c, int i)
{
	if (map[c][i] != '0' && map[c][i] != '1' && map[c][i] != 'C' &&
			map[c][i] != 'E' && map[c][i] != 'N' && map[c][i] != 'P')
		return (0);
	return (1);
}

int	check_map_items(char **map, t_map_items *mi, int c, int i)
{
	if (map[c][i] == 'C')
		mi->c = 1;
	if (map[c][i] == 'E')
	{
		if (mi->e == 1)
			return (0);
		else
			mi->e = 1;
	}
	if (map[c][i] == 'P')
	{
		if (mi->p == 1)
			return (0);
		else
			mi->p = 1;
	}
	return (1);
}

int	check_map(char **map)
{
	int			c;
	int			i;
	t_map_items	mi;

	c = 0;
	i = 0;
	mi.c = 0;
	mi.e = 0;
	mi.p = 0;
	while (map[c])
	{
		while (map[c][i])
		{
			if (!check_map_config(map, c, i))
				return (0);
			if (!check_map_items(map, &mi, c, i))
				return (0);
			i++;
		}
		i = 0;
		c++;
	}
	if (!(mi.c && mi.e && mi.p))
		return (0);
	return (1);
}
