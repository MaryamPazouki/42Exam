#include <stdlib.h>
char *ft_strncpy(char *dist, char *str, int n)
{
    int i;
    i=0;
    while(i < n && *str)
     {
        *dist ++ = *str ++;
        i++;
     }
     dist[i] = '\0';
     return(dist);
}


char    **ft_split(char *str)
{
    int i;
    int j;
    int k;
    int wc;

    i = 0;
    j = 0;
    k = 0;
    wc = 0;

    while(str[i])
    {
        while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ))
            i++;
        if (str[i])
            wc++;
        while (str[i] && (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' ))
            i++;
    }

    i=0;
    char **out = (char **) malloc(sizeof(char *) * (wc +1));

    while(str[i])
    {
        while(str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
            i++;
        j = i;
        while(str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
                i++;
        if (i > j)
        {    
            out[k] = (char *)malloc(sizeof(char) * (i - j + 1)); 
            if(!out[k])
                return NULL;
            ft_strncpy( out[k], &str[j], (i-j)  );
            k++;
        }

    }
    out[k] = NULL;
    return(out);
}

/*---------------------------main----------------------------------------------*/

#include <stdio.h>
int main() {
    char *c = "  this is    the check 42 ";
    char **s = ft_split(c);
    
    // Print the split strings
    for (int i = 0; s[i] != NULL; i++) {
        printf("%s\n", s[i]);
        free(s[i]); // Free each string after printing
    }
    free(s); // Free the array of strings

    return 0;
}

