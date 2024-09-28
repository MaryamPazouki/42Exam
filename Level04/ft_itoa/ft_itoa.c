#include <stdio.h>
#include <stdlib.h>

/* #include <limits.h>
 printf("%d", INT_MIN);
 */

char	*ft_itoa(int nbr)
{
    char c;
    int n = nbr;
    int len = 0;
    if (nbr == -2147483648)
        return("-2147483648\0");
    if (nbr <= 0)
        len++;
    while(n)
    {   
        n/=10;
        len++;
    }
    char *result = (char *) malloc(sizeof(char)* (len +1));
    if(result == NULL)
        return(NULL);
    if (nbr == 0)
    {
        result[0] = '0';
        return(result);
    }
    if (nbr < 0)
    {
        result[0] = '-';
        nbr = -nbr;
    }
    result[len] = '\0';
    while(nbr)
    {
        result[--len] = nbr %10 +'0';
        nbr /=10;
        
    }
    return (result);
}


int main() {
    char buffer[20];
    int num = 0;

    // Using sprintf to mimic itoa
    sprintf(buffer, "%d", num);
    printf("itoa output: %s\n", buffer);

    // Using ft_itoa
    char *ft_result = ft_itoa(num);
    if (ft_result != NULL) {
        printf("ft_itoa output: %s\n", ft_result);
        free(ft_result);
    } else {
        printf("ft_itoa returned NULL\n");
    }

    return 0;
}
