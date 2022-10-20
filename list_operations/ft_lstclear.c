#include "../push_swap.h"
void ft_lstclear(t_stack **lst, void (*del)(int))
{
	t_stack *tmp;

	if (!lst || !del || !*lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		(*del)((*lst)->num);
		free(*lst);
		*lst = NULL;
		*lst = tmp->next;
	}
}