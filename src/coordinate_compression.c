/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_compression.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 05:37:14 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/11/01 06:47:15 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	coordinate_compression(t_stack *stack)
{
	size_t	len;
	int		min;
	t_stack	*stack_min;
	t_stack	*tmp;
	size_t	i;

	len = ft_lstsize(stack);
	i = 0;
	while (i < len)
	{
		tmp = stack;
		min = INT_MAX;
		while (tmp)
		{
			if (tmp->num <= min && tmp->index == -1)
			{
				stack_min = tmp;
				min = tmp->num;
			}
			tmp = tmp->next;
		}
		stack_min->index = i;
		i++;
	}
}
