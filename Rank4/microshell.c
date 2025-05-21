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


// // Prints fatal error and exits
// void err_fatal(void)
// {
//     write(2, "error: fatal", 13);
//     exit(1);
// }

// // Prints exec error if execve fails
// void err_exec(char *cmd)
// {
//     write(2, "error: cannot execute ", 23);
//     write(2, cmd, strlen(cmd));
//     write(2, "\n", 1);
//     exit(1);
// }


void	ft_putstr_fd2(char *str, char *arg)
{
	while (*str)
		write(2, str++, 1);
	if (arg)
		while(*arg)
			write(2, arg++, 1);
	write(2, "\n", 1);
   // exit(1);
}


// Built-in cd implementation with argument and error checks
int ft_cd(char **args)
{
    int count = 0;
    while (args[count])
        count++;
    // cd must be followed by exactly one argument
    if (count != 2)
    {
        ft_putstr_fd2("error: cd: bad arguments", NULL);
        return(1);
    }
    // Attempt to change directory
    else if (chdir(args[1]) == -1)
    {
        ft_putstr_fd2("error: cd: cannot change directory to ", args[1]	);
        return(1);
    }
    return (0);
}

// Executes a command with optional piping
int execute(char **argv, char **envp, int input_fd, int has_pipe)
{
    int fd[2];

    // Create a pipe if needed
    if (has_pipe && pipe(fd) == -1)
    {
        ft_putstr_fd2("error: fatal", NULL);
    }

    pid_t pid = fork();
    if (pid < 0)
    {
        ft_putstr_fd2("error: fatal", NULL);
    }
    else if (pid == 0)
    {
        // In child

        // Redirect stdin if input_fd was passed (i.e., reading from previous pipe)
        if (input_fd != 0 && dup2(input_fd, 0) == -1)
            ft_putstr_fd2("error: fatal", NULL);

        // Redirect stdout to write end of pipe
        if (has_pipe && dup2(fd[1], 1) == -1)
            ft_putstr_fd2("error: fatal", NULL);

        // Close file descriptors
        if (input_fd)
            close(input_fd);
        if (has_pipe)
        {
            close(fd[0]);
            close(fd[1]);
        }

        // Execute the command
        execve(argv[0], argv, envp);
        // If execve fails
        ft_putstr_fd2("error: cannot execute ", argv[0]);
    }
    else
    {
        // In parent

        // Wait for the child if it's the last command or part of sequential execution
        if (waitpid(pid, NULL, 0) == -1)
        {
            ft_putstr_fd2("error: fatal", NULL);
            
        }

        // Close input_fd if it was opened
        if (input_fd)
            close(input_fd);

        // If there's a pipe, return the read end to be used in the next command
        if (has_pipe)
        {
            close(fd[1]);     // Close unused write end
            return fd[0];     // Return read end for next input
        }
    }
    return 0;
}

int main(int argc, char **argv, char **envp)
{
    int i = 1, start, j;
    int input_fd = 0;  // Will be used for chaining pipe inputs

    while (i < argc)
    {
        start = i;
        // Move i to the next separator '|' or ';'
        while (i < argc && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
            i++;

        if (i > start)
        {
            // Build the command array
            char **cmd = malloc(sizeof(char *) * (i - start + 1));
            if (!cmd)
            {
                ft_putstr_fd2("error: fatal", NULL);
            }
			j = 0;
			while(j < i -start)
			{
                cmd[j] = argv[start + j];
				j++;
			}
			cmd[j] = NULL;

            // Check if the next token is a pipe
            int is_pipe = (i < argc && !strcmp(argv[i], "|"));

            // Handle built-in cd
            if (!strcmp(cmd[0], "cd"))
            {
                // cd must not be part of a pipeline
                if (input_fd)
                    close(input_fd);
                ft_cd(cmd);
                input_fd = 0;  // Reset input
            }
            else
            {
                // Execute normal command with pipe if needed
                input_fd = execute(cmd, envp, input_fd, is_pipe);
            }

            free(cmd);
        }

        // Move past the separator token if present
        if (i < argc && (!strcmp(argv[i], ";") || !strcmp(argv[i], "|")))
            i++;
    }
    close (input_fd);
    return 0;
}


