/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inabakka <inabakka@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:04:43 by inabakka          #+#    #+#             */
/*   Updated: 2025/05/16 13:04:45 by inabakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_stack_node **a, bool print)
{
    if (!*a || !(*a)->next)
        return;
        
    t_stack_node *first = *a;
    t_stack_node *last = *a;
    
    while (last->next)
        last = last->next;
    
    *a = first->next;
    (*a)->prev = NULL;
    first->next = NULL;
    first->prev = last;
    last->next = first;
    
    if (print)
        write(1, "ra\n", 3);
}

void rb(t_stack_node **b, bool print)
{
    if (!*b || !(*b)->next)
        return;
        
    t_stack_node *first = *b;
    t_stack_node *last = *b;
    
    while (last->next)
        last = last->next;
    
    *b = first->next;
    (*b)->prev = NULL;
    first->next = NULL;
    first->prev = last;
    last->next = first;
    
    if (print)
        write(1, "rb\n", 3);
}

void rr(t_stack_node **a, t_stack_node **b)
{
    ra(a, false);
    rb(b, false);
    write(1, "rr\n", 3);
}

void rra(t_stack_node **a, bool print)
{
    if (!*a || !(*a)->next)
        return;
        
    t_stack_node *last = *a;
    t_stack_node *second_last = NULL;
    
    while (last->next)
    {
        second_last = last;
        last = last->next;
    }
    
    last->next = *a;
    (*a)->prev = last;
    last->prev = NULL;
    second_last->next = NULL;
    *a = last;
    
    if (print)
        write(1, "rra\n", 4);
}

void rrb(t_stack_node **b, bool print)
{
    if (!*b || !(*b)->next)
        return;
        
    t_stack_node *last = *b;
    t_stack_node *second_last = NULL;
    
    while (last->next)
    {
        second_last = last;
        last = last->next;
    }
    
    last->next = *b;
    (*b)->prev = last;
    last->prev = NULL;
    second_last->next = NULL;
    *b = last;
    
    if (print)
        write(1, "rrb\n", 4);
}

void rrr(t_stack_node **a, t_stack_node **b)
{
    rra(a, false);
    rrb(b, false);
    write(1, "rrr\n", 4);
}

