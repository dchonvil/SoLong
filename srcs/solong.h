/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 06:08:52 by dchonvil          #+#    #+#             */
/*   Updated: 2021/11/18 06:09:03 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define ESCAPE 65307

typedef	struct	s_map_items
{
    int c;
    int e;
    int p;
}				t_map_items;

typedef	struct	s_windmng
{
    char **map;
    int p_x;
    int p_y;
    int map_x;
    int map_y;
    int p_move;
    int move_x;
    int move_y;
    int nb_c;
    int total_c;
    int p_nb_c;
    void *mlx_id;
    void *wind_id;
    void *c_img;
    void *e_img;
    void *p_img;
    void *s_img;
    void *w_img;
}				t_windmng;

void    free_map(char **map);
int     check_arg(int ac, char **av);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	**ft_split(char const *s, char c);
int	    check_walls(char **map);
int	    check_map(char **map);
int     map_control(char **map);
char	**treat_file(char *file);
char	*read_file(char *file, char *letter, int size);
void    wind_size(t_windmng *wind);
int     load_icons(t_windmng *wind);
void    map_drawer(t_windmng *wind);
void    close_wind(t_windmng *wind);
void    wind_keyhook(int keycode, t_windmng *wind);
void    wind_mousehook(int button,int x,int y, t_windmng *wind);
void    wind_expose_hook(void *param);
void    wind_loop_hook(void *param);
void    treat_move(t_windmng *wind, int keycode);

#endif