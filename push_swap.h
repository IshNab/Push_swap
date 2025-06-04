/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inabakka <inabakka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:04:37 by inabakka          #+#    #+#             */
/*   Updated: 2025/05/23 17:08:51 by inabakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_node
{
    int value;
    struct s_node *next;
    struct s_node *prev;
} t_node;

typedef struct s_stack
{
    t_node *top;
    int size;
} t_stack;

// Stack operations
void    pa(t_stack **a, t_stack **b);
void    pb(t_stack **a, t_stack **b);
void    sa(t_stack **a, bool print);
void    sb(t_stack **b, bool print);
void    ss(t_stack **a, t_stack **b);
void    ra(t_stack **a, bool print);
void    rb(t_stack **b, bool print);
void    rr(t_stack **a, t_stack **b);
void    rra(t_stack **a, bool print);
void    rrb(t_stack **b, bool print);
void    rrr(t_stack **a, t_stack **b);

// Helper functions
int     stack_init(t_stack **a, char **argv, bool is_split);
int     stack_len(t_stack *stack);
int     is_sorted(t_stack *a);
int     get_min(t_stack *s);
int     get_max(t_stack *s);
int     get_median(t_stack *s, int size);
void    push_swap(t_stack **a, t_stack **b);
void    free_split(char **split);
void    free_stack(t_stack **stack);
void    append_node(t_stack **stack, int n);
void    sort_three(t_stack **a);
void    sort_five(t_stack **a, t_stack **b);
void	error_exit(t_stack **a, t_stack **b,
	char **split, bool is_split);
char    **ft_split(char *str, char c);
long	ft_atol(const char *str);
<<<<<<< HEAD
bool	check_input(char *str);
bool    check_duplicates(t_stack *stack);
=======

// Stack utilities
t_stack_node	*get_stack_bottom(t_stack_node *stack);
t_stack_node	*get_stack_before_bottom(t_stack_node *stack);
t_stack_node	*find_max_node(t_stack_node *stack);

// more stack utilities
void	append_node(t_stack_node **stack, int n);
int		stack_len(t_stack_node *stack);
int		find_median(t_stack_node *stack);
bool	stack_sorted(t_stack_node *stack);
void	rotate_to_top(t_stack_node **b, t_stack_node *max_node);

// Algorithm
void	small_sort(t_stack_node **a);
void	sort_five(t_stack_node **a, t_stack_node **b);
void	push_swap(t_stack_node **a, t_stack_node **b);

// Helper function
char	**ft_split(char const *s, char c);

// Operations
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
void	error_exit(t_stack_node **a, t_stack_node **b,
			char **split, bool is_split);
>>>>>>> parent of c083e4b (update)

#endif
