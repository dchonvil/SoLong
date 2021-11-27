/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:34:50 by dchonvil          #+#    #+#             */
/*   Updated: 2021/11/26 21:34:56 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include <stdlib.h>
#include "solong_bonus.h"

int     ft_get_color(int t, int r, int g, int b)
{
    return (t << 24 | r << 16 | g << 8 | b);
}

void	put_on_screen(t_windmng *wind, int c)
{
    int blk;
    int wht;
    char *n;
    char *mn;

    n = NULL;
    mn = NULL;
    blk = ft_get_color(0, 0, 0, 0);
    wht = ft_get_color(0, 255, 255, 255);
    if (c == 1)
    {
        n = ft_itoa(wind->p_move);
        mn = ft_itoa((wind->p_move - 1));
        mlx_string_put(wind->mlx_id, wind->wind_id, 5, (wind->map_y + 10)
            , blk, mn);
        mlx_string_put(wind->mlx_id, wind->wind_id, 5, (wind->map_y + 10)
            , wht, n);
        mlx_string_put(wind->mlx_id, wind->wind_id, 25, (wind->map_y + 10)
            , wht, "movement(s)");
        free(n);
        free(mn);
    }
    else
        mlx_string_put(wind->mlx_id, wind->wind_id, (wind->map_x / 2)
           , (wind->map_y + 10), wht, "You must collect all knives to finish");
}

void	icons_drawer(t_windmng *wind, char icon, int j, int n)
{
	if (icon == '0')
		mlx_put_image_to_window(wind->mlx_id, wind->wind_id, wind->s_img, j, n);
	else if (icon == '1')
		mlx_put_image_to_window(wind->mlx_id, wind->wind_id, wind->w_img, j, n);
	else if (icon == 'C')
		mlx_put_image_to_window(wind->mlx_id, wind->wind_id, wind->c_img, j, n);
	else if (icon == 'E')
		mlx_put_image_to_window(wind->mlx_id, wind->wind_id, wind->e_img, j, n);
    else if (icon == 'N')
        mlx_put_image_to_window(wind->mlx_id, wind->wind_id, wind->n_img, j, n);
    else if (icon == 'P')
        mlx_put_image_to_window(wind->mlx_id, wind->wind_id, wind->p_img, j, n);
}

void	items_pos(t_windmng *wind, char icon, int c, int i)
{
	if (icon == 'P')
	{
		wind->p_x = i;
		wind->p_y = c;
	}
	else
		wind->nb_c += 1;
}

int	map_drawer(t_windmng *wind)
{
    int	c;
	int	i;
	int	j;
	int	n;

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
