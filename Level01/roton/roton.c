#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int     main(int ac, char *av[])
{
    if (ac == 2)
    {
        int i = 0;
        while (av[1][i])
        {
            if ((av[1][i] >= 'A' && av[1][i] <= 'Y') || (av[1][i] >= 'a' && av[1][i] <= 'y'))
                ft_putchar(av[1][i] + 1);
            else if (av[1][i] == 'Z' || av[1][i] == 'z')
                ft_putchar(av[1][i] - 25);
            else
                ft_putchar(av[1][i]);
            i++;
        }
    }
    ft_putchar('\n');
    return (0);
}
