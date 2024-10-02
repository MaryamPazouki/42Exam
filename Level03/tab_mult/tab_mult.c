#include<unistd.h>

int ft_atoi( char *str)
{
    int sign;
    int digit;
    digit = 0;
    sign = 1;

    while(*str == ' ' || (*str >= 9 && *str <= 13) )
    {
        str++;
    }
    if (*str == '+')
        str++ ;
    while (*str >= '0' && *str <= '9')
    {
        digit = digit * 10 + *str - '0';
        str++;
    }
    return(sign * digit);
}

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr(int nbr)
{
    if (nbr/10 > 0)
        ft_putnbr(nbr/10);
    ft_putchar(nbr%10 + '0');
}

int main (int argc, char *argv[])
{
    if (argc != 2)
    {
        write(1, "\n", 1);
    }
    else 
    {
        int i;
        int digit;
        int mult;

        i = 1;
        digit = ft_atoi(argv[1]);
        while( i <=  9 && digit <= 238609183)
        {
            ft_putnbr(i);
            write(1, " x ", 3); 
            ft_putnbr(digit);
            write(1, " = ", 3);
            mult = i * digit; 
            ft_putnbr(mult); 
            write(1, "\n", 1);
            i++;
        }
    }
}