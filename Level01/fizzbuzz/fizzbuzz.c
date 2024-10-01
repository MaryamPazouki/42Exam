#include<unistd.h>

// Define put_nbr to print out the number with "write" function, which take just char as argument.
void put_nbr(int nbr)
{
    if (nbr > 10)
        put_nbr(nbr/10);
    char digit;
    digit = nbr%10 + '0';
    write(1, &digit, 1);
}

int main()
{
    int i;
    i=1;
    while (i<=100)
    {
        if(i%15 == 0)
            write(1,"fizzbuzz", 8);
        else if(i%5 == 0)
            write(1,"fizz", 4);
        else if(i%3 == 0)
            write(1,"buzz", 4);
        else
        {
            put_nbr(i);
        }
        i++;
        write(1, "\n", 1);
    }
    





}