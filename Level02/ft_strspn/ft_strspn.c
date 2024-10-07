#include<string.h>

char *ft_strchr(const char *s, int c)
{
    while(*s != '\0')
    {
        if (*s == c)
        {
            return((char *) s );
        }
        s++;
    }
    return(0);
}


size_t	ft_strspn(const char *s, const char *accept)
{
    int i, j;
    i = j = 0;
    
    while (s[i] != '\0')        
    {
        if (ft_strchr(accept, s[i]) == 0)
            break;
        i++;
    }
    return(i);
}

#include<stdio.h>

int main()
{
    char *s = "abcde1234ef";
    char *accept = "abcd12";

    printf("the ft_strspn output %ld \n ", ft_strspn(s,accept));
    printf("the ft_strspn output %ld \n",  strspn(s,accept));

}