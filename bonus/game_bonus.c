/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:35:46 by dchonvil          #+#    #+#             */
/*   Updated: 2021/11/26 21:35:51 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include "solong_bonus.h"

void	sprite_anim(t_windmng *wind)
{
    int x;
    int y;

    x = 80;
    y = 80;
    wind->blk_img = mlx_xpm_file_to_image(wind->mlx_id,
        "asts/txtr/blkbkg.xpm", &x, &y);
    if (wind->blk_img)
    {
        wind->tmp_img = wind->p_img;
        wind->tmp2_img = wind->n_img;
        wind->p_img = wind->blk_img;
        wind->n_img = wind->blk_img;
        map_drawer(wind);
        mlx_destroy_image(wind->mlx_id, wind->blk_img);
        wind->p_img = wind->p2_img;
        wind->n_img = wind->n2_img;
        map_drawer(wind);
        wind->p_img = wind->tmp_img;
        wind->n_img = wind->tmp2_img;
    }
}

void	end_game(t_windmng *wind, int stat)
{
    if (stat == 1)
        ft_putstr_fd("Too bad ... You lost with ", 1);
    else
        ft_putstr_fd("Congratulations !!! You won with ", 1);
	ft_putnbr_fd(wind->p_move, 1);
    if (stat == 1)
        ft_putstr_fd(" movements =(\n", 1);
    else
        ft_putstr_fd(" movements ;)\n", 1);
    close_wind(wind);
}

void	check_move(t_windmng *wind, char c)
{
	if (c == 'U')
	{
		wind->move_x = wind->p_x;
		wind->move_y = wind->p_y - 1;
	}
	else if (c == 'D')
	{
		wind->move_x = wind->p_x;
		wind->move_y = wind->p_y + 1;
	}
	else if (c == 'L')
	{
		wind->move_x = wind->p_x - 1;
		wind->move_y = wind->p_y;
	}
	else if (c == 'R')
	{
		wind->move_x = wind->p_x + 1;
		wind->move_y = wind->p_y;
	}
}

void	c_icon(t_windmng *wind, char place)
{
    sprite_anim(wind);
    if (place == 'C' || place == '0')
	{
		if (place == 'C')
			wind->p_nb_c += 1;
		wind->map[wind->move_y][wind->move_x] = 'P';
		wind->map[wind->p_y][wind->p_x] = '0';
	}
	else if (place == 'E')
	{
		if (wind->p_nb_c < wind->total_c)
		{
            put_on_screen(wind, 0);
			return ;
		}
		else
			end_game(wind, 0);
	}
    else if (place == 'N')
        end_game(wind, 1);
	wind->p_move += 1;
	wind->p_x = wind->move_x;
	wind->p_y = wind->move_y;
    sprite_anim(wind);
    usleep(250000);
    map_drawer(wind);
}

void	treat_move(t_windmng *wind, int keycode)
{
	char	c;
	char	place;
	int		nb_move;

	c = '\0';
	nb_move = wind->p_move;
	if (keycode == UP || keycode == 65362)
		c = 'U';
	if (keycode == DOWN || keycode == 65364)
		c = 'D';
	if (keycode == LEFT || keycode == 65361)
		c = 'L';
	if (keycode == RIGHT || keycode == 65363)
		c = 'R';
	check_move(wind, c);
	place = wind->map[wind->move_y][wind->move_x];
	if (place != '1')
		c_icon(wind, place);
	if (nb_move != wind->p_move)
        put_on_screen(wind, 1);
}
