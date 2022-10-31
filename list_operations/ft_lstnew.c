/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 02:12:53 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/11/01 02:12:54 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
t_stack *ft_lstnew(int num)
{
	t_stack *new;
	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->num = num;
	new->index = -1;
	new->next = NULL;
	new->previous = NULL;
	return (new);
}

// #include <stdio.h>
// #include <limits.h>	
// #include <stdint.h>
// int main(void)
// {
// 	t_stack *ptr;
// 	ptr = ft_lstnew(1);
// 	printf("%d\n", ptr->num);
// 	free(ptr);
// 	ptr = NULL;
// 	return (0);
// }