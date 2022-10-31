/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 02:18:01 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/11/01 02:18:02 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void free_num(void **num)
{
	size_t i;

	i = 0;
	while (num[i])
	{
		free(num[i]);
		i++;
	}
	free(num);
}

static void input_argv_to_stack(int argc, const char **num, t_stack **stack)
{
	size_t i;
	t_stack *tmp;

	i = 1;
	if (argc == 2)
		i = 0;
	while (num[i])
	{
		tmp = ft_lstnew(ft_atoi(num[i]));
		if (!tmp && argc == 2)
			free_num(num);
		if (!tmp)
			malloc_error(stack);
		ft_lstadd_back(stack, tmp);
		i++;
	}
	return ;
}

int main(int argc, char const **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	const char **num;

	stack_a = NULL;
	stack_b = NULL;
	num = check_args(argc, argv);
	if (!num)
		return (1);
	input_argv_to_stack(argc, num, &stack_a);
	if (num != argv)
		free_num((void **)num);
	// sort_stack(&stack_a, &stack_b);
	return (0);
}