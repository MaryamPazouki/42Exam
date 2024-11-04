#include <stdlib.h>
#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    
    if (begin_list == NULL || *begin_list == NULL)
        return;
    
    t_list *cur;
    cur  = *begin_list;

    if (cmp(cur->data, data_ref) == 0)
        {
            *begin_list = cur ->next;
            fre(cur);
            ft_list_remove_if(begin_list, data_ref, cmp);
        }
    else
         {
            cur = *begin_list;
             ft_list_remove_if(&cur -> next, data_ref, cmp);
        }
    }

}


/*---------------main-------------------------------------------*/
#include <stdio.h>

// Function to create a new node
t_list *create_node(void *data) {
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node) return NULL;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to print the list
void print_list(t_list *list) {
    while (list) {
        printf("%d -> ", *(int *)list->data);
        list = list->next;
    }
    printf("NULL\n");
}

// Comparison function for integers
int int_cmp(void *a, void *b) {
    return (*(int *)a - *(int *)b);
}

// Main function to test ft_list_remove_if
int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 2 -> 4
    t_list *list = create_node(&(int){1});
    list->next = create_node(&(int){2});
    list->next->next = create_node(&(int){3});
    list->next->next->next = create_node(&(int){2});
    list->next->next->next->next = create_node(&(int){4});

    printf("Original list: ");
    print_list(list);

    // Remove all nodes with the value 2
    int remove_value = 2;
    ft_list_remove_if(&list, &remove_value, int_cmp);

    printf("List after removing 2: ");
    print_list(list);

    // Free the remaining nodes
    while (list) {
        t_list *temp = list;
        list = list->next;
        free(temp);
    }

    return 0;
}

