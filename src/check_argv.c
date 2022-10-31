/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 05:37:00 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/11/01 06:46:42 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

char	**check_argv(int argc, char **argv)
{
	char	**str;
	long	*num;
	size_t	len;
	size_t	i;
	size_t	j;

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
	return (str);
}
