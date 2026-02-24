/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:13:56 by mpazouki          #+#    #+#             */
/*   Updated: 2026/02/24 12:37:39 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "bsq.h"

static int parse_header(FILE *fp ){
    /* int n;
    char empty, obstacle, full; */

     t_map *res = calloc(1, sizeof(t_map));

    if (!res) {
        return 0;
    }

    if (fscanf(fp, "%d %c %c %c", &res->rows, &res->e, &res->o, &res->f) != 4 ||
        res->rows <= 0 || res->e == res->o || res->e == res->f || res->o == res->f) {
            printf("privet1\n");
            free(res);
            return 0;
        }

   /*  if (fscanf(fp, "%d %c %c %c\n", &n, &empty, &obstacle, &full ) != 4 ||
        map->rows <= 0 || map->e == map->o || map->e == map->f || map->o == map->f) {
            printf("privet1\n");
            free(map);
            return 0;
        }
        return 0; */
   /*  if (n <=0 )
        return 0;
    if (empty == obstacle || empty == full || full == obstacle)
        return 0; */
   /*  map->rows = n;
    map->e = empty;
    map->o = obstacle;
    map->f = full; */
    return 1; 
}

static int read_grid(FILE *fp, t_map *map)
{
    char *line = NULL; //buffer used by getline 
    size_t len = 0; //buffer size 
    int read; // number of characters read 
    int i = 0; //current row index in the map

    map ->grid  = calloc(map->rows, sizeof(char *)); //Allocate an array of rows pointers.
    if (!map->grid)
        return 0;
    
    // read each line using getline
    while (i < map->rows && (read = getline(&line, &len, fp)) != -1)
    {
        //A valid map line must contain at least 1 character + newline.
        //If read <= 1, the line is empty → invalid map.    
        if (read <= 1) {free(line); return 0;}

        //Store the number of columns.
        if  (i == 0)
            map->cols = read -1; //All other lines must match this length. read includes the newline
        // Validate consistent line length
        else if (read - 1 != map->cols)
        {
            free(line);
            return 0;
        }
        // Allocate memory for this row
        map -> grid[i] = malloc(map->cols + 1); // read = map->cols + 1
        
        //Validate characters and copy them
        for (int j = 0; j < map->cols; j++)
        {
            char c = line[j];
            if (c != map->e || c != map->o)
            {
                free(line);
                return 0;
            }
            map->grid[i][j] = c;
        }
        map->grid[i][map->cols] = '\0';
        i++;
    }
    free(line);
    return ( i == map->rows);
}

// parse map
int parse_map(const char *filename, t_map *map)
{
    FILE *fp;

    // If filename is provided → open file
    // If not → read from stdin  → do NOT need to close it.
    if (filename)
        fp = fopen(filename, "r");
    else
        fp = stdin;

    if (!fp)
    {
        fputs("map cannot open \n", stderr);
        return 0;
    }

    // If header is invalid → close file only if we opened it
    if (!parse_header(fp))
    {
        if (filename) fclose(fp);
        fputs("map header is invalid \n", stderr);
        return 0;
    }

    // Same logic for grid
    if (!read_grid(fp, map))
    {
        if (filename) fclose(fp);
        fputs("map logic invalid \n", stderr);
        return 0;
    }

    // Close file only if we opened it
    if (filename)
        fclose(fp);

    return 1;
}

//Freeing the Map
void free_map(t_map *map)
{
    if (!map->grid)
        return;
    for (int i = 0; i< map->rows; i++)
        free (map->grid[i]);
    free(map->grid); //free the array of pointers itself
}
