/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 01:24:41 by dchonvil          #+#    #+#             */
/*   Updated: 2021/11/18 01:24:48 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include "solong.h"

void wind_init(char **map)
{
    t_windmng wind;
    void *wkh = &wind_keyhook;
    void *wmh = &wind_mousehook;

    wind.map = map;
    wind.mlx_id = mlx_init();
    wind_size(&wind);
    wind.wind_id = mlx_new_window(wind.mlx_id, wind.map_x, wind.map_y, "Naruto Rush");
    if (!load_icons(&wind))
    {
        ft_putstr_fd("Error loading images\n", 1);
        close_wind(&wind);
    }
    wind.nb_c = 0;
    wind.p_move = 0;
    wind.p_nb_c = 0;
    map_drawer(&wind);
    wind.total_c = wind.nb_c;
    mlx_key_hook(wind.wind_id, wkh, &wind);
    mlx_mouse_hook(wind.wind_id, wmh, &wind);
    mlx_expose_hook(wind.wind_id, wkh, &wind);
    mlx_loop_hook(wind.wind_id, wmh, &wind);
    mlx_loop(wind.mlx_id);



}

int main(int ac, char **av)
{
    char **map;

    if (!check_arg(ac, av))
        return (1);
    map = treat_file(av[1]);
    if (!map)
        return (1);
    if (!map_control(map))
        return (1);
    //free_map(map);
    wind_init(map);
    return (0);
}