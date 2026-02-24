/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:23:47 by mpazouki          #+#    #+#             */
/*   Updated: 2026/02/20 12:25:52 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void print_map(const t_map *map)
{
    for (int i = 0; i< map->rows; i++)
    {
        fputs(map->grid[i], stdout); //prints a string without adding a newline.
        fputc('\n', stdout); // adds the newline.
    }
}