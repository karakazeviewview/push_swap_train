#include "../push_swap.h"
t_stack *ft_lstmap(t_stack *lst, int (*f)(int), void (*del)(int))
{
	t_stack *tmp;
	t_stack *newlist;

	if (!lst || !f)
		return (NULL);
	newlist = NULL;
	while (lst)
	{
		tmp = ft_lstnew((*f)(lst->num));
		if (!tmp)
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, tmp);
		lst = lst->next;
	}
	return (newlist);
}
