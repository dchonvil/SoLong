/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wind_mng.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 05:57:25 by dchonvil          #+#    #+#             */
/*   Updated: 2021/11/22 05:57:28 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include "solong.h"

void    wind_size(t_windmng *wind)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (wind->map[y])
        y++;
    while (wind->map[0][x])
        x++;
    wind->map_x = (x * 50) + 5;
    wind->map_y = (y * 50) + 5;
}

int load_icons(t_windmng *wind)
{
    int x;
    int y;

    x = 50;
    y = 50;
    wind->c_img = mlx_xpm_file_to_image(wind->mlx_id, "asts/txtr/knife.xpm", &x, &y);
    wind->e_img = mlx_xpm_file_to_image(wind->mlx_id, "asts/txtr/house.xpm", &x, &y);
    wind->p_img = mlx_xpm_file_to_image(wind->mlx_id, "asts/txtr/naruto.xpm", &x, &y);
    wind->s_img = mlx_xpm_file_to_image(wind->mlx_id, "asts/txtr/plant.xpm", &x, &y);
    wind->w_img = mlx_xpm_file_to_image(wind->mlx_id, "asts/txtr/tree.xpm", &x, &y);
    if (!(wind->c_img && wind->e_img && wind->p_img && wind->s_img && wind->w_img))
        return (0);
    return (1);
}

int wind_loop_hook(t_windmng *wind)
{
    close_wind(wind);
    return (1);
}

int wind_keyhook(int keycode, t_windmng *wind)
{
    if (keycode == ESCAPE)
        close_wind(wind);
    else if (keycode == UP || keycode == DOWN ||
             keycode == LEFT || keycode == RIGHT)
        treat_move(wind, keycode);
    else if (keycode == 65362 || keycode == 65364 ||
             keycode == 65361 || keycode == 65363)
        treat_move(wind, keycode);
    return (0);
}

void close_wind(t_windmng *wind)
{
    if (wind->c_img)
        mlx_destroy_image(wind->mlx_id, wind->c_img);
    if (wind->e_img)
        mlx_destroy_image(wind->mlx_id, wind->e_img);
    if (wind->p_img)
        mlx_destroy_image(wind->mlx_id, wind->p_img);
    if (wind->s_img)
        mlx_destroy_image(wind->mlx_id, wind->s_img);
    if (wind->w_img)
        mlx_destroy_image(wind->mlx_id, wind->w_img);
    mlx_clear_window(wind->mlx_id, wind->wind_id);
    mlx_destroy_window(wind->mlx_id, wind->wind_id);
    mlx_destroy_display(wind->mlx_id);
    mlx_loop_end(wind->mlx_id);
    free_map(wind->map);
    free(wind->mlx_id);
    exit(0);
}



