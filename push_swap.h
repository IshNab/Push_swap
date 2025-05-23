/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inabakka <inabakka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:04:37 by inabakka          #+#    #+#             */
/*   Updated: 2025/05/23 16:53:44 by inabakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					final_index;
	int					push_cost;
	bool				above_middle;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

// Stack initialization and validation
int		stack_init(t_stack_node **a, char **argv, bool is_split);
bool	check_duplicates(t_stack_node *stack);
bool	check_input(char *str);
void	free_stack(t_stack_node **stack);
void	free_split(char **split);
long	ft_atol(const char *str);

// Stack utilities
t_stack_node	*get_stack_bottom(t_stack_node *stack);
t_stack_node	*get_stack_before_bottom(t_stack_node *stack);
void			append_node(t_stack_node **stack, int n);
int				stack_len(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
int				find_median(t_stack_node *stack);
t_stack_node		*find_max_node(t_stack_node *stack);
void			rotate_to_top(t_stack_node **b, t_stack_node *max_node);

// Algorithm
void	small_sort(t_stack_node **a);
void	sort_five(t_stack_node **a, t_stack_node **b);
void	push_swap(t_stack_node **a, t_stack_node **b);

//helper function
char	**ft_split(char const *s, char c);

//operations
void	sa(t_stack_node **a, bool print);
void	sb(t_stack_node **b, bool print);
void	ss(t_stack_node **a, t_stack_node **b);
void	pa(t_stack_node **a, t_stack_node **b);
void	pb(t_stack_node **a, t_stack_node **b);
void	ra(t_stack_node **a, bool print);
void	rb(t_stack_node **b, bool print);
void	rr(t_stack_node **a, t_stack_node **b);
void	rra(t_stack_node **a, bool print);
void	rrb(t_stack_node **b, bool print);
void	rrr(t_stack_node **a, t_stack_node **b);

// Error handling
void	error_exit(t_stack_node **a, t_stack_node **b, char **split, bool is_split);

#endif
