/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 10:57:37 by mpazouki          #+#    #+#             */
/*   Updated: 2026/02/19 11:19:21 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BSQ_H
#define BSQ_H

#include<stdlib.h>
#include<stdio.h>

typedef struct s_map{
    int rows; 
    int cols;
    char e;
    char o;
    char f;
    char **grid;
}t_map;

int parse_map(const char *filename, t_map *map);
void free_map(t_map *map);

void solve_bsq(t_map *map);
void print_map(const t_map *map);

#endif