void sort_int_tab(int *tab, unsigned int size)
{
    int i;
    int temp;
    i = 0;
    while (i < size )
    {
        if (tab[i] > tab[i+1])
        {
            temp = tab[i];
            tab[i] = tab[i+1];
            tab[i +1] = temp;
            i = 0;
        }
        else 
            i++;
    }

}


/*------------main-------------------------------------*/
#include <stdio.h>

int main()
{
    int arr[] = {2,4,5,30,1};
    unsigned int size = sizeof(arr) / sizeof(arr[0]);
    
    for (unsigned int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");


    sort_int_tab(arr, size);

    for (unsigned int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
    return(0);
}