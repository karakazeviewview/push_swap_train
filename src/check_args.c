/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 02:16:54 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/11/01 02:16:55 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int check_isnum(const char *s)
{
	if (!s)
		return (1);
	if (*s == '-')
		s++;
	if (!*s)
		return (1);
	while (*s)
	{
		if (!ft_isdigit(*s++))
			return (1);
	}
	return (0);
}

static int check_over_int(long num)
{
	if (num < INT_MIN)
		return (1);
	if (INT_MAX < num)
		return (1);
	return (0);
}

static void scan_num(const char **num, int argc)
{
	size_t i;

	i = 1;
	if (argc == 2)
		i = 0;
	while (num[i])
	{
		if (check_over_int(ft_atoi(num[i])) || check_isnum(num[i]))
			error_argv();
		i++;
	}
}

const char **check_args(int argc, const char **argv)
{
	const char **num;

	if (argc < 2)
		exit (1);
	else if (argc == 2)
	{
		num = (const char **)ft_split(argv[1], ' ');
		if (!num)
			malloc_error(NULL);
		scan_num(num, argc);
		return (num);
	}
	scan_num(argv, argc);
	return (argv);
}

#include <stdio.h>

int main(int argc, const char **argv)
{
	const char **num;
	int i;

	num = check_args(argc, argv);
	i = 0;
	while (num[i])
	{
		printf("%s\n", num[i]);
		i++;
	}
	i = 0;
	while (argv[i])
	{
		printf("%s\n", argv[i]);
		i++;
	}
	return (0);
}