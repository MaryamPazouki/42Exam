#include <stdlib.h>
#include <stdio.h>
#include "ft_list.h"

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    if (begin_list == NULL)
        return;

    while (begin_list)
    {
        (*f)(begin_list -> data);
        begin_list = begin_list->next;
    }
}


/* ---------------main ---------------------------*/


// Function to create a new node
t_list *create_node(int value) {
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node) return NULL;
    new_node->data = malloc(sizeof(int));
    *(int *)new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

// Function to print the data of each node
void print_data(void *data) {
    printf("%d\n", *(int *)data);
}

// Main function to test ft_list_foreach
int main() {
    // Create a simple linked list: 1 -> 2 -> 3
    t_list *list = create_node(1);
    list->next = create_node(2);
    list->next->next = create_node(3);

    // Use ft_list_foreach to print each element
    printf("List elements:\n");
    ft_list_foreach(list, print_data);

    // Free the list
    while (list) {
        t_list *temp = list;
        list = list->next;
        free(temp->data); // Free the data
        free(temp);       // Free the node
    }

    return 0;
}
