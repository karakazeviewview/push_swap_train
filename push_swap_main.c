#include <libc.h>
#include <stdbool.h>
#include "libft/libft.h"
#include "push_swap.h"

typedef struct s_stack
{
	int				num;
	long			index;
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	is_sorted()

}

void	error_input_stack(t_stack *stack, size_t len)
{
	size_t	i;
	t_stack	*tmp;

	i = 0;
	while (i < len)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	return ;
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
			error_input_stack(stack, i);
		ft_lstadd_back(stack, new);
		i++;
	}
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
				min = stack->num;
			}
			tmp = tmp->next;
		}
		stack_min->index = i;
		i++;
	}
}

void	free_splited(char **str, int argc)
{
	if (argc == 2)
	{
		while (str && *str)
		{
			free(*str);
			*str++;
		}
		free(str);
	}
	return ;
}

void	error_argv(char **str, long *num, int argc)
{
	free_splited(str, argc);
	free(num);
	ft_putchar_fd("Error\n", 2);
	exit(1);
}

bool	check_dup(long *num, size_t len)
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
		if (!(*str <= '0' && *str <= '9'))
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
		i = 0;
		str = split(argv[1]);
	}
	else
	{
		i = 1;
		str = argv;
	}
	len = words_count(str - i);
	num = malloc(sizeof(long)  * len);
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
		if (!check_isnum(str[i]) && check_isover_int(num[j]))
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
	input_stack(&stack_a, argc);
	free_splited(str, argc);
	coordinate_compression(stack_a);
	stack_sort(&stack_a, &stack_b);

						if (is_sorted() != true)
						{
							if (argc != 2)
							{
								if (argc != 3)
								{
									if (!(argc <= 5))
									{
										radix_sort();
										free(stack_a);
									}
								}
							}
					}
	write(1, "error", 6);
	if (argc == 2)
	{
		free(splited);
	}
	exit (1);
	return (0);
}

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

int main(void)
{
	
	return (0);
}