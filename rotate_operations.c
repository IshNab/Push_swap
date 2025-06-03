/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inabakka <inabakka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:04:43 by inabakka          #+#    #+#             */
/*   Updated: 2025/05/16 13:50:14 by inabakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_stack **a, bool print)
{
    if (!a || !a->top || !a->top->next)
        return;
        
    t_node *first = a->top;
    t_node *last = a->top;
    
    while (last->next)
        last = last->next;
    
    a->top = first->next;
    a->top->prev = NULL;
    first->next = NULL;
    first->prev = last;
    last->next = first;
    
    if (print)
        write(1, "ra\n", 3);
}

/* Rotate stack B - shift all elements up by 1 (first becomes last) */
void rb(t_stack **b, bool print)
{
    if (!b || !*b || !(*b)->top || !(*b)->top->next)
        return;
    
    t_node *first = (*b)->top;
    t_node *last = (*b)->top;
    
    // Find last node
    while (last->next)
        last = last->next;
    
    // Perform rotation
    (*b)->top = first->next;
    (*b)->top->prev = NULL;
    first->next = NULL;
    first->prev = last;
    last->next = first;
    
    if (print)
        write(1, "rb\n", 3);
}

/* Rotate both stacks A and B */
void rr(t_stack **a, t_stack **b)
{
    if (!a || !b || !*a || !*b)
        return;
    
    // Rotate both stacks without printing
    ra(a, false);
    rb(b, false);
    
    write(1, "rr\n", 3);
}

/* Reverse rotate stack A - shift all elements down by 1 (last becomes first) */
void rra(t_stack **a, bool print)
{
    if (!a || !*a || !(*a)->top || !(*a)->top->next)
        return;
    
    t_node *last = (*a)->top;
    t_node *second_last = NULL;
    
    // Find last and second last nodes
    while (last->next) {
        second_last = last;
        last = last->next;
    }
    
    // Perform reverse rotation
    last->next = (*a)->top;
    (*a)->top->prev = last;
    second_last->next = NULL;
    last->prev = NULL;
    (*a)->top = last;
    
    if (print)
        write(1, "rra\n", 4);
}

/* Reverse rotate stack B */
void rrb(t_stack **b, bool print)
{
    if (!b || !*b || !(*b)->top || !(*b)->top->next)
        return;
    
    t_node *last = (*b)->top;
    t_node *second_last = NULL;
    
    // Find last and second last nodes
    while (last->next) {
        second_last = last;
        last = last->next;
    }
    
    // Perform reverse rotation
    last->next = (*b)->top;
    (*b)->top->prev = last;
    second_last->next = NULL;
    last->prev = NULL;
    (*b)->top = last;
    
    if (print)
        write(1, "rrb\n", 4);
}

/* Reverse rotate both stacks A and B */
void rrr(t_stack **a, t_stack **b)
{
    if (!a || !b || !*a || !*b)
        return;
    
    // Reverse rotate both stacks without printing
    rra(a, false);
    rrb(b, false);
    
    write(1, "rrr\n", 4);
}  