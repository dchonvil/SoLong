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
    //mlx_pixel_put(ids[0], ids[1], 100, 50, 0xFFFFFF);

    wind->c_img = mlx_xpm_file_to_image(wind->mlx_id, "txtr/knife.xpm", &x, &y);
    wind->e_img = mlx_xpm_file_to_image(wind->mlx_id, "txtr/house.xpm", &x, &y);
    wind->p_img = mlx_xpm_file_to_image(wind->mlx_id, "txtr/naruto.xpm", &x, &y);
    wind->s_img = mlx_xpm_file_to_image(wind->mlx_id, "txtr/plant.xpm", &x, &y);
    wind->w_img = mlx_xpm_file_to_image(wind->mlx_id, "txtr/tree.xpm", &x, &y);

    if (!(wind->c_img && wind->e_img && wind->p_img && wind->s_img && wind->w_img))
    {
        ft_putstr_fd("Image KO\n", 1);
        return (0);
    }
    return (1);
}

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

void map_drawer(t_windmng *wind)
{
    int c;
    int i;
    int j;
    int n;

    c = 0;
    i = 0;
    j = 5;
    n = 5;
    wind->nb_c = 0;
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
    ft_putnbr_fd(wind->nb_c, 1);
    ft_putstr_fd(" kNIVES\n", 1);
}
