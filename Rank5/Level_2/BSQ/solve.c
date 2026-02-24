/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 10:44:37 by mpazouki          #+#    #+#             */
/*   Updated: 2026/02/20 12:37:35 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void solve_bsq(t_map *map)
{
    int **dp = malloc(map-> rows * sizeof(int *));
    if (!dp)
        return;
    for (int i = 0; i< map->rows; i ++)
    {
        dp[i] = calloc(map->cols, sizeof(int));
        if(!dp)
            return;
    }
    
    int best_size = 0;
    int best_i = 0;
    int best_j = 0;
    
    for (int  i = 0; i< map->rows; i ++)
    {
        for(int j = 0; j < map->cols; j++)
        {
            if (map->grid[i][j] == map->o)
                dp[i][j] = 0;
            else
            {
                if (i == 0 || j == 0)
                    dp[i][j] =1;
                
                int a = dp[i-1][j]; 
                int b = dp[i][j-1]; 
                int c = dp[i-1][j-1];
                int min = a < b ? a : b;
                if (c < min) min = c;

                dp[i][j] = min + 1;
                
                if (dp[i][j] > best_size)
                {
                    best_size = dp[i][j];
                    best_i = i;
                    best_j = j;
                }
            }
        }
    }
    
    for (int  i = best_i - best_size + 1; i <= best_i; i++)
    {
        for (int  j = best_j - best_size + 1; j <= best_j; j++)
            map->grid[i][j] = map->f;
    }

    for (int i = 0; i<=map->rows; i++)
        free(dp[i]);
    free(dp);
}


// DP algorithm

/* If the cell (i, j) is empty:

This means:

Look at the square above

Look at the square to the left

Look at the square diagonally up-left

The smallest of those determines how big a square you can extend */