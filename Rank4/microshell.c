/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miroschell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:45:15 by mpazouki          #+#    #+#             */
/*   Updated: 2025/05/08 13:45:15 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char **argv, char **envp)
{
    
    int i;
    int start;
    int j;

     i = 1;
     while(i< argc)
     {
        start = i;
        while(i<argc && (strcmp(argv[i], "|") && strcmp(argv[i], ";") ))
            i++;
        if (i > start)
        {
            j=start;
            write(1, "command", 9);
            while(j < i)
            {
                write(1, argv[i], strlen(argv[i]));
                if (j + 1 < i)
                    write(1, " ", 1);
                j++;
            }
            write(1, "\n", 1);
        }
        if (i<argc &&  (!strcmp(argv[i], "|") || !strcmp(argv[i],";")))
            i++;
    }
    (void )envp;
    return 0;
}