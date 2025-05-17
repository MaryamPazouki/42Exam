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
    write(2, "error: fatal\n", 13);
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

int execute(char **argv, int i, char **envp, int input_fd, int has_pipe)
{
    int fd[2];
    if (has_pipe && pipe(fd) == -1)
        err_fatal();

    pid_t pid = fork();
    if (pid < 0)
        err_fatal();
    else if (pid == 0)
    {
        if (input_fd != 0 && dup2(input_fd, 0) == -1)
            err_fatal();
        if (has_pipe && dup2(fd[1], 1) == -1)
            err_fatal();
        if (input_fd)
            close(input_fd);
        if (has_pipe)
        {
            close(fd[0]);
            close(fd[1]);
        }
        execve(argv[0], argv, envp);
        err_exec(argv[0]);
    }
    else
    {
        if (waitpid(pid, NULL, 0) == -1)
            err_fatal();
        if (input_fd)
            close(input_fd);
        if (has_pipe)
            close(fd[1]);
        return has_pipe ? fd[0] : 0;
    }
    return 0;
}

int main(int argc, char **argv, char **envp)
{
    int i = 1, start, j;
    int input_fd = 0;

    while (i < argc)
    {
        start = i;
        while (i < argc && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
            i++;

        if (i > start)
        {
            char **cmd = malloc(sizeof(char *) * (i - start + 1));
            if (!cmd)
                err_fatal();
            for (j = 0; j < i - start; j++)
                cmd[j] = argv[start + j];
            cmd[j] = NULL;

            int is_pipe = (i < argc && !strcmp(argv[i], "|"));
            if (!strcmp(cmd[0], "cd"))
            {
                if (input_fd)
                    close(input_fd);
                ft_cd(cmd);
                input_fd = 0;
            }
            else
                input_fd = execute(cmd, i - start, envp, input_fd, is_pipe);

            free(cmd);
        }

        if (i < argc && (!strcmp(argv[i], ";") || !strcmp(argv[i], "|")))
            i++;
    }
    return 0;
}

