/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inabakka <inabakka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:04:28 by inabakka          #+#    #+#             */
/*   Updated: 2025/05/30 17:38:06 by inabakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    pa(t_stack **a, t_stack **b)
{
    t_node *push_node;
    
    if (!b || !b->top)
        return;
    
    push_node = b->top;
    b->top = b->top->next;
    if (b->top)
        b->top->prev = NULL;
    
    push_node->next = a->top;
    if (a->top)
        a->top->prev = push_node;
    a->top = push_node;
    push_node->prev = NULL;
    
    a->size++;
    b->size--;
    write(1, "pa\n", 3);
}

void    pb(t_stack **a, t_stack **b)
{
    t_node *push_node;
    
    if (!a || !a->top)
        return;
    
    push_node = a->top;
    a->top = a->top->next;
    if (a->top)
        a->top->prev = NULL;
    
    push_node->next = b->top;
    if (b->top)
        b->top->prev = push_node;
    b->top = push_node;
    push_node->prev = NULL;
    
    b->size++;
    a->size--;
    write(1, "pb\n", 3);
}
