#include "sort_list.list.h"
#include <stdlib.h>


t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    int temp;
    t_list *start;


    start = lst;
    while (lst != NULL && lst->next != NULL)
    {
        if (cmp(lst->data, lst->next->data) == 0)
        {
            temp = lst->next->data;
            lst->next-> data = lst->data;
            lst->data = temp;
            lst = start;
        }
            lst = lst->next;
    }
    return(start);
}


/*--------------------main---------------------------------------*/

// Function to create a new node
t_list *create_node(int value) {
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}


// Function to print the list
void print_list(t_list *lst) {
    while (lst != NULL) {
        printf("%d -> ", lst->data);
        lst = lst->next;
    }
    printf("NULL\n");
}