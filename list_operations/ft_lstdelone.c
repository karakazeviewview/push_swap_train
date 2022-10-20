#include "../push_swap.h"
void ft_lstdelone(t_stack *lst, void (*del)(int))
{
	if (!lst || !del)
		return ;
	(*del)(lst->num);
	free(lst);
}