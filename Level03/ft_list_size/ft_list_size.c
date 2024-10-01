#include <stdlib.h>

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;


int	ft_list_size(t_list *begin_list)
{
	int i;
	i = 0;
	t_list *current = begin_list;
	while(current != NULL)
	{
		i++;
		current = current -> next;
	}
	return(i);
}
