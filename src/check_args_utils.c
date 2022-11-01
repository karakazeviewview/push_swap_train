/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 05:36:49 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/11/01 18:22:21 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static bool	check_isdup(long *num, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (num[i] == num[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

static bool	check_isover_int(long num)
{
	if (num < INT_MIN || INT_MAX < num)
		return (true);
	return (false);
}

static bool	check_isnum(char *str)
{
	if (!str || !*str)
		return (false);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str < '0' || '9' < *str)
			return (false);
		str++;
	}
	return (true);
}
