/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 06:08:52 by dchonvil          #+#    #+#             */
/*   Updated: 2021/11/25 21:06:53 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define ESCAPE 65307

typedef struct s_map_items
{
	int	c;
	int	e;
	int	p;
}	t_map_items;

typedef struct s_windmng
{
	int		p_x;
	int		p_y;
	int		nb_c;
	int		map_x;
	int		map_y;
	char	**map;
	int		p_move;
	int		move_x;
	int		move_y;
	int		p_nb_c;
	int		total_c;
	void	*c_img;
	void	*e_img;
	void	*p_img;
	void	*s_img;
	void	*w_img;
	void	*mlx_id;
	void	*wind_id;
}	t_windmng;

void	free_map(char **map);
int		check_map(char **map);
int		check_walls(char **map);
int		map_control(char **map);
char	**treat_file(char *file);
void	wind_size(t_windmng *wind);
int		load_icons(t_windmng *wind);
int		map_drawer(t_windmng *wind);
void	close_wind(t_windmng *wind);
int		check_arg(int ac, char **av);
int		wind_loop_hook(t_windmng *wind);
void	treat_move(t_windmng *wind, int keycode);
int		wind_keyhook(int keycode, t_windmng *wind);
char	*read_file(char *file, char *letter, int size);

#endif
