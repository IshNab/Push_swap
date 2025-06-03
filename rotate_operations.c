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

void ra(t_stack *a, bool print)
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

void rb(t_stack *b, bool print)
{
    if (!b || !b->top || !b->top->next)
        return;
        
    t_node *first = b->top;
    t_node *last = b->top;
    
    while (last->next)
        last = last->next;
    
    b->top = first->next;
    b->top->prev = NULL;
    first->next = NULL;
   