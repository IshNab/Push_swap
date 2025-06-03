/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inabakka <inabakka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:04:37 by inabakka          #+#    #+#             */
/*   Updated: 2025/05/30 16:34:04 by inabakka         ###   ########.fr       */
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
char    **ft_split(char *str, char c);

#endif
