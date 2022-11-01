/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:07:20 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/11/01 18:27:27 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

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

static bool	check_isover_int(long num)
{
	if (num < INT_MIN || INT_MAX < num)
		return (true);
	return (false);
}

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

static void	check_func(int argc, char **str, size_t len, size_t i)
{
	long	*num;
	size_t	j;

	num = malloc(sizeof(long) * len);
	if (!num)
	{
		free_splited(str, argc);
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	j = 0;
	while (str[i] != NULL)
	{
		num[j] = ft_atol(str[i]);
		if (!check_isnum(str[i]) || check_isover_int(num[j]))
			error_argv(str, num, argc);
		i++;
		j++;
	}
	if (check_isdup(num, len))
		error_argv(str, num, argc);
	free(num);
}

char	**check_argv(int argc, char **argv)
{
	char	**str;
	size_t	len;
	size_t	i;

	if (argc < 2)
		exit (1);
	else if (argc == 2)
	{
		if (argv[1][0] == '\0')
			error_argv(NULL, NULL, argc);
		i = 0;
		str = ft_split(argv[1], ' ');
		if (!str)
			error_argv(NULL, NULL, argc);
	}
	else
	{
		i = 1;
		str = argv;
	}
	len = words_count(str) - i;
	check_func(argc, str, len, i);
	return (str);
}
