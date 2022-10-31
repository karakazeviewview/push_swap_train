/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 05:36:32 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/11/01 06:50:50 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	three_sort(t_stack **stack)
{
	while (1)
	{
		if (is_sorted(*stack))
			break ;
		if ((*stack)->index < (*stack)->next->next->index)
			sa(stack);
		else
			ra(stack);
	}
	return ;
}

static void	five_sort(t_stack **stack_a, t_stack **stack_b, size_t len)
{
	long	i;

	i = 0;
	while (i < (long)(len - 3))
	{
		if ((*stack_a)->index == i)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else if ((*stack_a)->next->index == i || \
				(*stack_a)->next->next->index == i)
			ra(stack_a);
		else
			rra(stack_a);
	}
	three_sort(stack_a);
	pa(stack_a, stack_b);
	if (len == 5)
		pa(stack_a, stack_b);
	return ;
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	size_t	len;

	if (is_sorted(*stack_a))
		return ;
	len = ft_lstsize(*stack_a);
	if (len == 2)
		sa(stack_a);
	else if (len == 3)
		three_sort(stack_a);
	else if (len <= 5)
		five_sort(stack_a, stack_b, len);
	else
		radix_sort(stack_a, stack_b, len);
}
