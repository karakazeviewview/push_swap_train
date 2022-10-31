/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 05:37:21 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/11/01 06:47:41 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	error_input_stack(t_stack *stack, size_t len, char **str, int argc)
{
	size_t	i;
	t_stack	*tmp;

	i = 0;
	while (i < len)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
		i++;
	}
	free_splited(str, argc);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	error_argv(char **str, long *num, int argc)
{
	free_splited(str, argc);
	free(num);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
