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
# include <stddef.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_stack
{
	struct s_stack *top;    // Pointer to top node
    int size; 
    int					value;
	int					current_position;
	int					final_index;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

// Stack operations
void	pa(t_stack **a, t_stack **b, bool checker);
void	pb(t_stack **b, t_stack **a, bool checker);
void    sa(t_stack **a, bool print);
void    sb(t_stack **b, bool print);
void    ss(t_stack **a, t_stack **b);
void	ra(t_stack **a, bool checker);
void	rb(t_stack **b, bool checker);
void	rr(t_stack **a, t_stack **b, bool checker);
void	rra(t_stack **a, bool checker);
void	rrb(t_stack **b, bool checker);
void	rrr(t_stack **a, t_stack **b, bool checker);

// Helper functions
int     stack_init(t_stack **a, char **argv, bool is_split);
int     stack_len(t_stack *stack);
bool	stack_sorted(t_stack *stack);
int     get_min(t_stack *s);
int     get_max(t_stack *s);
int     get_median(t_stack *s, int size);
//void    push_swap(t_stack **a, t_stack **b);
void    free_split(char **split);
void    free_stack(t_stack **stack);
void    append_node(t_stack **stack, int n);
void    sort_three(t_stack **a);
void    sort_five(t_stack **a, t_stack **b);
void	error_exit(t_stack **a, t_stack **b,
	char **split, bool is_split);
char    **ft_split(char const *str, char c);
long	ft_atol(const char *str);
bool	check_input(char *str);
bool    check_duplicates(t_stack *stack);
char	*ft_substr(char const *string, unsigned int start, size_t len);

//push_swap_utils_2.c
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *src);
int     ft_strlen(const char *str);
t_stack	*find_smallest(t_stack *stack);
t_stack	*return_cheapest(t_stack *stack);

//oceano utils
void	push_swap(t_stack **a, t_stack **b);
void	finish_rotation(t_stack **stack,
							t_stack *top_node,
							char stack_name);
void	set_current_position(t_stack *stack);
void	set_price(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *b);
void	init_nodes(t_stack *a, t_stack *b);
t_stack	*find_last_node(t_stack *head);

#endif