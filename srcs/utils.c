/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 04:39:59 by dchonvil          #+#    #+#             */
/*   Updated: 2021/11/19 04:40:05 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "solong.h"

int check_arg(int ac, char **av)
{
    int c;

    c = 0;
    if (ac != 2)
    {
        if (ac < 2)
            ft_putstr_fd("Error: Argument needed.\n", 1);
        if (ac > 2)
            ft_putstr_fd("Error : Only one argument expected.\n", 1);
        ft_putstr_fd("Usage: ./so_long [map.ber]\n", 1);
        return (0);
    }
    while (av[1][c])
        c++;
    if (av[1][c - 4] != '.' && av[1][c - 3] != 'b'
        && av[1][c - 2] != 'e' && av[1][c - 1] != 'r')
    {
        ft_putstr_fd("Error: The used file is not a .ber.\n", 1);
        return (0);
    }
    return (1);
}

void free_map(char **map)
{
    int c;

    c = 0;
    while (map[c])
    {
        free(map[c]);
        c++;
    }
    free(map);
}