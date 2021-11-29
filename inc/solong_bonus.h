/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:39:32 by dchonvil          #+#    #+#             */
/*   Updated: 2021/11/27 21:41:03 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_BONUS_H
# define SOLONG_BONUS_H

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
	void	*n_img;
	void	*n2_img;
	void	*p_img;
	void	*p2_img;
	void	*s_img;
	void	*w_img;
	void	*mlx_id;
	void	*wind_id;
	void	*blk_img;
	void	*tmp_img;
	void	*tmp2_img;
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
int		ft_get_color(int t, int r, int g, int b);
void	put_on_screen(t_windmng *wind, int c);

#endif
