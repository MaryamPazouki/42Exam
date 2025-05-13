/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microschell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 23:48:06 by mpazouki          #+#    #+#             */
/*   Updated: 2025/05/11 23:48:06 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

void err_fatal(void)
{
    write(2, "Err: fatal\n", 12);
    exit(1);
}

void err_exec(char *cmd)
{
	write(2, "error: cannot execute ", 23);
	write(2, cmd, strlen(cmd));
	write(2, "\n", 1);
	exit(1);
}



int ft_cd(char **args)
{
	int count = 0;
	while (args[count])
		count++;
	if (count != 2)
	{
		write(2, "error: cd: bad arguments\n", 25);
		return (1);
	}
	if (chdir(args[1]) == -1)
	{
		write(2, "error: cd: cannot change directory to ", 38);
		write(2, args[1], strlen(args[1]));
		write(2, "\n", 1);
		return (1);
	}
	return (0);
}

int main(int argc, char **argv, char **envp)
{
	int i = 1;
	int start, j;

	while (i < argc)
	{
		start = i;
		while (i < argc && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;

		if (i > start)
		{
			// Create null-terminated command array
			char **cmd = malloc(sizeof(char *) * (i - start + 1));
			if (!cmd)
				err_fatal();

			for (j = 0; j < i - start; j++)
				cmd[j] = argv[start + j];
			cmd[j] = NULL;

			// Built-in cd
			if (!strcmp(cmd[0], "cd"))
				ft_cd(cmd);
			else
			{
				pid_t pid = fork();
				if (pid < 0)
					err_fatal();
				else if (pid == 0)
				{
					execve(cmd[0], cmd, envp);
					err_exec(cmd[0]);
				}
				else
				{
					if (waitpid(pid, NULL, 0) == -1)
						err_fatal();
				}
			}
			free(cmd);
		}

		// Skip over ";" or "|"
		if (i < argc && (!strcmp(argv[i], ";") || !strcmp(argv[i], "|")))
			i++;
	}
	return (0);
}





/*
int main(int argc, char **argv, char **envp)
{
    
    int i;
    int start;
    int j;

     i = 1;
     while(i< argc)
     {
        start = i;
        while(i < argc && (strcmp(argv[i], "|") && strcmp(argv[i], ";") ))
            i++;
        if (i > start)
        {
           if (!strcmp(argv[start], "cd"))
           {
             argv[i] = NULL;
             ft_cd(&argv[start]);
           }
           else 
           {        
                argv[i] = NULL;
                pid_t pid = fork();
                if (pid < 0)
                    err_fatal();
                else if(pid == 0)
                {
                    execve(argv[start], &argv[start], envp);
                    err_exec();
                }
                else 
                {
                    if (waitpid (pid , NULL, 0)== -1)
                        err_fatal();
                }
           }
        }
        if (i < argc &&  (!strcmp(argv[i], "|") || !strcmp(argv[i], ";")))
            i++;
    }
    (void )envp;
    return 0;
}*/