#include<string.h>

size_t	ft_strspn(const char *s, const char *accept)
{
    int i, j;
    i = j = 0;
    
    while (s[i] != '\0')        
    {
        while (s[i] == accept[j])
            j++;
        i++;
    }
    return(j);
}