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

typedef struct s_node {
    int value;
    struct s_node *next;
    struct s_node *prev;
} t_node;

typedef struct s_stack {
    t_node *top;
    int size;
} t_stack;

// Stack operations
void    pa(t_stack *a, t_stack *b);
void    pb(t_stack *a, t_stack *b);
void    sa(t_stack *a, bool print);
void	sb(t_stack *b, bool print);
void    ss(t_stack *a, t_stack *b);
void    ra(t_stack *a, bool print);
void    rb(t_stack_node *b, bool print);
void    rr(t_stack *a, t_stack *b);
void    rra(t_stack_node *a, bool print);
void    rrb(t_stack_node *b, bool print);
void    rrr(t_stack *a, t_stack *b);

// Helper functions
void init_stack(t_stack *stack, int argc, char **argv);
int is_sorted(t_stack *a);
int get_min(t_stack *s);
int get_max(t_stack *s);
int get_median(t_stack *s, int size);
void sort_three(t_stack *a);
void sort_five(t_stack *a, t_stack *b);
void push_chunks_to_b(t_stack *a, t_stack *b, int chunk_size);
void sort_and_push_back(t_stack *a, t_stack *b);

#endif
