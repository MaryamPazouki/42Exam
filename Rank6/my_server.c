#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/ip.h>
#include <sys/select.h>

/* ❌ FIX: subject forbids #define → replaced with const int */
const int MAX_FD = 65536;      // FIXED
const int READ_BUF = 1000;     // FIXED

int     client_count = 0;
int     max_fd = 0;
int     client_ids[65536];
char    *client_msgs[65536];

fd_set  read_fds, write_fds, active_fds;

char    read_buffer[1001];
char    write_buffer[42];


// ---------- Utility Functions ----------

void fatal_error(void)
{
    write(2, "Fatal error\n", 12);
    exit(1);
}

int extract_message(char **buf, char **msg)
{
    char    *newbuf;
    int     i = 0;

    *msg = NULL;
    if (*buf == NULL)
        return 0;

    while ((*buf)[i])
    {
        if ((*buf)[i] == '\n')
        {
            newbuf = calloc(1, strlen(*buf + i + 1) + 1);
            if (!newbuf)
                return -1;

            strcpy(newbuf, *buf + i + 1);

            *msg = *buf;
            (*msg)[i + 1] = '\0';
            *buf = newbuf;

            return 1;
        }
        i++;
    }
    return 0;
}

char *str_join(char *buf, char *add)
{
    char    *newbuf;
    int     len = (buf) ? strlen(buf) : 0;

    newbuf = malloc(len + strlen(add) + 1);
    if (!newbuf)
        return NULL;

    newbuf[0] = '\0';

    if (buf)
    {
        strcat(newbuf, buf);
        free(buf);
    }
    strcat(newbuf, add);

    return newbuf;
}


// ---------- Server Logic ----------

// void broadcast(int sender_fd, char *msg)
// {
    /* ❌ FIX: must use active_fds, NOT write_fds */
void broadcast(int sender_fd, char *msg)
{
    for (int fd = 0; fd <= max_fd; fd++)
    {
        if (FD_ISSET(fd, &write_fds) && fd != sender_fd)
            send(fd, msg, strlen(msg), 0);
    }
}

void add_client(int fd)
{
    if (fd > max_fd)
        max_fd = fd;

    client_ids[fd] = client_count++;
    client_msgs[fd] = NULL;

    FD_SET(fd, &active_fds);

    sprintf(write_buffer, "server: client %d just arrived\n", client_ids[fd]);
    broadcast(fd, write_buffer);
}

void remove_client(int fd)
{
    sprintf(write_buffer, "server: client %d just left\n", client_ids[fd]);
    broadcast(fd, write_buffer);

    free(client_msgs[fd]);
    client_msgs[fd] = NULL;
    client_ids[fd] = -1;
    FD_CLR(fd, &active_fds);
    close(fd);
}

void handle_message(int fd)
{
    char *msg;

    while (extract_message(&client_msgs[fd], &msg))
    {
        sprintf(write_buffer, "client %d: ", client_ids[fd]);
        broadcast(fd, write_buffer);
        broadcast(fd, msg);
        free(msg);
    }
}

int create_server_socket(void)
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        fatal_error();

    FD_SET(sockfd, &active_fds);
    max_fd = sockfd;

    return sockfd;
}


// ---------- Main ----------

int main(int ac, char **av)
{
    if (ac != 2)
    {
        write(2, "Wrong number of arguments\n", 26);
        return 1;
    }

    FD_ZERO(&active_fds);

    int sockfd = create_server_socket();

    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1
    // servaddr.sin_addr.s_addr = 2130706433; // 127.0.0.1
    servaddr.sin_port = htons(atoi(av[1]));

    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
        fatal_error();

    if (listen(sockfd, SOMAXCONN) < 0)
        fatal_error();

    while (1)
    {
        read_fds = write_fds = active_fds;

        if (select(max_fd + 1, &read_fds, &write_fds, NULL, NULL) < 0)
            fatal_error();

        for (int fd = 0; fd <= max_fd; fd++)
        {
            if (!FD_ISSET(fd, &read_fds))
                continue;

            if (fd == sockfd)
            {
                socklen_t len = sizeof(servaddr);
                int client_fd = accept(sockfd, (struct sockaddr *)&servaddr, &len);

                if (client_fd >= 0)
                {
                    add_client(client_fd);
                }
            }
            else
            {
                int bytes = recv(fd, read_buffer, READ_BUF, 0);

                if (bytes <= 0)
                {
                    remove_client(fd);
                    continue;
                }

                read_buffer[bytes] = '\0';
                client_msgs[fd] = str_join(client_msgs[fd], read_buffer);

                handle_message(fd);
            }
        }
    }

    return 0;
}

// const int READ_BUF = 1000;
// const int MAX_FD = 65536;

// fd_set read_fds, write_fds, active_fds;

// int client_count = 0;
// int max_fd = 0;

// char *client_msgs[MAX_FD];
// char client_ids[MAX_FD];

// char read_buffer[1001];
// char write_buffer[42];

// void add_client(int fd){
//     if (fd > max_fd)
//         max_fd = fd;
    
//     client_msgs[fd] = NULL;
//     client_ids[fd] = client_count++;

//     FD_SET(fd, &active_fds);
//     sprintf(write_buffer, "server: client %d just arrived\n" , client_ids[fd]);
//     broadcast(fd, write_buffer);
// }

// void handle_message(int fd)
// {
//     char *msg;
//     while(extract_message(&client_msgs[fd], &msg))
//     {
        
//     }
// }
// void remove_client(int fd)
// {
//     sprintf(write_buffer, "server: client %d just left\n", client_ids[fd]);
//     broadcast(fd, write_buffer);

//     free( client_msgs[fd]);
//     client_ids[fd] = -1;
//     client_msgs[fd] = NULL;
//     FD_CLR(fd, &active_fds);
//     close(fd);
// }
// while(1)
// {
//     read_fds = write_fds = active_fds;
//     if (select(max_fd +1, &read_fds, &write_fds, NULL, NULL ) < 0)
//         fatal_error();
//     for (size_t fd = 0; i <= max_fd; fd++)
//     {
//         if (!FD_ISSET(fd, &read_fds))
//             continue;
//         if (fd == sockfd)
//         {
//             socklen_t len = sizeof(servaddr);
//             int client_fd = accept(sockfd, (struct suckaddr *)&servaddr, &len);
//             if (client_fd >= 0)
//             {
//                 add_client(client_fd);
//                 break;
//             }
//         }
//         else
//         {
//             int bytes = recv(fd, read_buffer, READ_BUFF, 0);
//             if (bytes <= 0)
//             {
//                 remove_client(fd);
//             }
//             read_buufer[bytes] = '\0';
//             client_msgs[fd] = str_join(client_msgs[fd], read_buffer);
//             handle_message(fd);
//         }
//     }
    
// }