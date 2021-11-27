/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 07:09:16 by dchonvil          #+#    #+#             */
/*   Updated: 2021/11/25 20:29:14 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "solong.h"

void	end_game(t_windmng *wind)
{
	ft_putstr_fd("Congratulations !!! You won with ", 1);
	ft_putnbr_fd(wind->p_move, 1);
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
			ft_putstr_fd("You must collect all knives to finish\n", 1);
			return ;
		}
		else
			end_game(wind);
	}
	wind->p_move += 1;
	wind->p_x = wind->move_x;
	wind->p_y = wind->move_y;
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
	{
		ft_putstr_fd("You made ", 1);
		ft_putnbr_fd(wind->p_move, 1);
		ft_putstr_fd(" movements\n", 1);
	}
}
