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

typedef	struct	s_map_items
{
    int e;
    int p;
}				t_map_items;

int     check_arg(int ac, char **av);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	**ft_split(char const *s, char c);
int	    check_walls(char **map);
int	    check_map(char **map);
int     map_control(char **av);

#endif