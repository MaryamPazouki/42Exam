#include<unistd.h>

void	ft_putstr(char *str)
{
    while(*str)
        write(1, str++, 1);
}


// version with indexes
void ft_putstr(char *str)
{
    int i = 0;

    while (str[i])
        write(1, &str[i++], 1);
}

/*
Conclusion:
Use str++ when you want to move a pointer to the next element in a sequence directly.
Use &str[i++] when you want to access elements using an index without modifying the original pointer.

*/