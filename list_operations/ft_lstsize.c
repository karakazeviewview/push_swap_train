#include "../push_swap.h"
int ft_lstsize(t_stack *lst)
{
	int i;
	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}