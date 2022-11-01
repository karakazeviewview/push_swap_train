/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 05:37:00 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/11/01 18:17:54 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

size_t	words_count(char **str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (*str++)
		i++;
	return (i);
}
