/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 05:37:43 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/11/01 06:48:40 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	input_stack(t_stack **stack, char **str, int argc)
{
	t_stack	*new;
	size_t	i;

	i = 1;
	if (argc == 2)
		i = 0;
	while (str && str[i])
	{
		new = ft_lstnew(ft_atoi(str[i]));
		if (!new)
			error_input_stack(*stack, i, str, argc);
		ft_lstadd_back(stack, new);
		i++;
	}
	free_splited(str, argc);
	return ;
}
