/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 02:14:24 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/11/01 19:17:02 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				num;
	long			index;
	struct s_stack	*next;
	struct s_stack	*previous;
}			t_stack;

t_stack			*ft_lstnew(int num);
void			ft_lstadd_front(t_stack **lst, t_stack *new);
size_t			ft_lstsize(t_stack *lst);
t_stack			*ft_lstfirst(t_stack *lst);
t_stack			*ft_lstlast(t_stack *lst);
void			ft_lstadd_back(t_stack **lst, t_stack *new);
void			ft_lstdelone(t_stack *lst, void (*del)(int));
void			ft_lstclear(t_stack **lst, void (*del)(int));
void			ft_lstiter(t_stack *lst, void (*f)(int));
t_stack			*ft_lstmap(t_stack *lst, int (*f)(int), void (*del)(int));
void			sa(t_stack **lst);
void			sb(t_stack **lst);
void			ss(t_stack **stack_a, t_stack **stack_b);
void			pa(t_stack **stack_a, t_stack **stack_b);
void			pb(t_stack **stack_a, t_stack **stack_b);
void			ra(t_stack **lst);
void			rb(t_stack **lst);
void			rr(t_stack **stack_a, t_stack **stack_b);
void			rra(t_stack **lst);
void			rrb(t_stack **lst);
void			rrr(t_stack **stack_a, t_stack **stack_b);
size_t			words_count(char **str);
char			**check_argv(int argc, char **argv);
void			coordinate_compression(t_stack *stack);
void			error_input_stack(t_stack *stack, size_t len, char **str, \
				int argc);
void			error_argv(char **str, long *num, int argc);
void			free_stack(t_stack *stack);
void			free_splited(char **str, int argc);
void			input_stack(t_stack **stack, char **str, int argc);
void			radix_sort(t_stack **stack_a, t_stack **stack_b, size_t len);
void			sort_stack(t_stack **stack_a, t_stack **stack_b);
bool			is_sorted(t_stack *stack);

#endif
