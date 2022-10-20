#include "../push_swap.h"
void ft_lstiter(t_stack *lst, void (*f)(int))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		(*f)(lst->num);
		lst = lst->next;
	}
}