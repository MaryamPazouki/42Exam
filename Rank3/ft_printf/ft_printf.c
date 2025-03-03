/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 02:27:46 by mpazouki          #+#    #+#             */
/*   Updated: 2025/03/03 23:18:42 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include<stdarg.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int ft_putchar(char c)
{
    return(write(1, &c, 1));
}

int ft_putstr(char *s)
{
    if (!s)
    {
        s = "(null)";
    }
    int i=0;
    while(s[i])
    {
        ft_putchar(s[i]);
        i++;
    }
    return(i);
}

int ft_putnbr(int nb)
{
    int count = 0;
    char str[] = "0123456789";
    if (nb== -2147483648)
    {
        count += ft_putstr("-2147483648");
        return(count);
    }
    if (nb < 0)
    {
        count += ft_putchar ('-');
        nb = -nb;
    }
    if (nb >=10)
        count += ft_putnbr(nb/10);
    count += ft_putchar(str[nb%10]);
    return(count);
}


int ft_puthex(unsigned int nb)
{
    int count = 0;
    char str[] = "0123456789abcdef";
    if (nb >=16)
        count += ft_putnbr(nb/16);
    count += ft_putchar(str[nb%16]);
    return(count);
}

int ft_printf(char *str, ...)
{
    va_list ap;
    int count = 0;
    int i = 0;

    va_start(ap, str);
    while(str[i])
    {
        if (str[i] == '%')
        {
            if (str[i+1] == 's')
                count += ft_putstr(va_arg(ap, char *));
            else if (str[i+1] == 'd' )
                count += ft_putnbr(va_arg(ap, int));
            else if (str[i+1] == 'x')
                count += ft_puthex(va_arg(ap, unsigned int));
        	else
                count += ft_putchar(str[i+1]);
            i++;
        }
        else
            count += ft_putchar(str[i]);
        i++;
    }
    va_end(ap);
    return (count);
}


int main(void)
{
    int d= 0; 
    int d2 = 0;
    d = ft_printf("Hello %s\n", "you");
    d2= printf("Hello %s\n", "you");
    printf ("ft_printf %d, printf %d \n", d , d2);

    // d = ft_printf("Hello %d\n", 12);
    // d2= printf("Hello %d\n", 12);
    // printf ("ft_printf %d, printf %d", d , d2);

   //d = ft_printf("Hello %x\n", 123);
    /* d2= printf("Hello %x\n", 123);
    printf ("ft_printf %d, printf %d", d , d2); */


    // d = ft_printf("Hello %d\n", -2147483648);
    // d2= printf("Hello %d\n", -2147483648);
    // printf ("ft_printf %d, printf %d", d , d2);
    return 0;

}