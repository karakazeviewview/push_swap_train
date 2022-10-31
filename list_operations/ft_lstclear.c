/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 02:12:12 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/11/01 02:12:13 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
void ft_lstclear(t_stack **lst, void (*del)(int))
{
	t_stack *tmp;

	if (!lst || !del || !*lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		(*del)((*lst)->num);
		free(*lst);
		*lst = NULL;
		*lst = tmp->next;
	}
}