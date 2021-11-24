/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_mng.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 03:44:41 by dchonvil          #+#    #+#             */
/*   Updated: 2021/11/19 03:44:47 by dchonvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "solong.h"

int     read_map(char *box, char *letter, int p)
{
    int		c;
    int		r;

    c = 0;
    while ((r = read(p, letter, 1)) != 0)
    {
        if (r == -1)
        {
            ft_putstr_fd(strerror(errno), 1);
            return (r);
        }
        box[c] = letter[0];
        c++;
    }
    box[c] = '\0';
    return (0);
}

char	*read_file(char *file, char *letter, int size)
{
    int     p;
    int		check;
    char	*box;

    p = open(file, O_RDONLY);
    if (p == -1)
    {
        ft_putstr_fd(strerror(errno), 1);
        return (NULL);
    }
    box = malloc(sizeof(char) * (size + 1));
    if (!box)
    {
        ft_putstr_fd(strerror(errno), 1);
        return (NULL);
    }
    check = read_map(box, letter, p);
    close(p);
    if (check == -1)
    {
        free(box);
        return (NULL);
    }
    return (box);
}

int		check_file(char *file, char *letter)
{
    int		c;
    int		p;
    int		r;

    c = 0;
    p = open(file, O_RDONLY);
    if (p == -1)
    {
        ft_putstr_fd(strerror(errno), 1);
        return (p);
    }
    while ((r = read(p, letter, 1)) != 0)
    {
        if (r == -1)
        {
            close(p);
            ft_putstr_fd(strerror(errno), 1);
            return (r);
        }
        c++;
    }
    close(p);
    return (c);
}

char	**treat_file(char *file)
{
    int		c;
    char    *box;
    char	**map;
    char	*letter;

    box = NULL;
    letter = malloc(sizeof(char) * 1);
    if (!letter)
    {
        ft_putstr_fd(strerror(errno), 1);
        return (NULL);
    }
    c = check_file(file, letter);
    if (c > 0)
        box = read_file(file, letter, c);
    if (c == -1 || !box)
    {
        free(letter);
        return (NULL);
    }
    map = ft_split(box, '\n');
    free(box);
    free(letter);
    return (map);
}

int     map_control(char **map)
{
    if (!check_walls(map))
    {
        ft_putstr_fd("Error\nThe map does not comply.\n", 1);
        ft_putstr_fd("The map must be close with the '1' character ", 1);
        ft_putstr_fd("and must be rectangular.\n", 1);
        return (0);
    }
    if (!check_map(map))
    {
        ft_putstr_fd("Error\nThe map does not comply.\n", 1);
        ft_putstr_fd("Only [0,1, C, E, P] characters (obligatory) ", 1);
        ft_putstr_fd("can be used, 'E' and 'P' just one time.\n", 1);
        ft_putstr_fd("CHARACTERS SET :\n================\n0 : Space\n", 1);
        ft_putstr_fd("1 : wall\nC : Collection\nE : Exit\nP : Player\n", 1);
        return (0);
    }
    return (1);
}