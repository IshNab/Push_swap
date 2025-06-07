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

// In your header file:
typedef struct s_node {
    int value;
    struct s_node *next;
    struct s_node *prev;  // Only if you need doubly-linked
} t_node;

typedef struct s_stack {
    t_node *top;    // Pointer to top node
    int size;       // Number of elements
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
bool	stack_sorted(t_stack *stack);
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
char    **ft_split(char const *str, char c);
long	ft_atol(const char *str);
bool	check_input(char *str);
bool    check_duplicates(t_stack *stack);
char	*ft_substr(char const *string, unsigned int start, size_t len);

//push_swap_utils_2.c
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *src);
int     ft_strlen(const char *str);

#endif