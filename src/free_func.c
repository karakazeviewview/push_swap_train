/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 05:37:35 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/11/01 06:48:10 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	return ;
}

void	free_splited(char **str, int argc)
{
	size_t	i;

	i = 0;
	if (argc == 2)
	{
		while (str && str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
	return ;
}
