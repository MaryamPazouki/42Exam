/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:26:42 by mpazouki          #+#    #+#             */
/*   Updated: 2026/02/24 12:01:10 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static void process_map(const char *filename)
{
    t_map map = {0};
    
    if (!parse_map(filename, &map))
    {
        fputs("map error \n", stderr);
        return;
    }

    solve_bsq(&map);
    print_map(&map);
    free_map(&map);
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        process_map(NULL);
        return 0;
    }
    fputs("map goes to  open \n", stderr);
    for (int i = 0; i < argc ; i++)
    {
        process_map(argv[i]);
        
        // Print newline between maps (but not after the last one)
        if (i< argc -1)
            fputc('\n', stdout);
    }
    return 0;
}