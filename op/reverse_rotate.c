/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 02:14:40 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/11/01 02:14:41 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst || !*lst || !((*lst)->next))
		return ;
	tmp = ft_lstlast(*lst);
	tmp->next = *lst;
	(*lst)->previous = tmp;
	*lst = tmp;
	tmp = tmp->previous;
	tmp->next = NULL;
	(*lst)->previous = NULL;
}

void	rra(t_stack **lst)
{
	reverse_rotate(lst);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **lst)
{
	reverse_rotate(lst);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
