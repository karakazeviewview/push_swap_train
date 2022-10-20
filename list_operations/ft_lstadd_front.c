#include "../push_swap.h"

void ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
		(*lst)->previous = new;
	new->next = *lst;
	*lst = new;
}