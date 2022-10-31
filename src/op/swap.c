/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 02:14:52 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/11/01 02:14:53 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **lst)
{
	t_stack	*first;
	t_stack	*second;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	first = *lst;
	second = (*lst)->next;
	if (second->next)
		second->next->previous = first;
	first->previous = second;
	first->next = second->next;
	second->previous = NULL;
	second->next = first;
	*lst = second;
}

void	sa(t_stack **lst)
{
	swap(lst);
	write(1, "sa\n", 3);
}

void	sb(t_stack **lst)
{
	swap(lst);
	write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
