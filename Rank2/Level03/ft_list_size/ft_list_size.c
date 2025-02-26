#include <stdlib.h>
#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int i;
	i = 0;
	t_list *current = begin_list; // because we wanna inter on the list thats 
	//why we start with current
	while(current != NULL)
	{
		i++; // first count one node then gor to the next
		current = current -> next;
	}
	return(i);
}


