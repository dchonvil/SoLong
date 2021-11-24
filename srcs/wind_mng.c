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

void close_wind(t_windmng *wind)
{
    ft_putstr_fd("Exit\n", 1);

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

    //mlx_clear_window(wind->mlx_id, wind->wind_id);
    mlx_destroy_window(wind->mlx_id, wind->wind_id);
    mlx_loop_end(wind->mlx_id);
    free_map(wind->map);
    free(wind->mlx_id);
    ft_putstr_fd("Ok, TED\n", 1);
    exit(0);
}

/*
void wind_loop_hook(t_windmng *wind)
{
    ft_putnbr_fd(keycode, 1);
    ft_putstr_fd("\n", 1);
    if (keycode == 65307)
        close_wind(wind);
}

void wind_expose_hook(t_windmng *wind)
{
    ft_putnbr_fd(keycode, 1);
    ft_putstr_fd("\n", 1);
    if (keycode == 65307)
        close_wind(wind);
}
 */

void wind_keyhook(int keycode, t_windmng *wind)
{
    ft_putnbr_fd(keycode, 1);
    ft_putstr_fd("\n", 1);
    if (keycode == ESCAPE)
        close_wind(wind);
    else if (keycode == UP || keycode == DOWN ||
        keycode == LEFT || keycode == RIGHT)
        treat_move(wind, keycode);
    else if (keycode == 65362 || keycode == 65364 ||
             keycode == 65361 || keycode == 65363)
        treat_move(wind, keycode);
}

void wind_mousehook(int button, int x, int y, t_windmng *wind)
{
    if (button == -1)
    {
        close_wind(wind);
    }
}
