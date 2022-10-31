/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 05:37:51 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/11/01 06:49:17 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**str;

	stack_a = NULL;
	stack_b = NULL;
	str = check_argv(argc, argv);
	input_stack(&stack_a, str, argc);
	coordinate_compression(stack_a);
	sort_stack(&stack_a, &stack_b);
	free_stack(stack_a);
	return (0);
}

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q push_swap");
// }
