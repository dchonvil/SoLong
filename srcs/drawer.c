/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 06:04:08 by dchonvil          #+#    #+#             */
/*   Updated: 2021/11/23 06:04:17 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"

void icons_drawer(t_windmng *wind, char icon, int j, int n)
{
    if (icon == '0')
        mlx_put_image_to_window(wind->mlx_id, wind->wind_id, wind->s_img, j, n);
    else if (icon == '1')
        mlx_put_image_to_window(wind->mlx_id, wind->wind_id, wind->w_img, j, n);
    else if (icon == 'C')
        mlx_put_image_to_window(wind->mlx_id, wind->wind_id, wind->c_img, j, n);
    else if (icon == 'E')
        mlx_put_image_to_window(wind->mlx_id, wind->wind_id, wind->e_img, j, n);
    else if (icon == 'P')
        mlx_put_image_to_window(wind->mlx_id, wind->wind_id, wind->p_img, j, n);
}

void    items_pos(t_windmng *wind, char icon, int c, int i)
{
    if (icon == 'P')
    {
        wind->p_x = i;
        wind->p_y = c;
    }
    else
        wind->nb_c += 1;
}

int map_drawer(t_windmng *wind)
{
    int c;
    int i;
    int j;
    int n;

    c = 0;
    i = 0;
    j = 5;
    n = 5;
    while (wind->map[c])
    {
        while (wind->map[c][i])
        {
            if (wind->map[c][i] == 'C' || (wind->map[c][i]) == 'P')
                items_pos(wind, wind->map[c][i], c, i);
            icons_drawer(wind, wind->map[c][i], j, n);
            i++;
            j += 50;
        }
        i = 0;
        j = 5;
        n += 50;
        c++;
    }
    return (0);
}
