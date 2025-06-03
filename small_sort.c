/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inabakka <inabakka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:05:02 by inabakka          #+#    #+#             */
/*   Updated: 2025/05/30 17:16:43 by inabakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Sort stack with 3 elements
void sort_three(t_stack *a)
{
    int first;
    int second;
    int third;

	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
    
    if (first > second && second < third && first < third)
        sa(a);
    else if (first > second && second > third)
    {
        sa(a);
        rra(a);
    }
    else if (first > second && second < third && first > third)
        ra(a);
    else if (first < second && second > third && first < third)
    {
        sa(a);
        ra(a);
    }
    else if (first < second && second > third && first > third)
        rra(a);
}

// Sort stack with 5 elements
void sort_five(t_stack *a, t_stack *b)
{
    int pushed = 0;
    // Push 2 smallest elements to stack B
    while (pushed < 2)
    {
        int min = get_min(a);
        if (a->top->value == min)
        {
            pb(a, b);
            pushed++;
        }
        else
            ra(a);
    }
    
    // Sort remaining 3 elements in stack A
    sort_three(a);
    
    // Push elements back from stack B
    while (b->size > 0)
        pa(a, b);
}
