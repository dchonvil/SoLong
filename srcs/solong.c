/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 01:24:41 by dchonvil          #+#    #+#             */
/*   Updated: 2021/11/25 20:47:23 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "solong.h"
#include <stdlib.h>

void	free_map(char **map)
{
	int	c;

	c = 0;
	while (map[c])
	{
		free(map[c]);
		c++;
	}
	free(map);
}

int	check_arg(int ac, char **av)
{
	int	c;

	c = 0;
	if (ac != 2)
	{
		if (ac < 2)
			ft_putstr_fd("Error: Argument needed.\n", 1);
		if (ac > 2)
			ft_putstr_fd("Error : Only one argument expected.\n", 1);
		ft_putstr_fd("Usage: ./so_long [map.ber]\n", 1);
		return (0);
	}
	while (av[1][c])
		c++;
	if (av[1][c - 4] != '.' && av[1][c - 3] != 'b'
			&& av[1][c - 2] != 'e' && av[1][c - 1] != 'r')
	{
		ft_putstr_fd("Error: The used file is not a .ber.\n", 1);
		return (0);
	}
	return (1);
}

int	wind_init(char **map, t_windmng *wind)
{
	wind->map = map;
	wind->mlx_id = mlx_init();
	if (!wind->mlx_id)
		return (0);
	wind_size(wind);
	wind->wind_id = mlx_new_window(wind->mlx_id,
			wind->map_x, wind->map_y, "Naruto Rush");
	if (!wind->wind_id)
		return (0);
	if (!load_icons(wind))
	{
		ft_putstr_fd("Error loading images.\n", 1);
		close_wind(wind);
	}
	wind->nb_c = 0;
	wind->p_move = 0;
	wind->p_nb_c = 0;
	map_drawer(wind);
	wind->total_c = wind->nb_c;
	return (1);
}

int	game_init(char **map)
{
	t_windmng	wind;

	if (!wind_init(map, &wind))
	{
		ft_putstr_fd("Error init game.\n", 1);
		free_map(map);
		return (0);
	}
	mlx_hook(wind.wind_id, 33, 1L << 17, wind_loop_hook, &wind);
	mlx_hook(wind.wind_id, 12, 1L << 15, map_drawer, &wind);
	mlx_key_hook(wind.wind_id, wind_keyhook, &wind);
	mlx_loop(wind.mlx_id);
	return (1);
}

int	main(int ac, char **av)
{
	char	**map;

	if (!check_arg(ac, av))
		return (1);
	map = treat_file(av[1]);
	if (!map)
		return (1);
	if (!map_control(map))
	{
		free_map(map);
		return (1);
	}
	if (!game_init(map))
		return (1);
	return (0);
}
