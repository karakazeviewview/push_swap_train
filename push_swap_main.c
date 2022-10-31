/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 02:17:55 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/11/01 02:17:56 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include <stdbool.h>
#include "libft/include/libft.h"
#include "push_swap.h"

void	free_splited(char **str, int argc);
bool	is_sorted(t_stack *stack);
void	three_sort(t_stack **stack);

void	radix_sort(t_stack **stack_a, t_stack **stack_b, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (1)
	{
		if (is_sorted(*stack_a))
			break ;
		j = 0;
		while (j < len)
		{
			if (!(((*stack_a)->index >> i) & 1))
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			j++;
		}
		while (j != 0)
		{
			pa(stack_a, stack_b);
			j--;
		}
		// printf("%p\n", stack_b);
		i++;
	}
	return ;
}

void	five_sort(t_stack **stack_a, t_stack **stack_b, size_t len)
{
	long	i;

	i = 0;
	while (i < (long)(len - 3))
	{
		if ((*stack_a)->index == i)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else if ((*stack_a)->next->index == i || (*stack_a)->next->next->index ==i)
			ra(stack_a);
		else
			rra(stack_a);
	}
	three_sort(stack_a);
	pa(stack_a, stack_b);
	if (len == 5)
		pa(stack_a, stack_b);
	return ;
}

void	three_sort(t_stack **stack)
{
	// if ((*stack)->index < (*stack)->next->index && (*stack)->next->index > (*stack)->next->next->index && )
	// {
	// 	rra(stack);
	// 	sa(stack);
	// }
	// else if ((*stack)->index > (*stack)->next->index && (*stack)->next->index < (*stack)->next->next->index)
	// 	sa(stack);
	// else if ((*stack)->index < (*stack)->next->index && (*stack)->next->index > (*stack)->next->next->index && (*stack)->index > (*stack)->next->next->index)
	// 	rra(stack);
	// else if ((*stack)->index > (*stack)->next->index && (*stack)->next->index < (*stack)->next->next->index)
	// {
	// 	rra(stack);
	// 	rra(stack);
	// }
	// else if ((*stack)->index > (*stack)->next->index && (*stack)->next->index > (*stack)->next->next->index)
	// {
	// 	sa(stack);
	// 	rra(stack);
	// }
	while (1)
	{
		if (is_sorted(*stack))
			break ;	
		if ((*stack)->index < (*stack)->next->next->index)
			sa(stack);
		else
			ra(stack);
	}
	return ;
	
}
/*
0 1 2
0 2 1
1 0 2
1 2 0
2 0 1
2 1 0
*/




void	free_stack(t_stack *stack)
{
	t_stack	 *tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	return ;
}

bool	is_sorted(t_stack *stack)
{
	if (!stack)
		return (false);
	while (stack->next)
	{
		if (stack->index > stack->next->index)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	size_t	len;

	if (is_sorted(*stack_a))
		return ;
	len = ft_lstsize(*stack_a);
	if (len == 2)
		sa(stack_a);
	else if (len == 3)
		three_sort(stack_a);
	else if (len <= 5)
		five_sort(stack_a, stack_b, len);
	else
		radix_sort(stack_a, stack_b, len);
}

void	error_input_stack(t_stack *stack, size_t len, char **str, int argc)
{
	size_t	i;
	t_stack	*tmp;

	i = 0;
	while (i < len)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
		i++;
	}
	free_splited(str, argc);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

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

void	coordinate_compression(t_stack *stack)
{
	size_t	len;
	int		min;
	t_stack	*stack_min;
	t_stack	*tmp;
	size_t	i;

	len = ft_lstsize(stack);
	i = 0;
	while (i < len)
	{
		tmp = stack;
		min = INT_MAX;
		while(tmp)
		{
			if (tmp->num <= min && tmp->index == -1)
			{
				stack_min = tmp;
				min = tmp->num;
			}
			tmp = tmp->next;
		}
		stack_min->index = i;
		i++;
	}
}

void	free_splited(char **str, int argc)
{
	size_t	i;

	i = 0;
	if (argc == 2)
	{
		while (str && str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
	return ;
}

void	error_argv(char **str, long *num, int argc)
{
	free_splited(str, argc);
	free(num);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

bool	check_isdup(long *num, size_t len)
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

bool	check_isover_int(long num)
{
	if (num < INT_MIN || INT_MAX < num)
		return (true);
	return (false);
}

bool	check_isnum(char *str)
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

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
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

	// while (stack_a)
	// {
	// 	printf("num\t\t= %d\n", stack_a->num);
	// 	printf("index\t\t= %ld\n", stack_a->index);
	// 	printf("previous\t= %p\n", stack_a->previous);
	// 	printf("ptr\t\t= %p\n", stack_a);
	// 	printf("next\t\t= %p\n", stack_a->next);
	// 	stack_a = stack_a->next;
	// }
	
//sort
//free(stack_a)
//exit(0)
// int main(int argc, char const *argv[])
// {
// 	char	**str;


// 	str = malloc(sizeof(char *) * 5);
// 	str[0] = "a";
// 	str[1] = "a";
// 	str[2] = "a";
// 	str[3] = "a";
// 	str[4] = NULL;
// 	printf("%zu\n", words_count(str));
// 	return 0;
// }

// ok check_isnum
// ok check_isover_int
// ok check_isdup