/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inabakka <inabakka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:05:02 by inabakka          #+#    #+#             */
/*   Updated: 2025/05/23 16:21:23 by inabakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Sort stack with 3 elements
void sort_three(t_stack **a)
{
    int first = (*a)->top->value;
    int second = (*a)->top->next->value;
    int third = (*a)->top->next->next->value;

    if (first > second && second < third && first < third)
        sa(a, true);
    else if (first > second && second > third)
    {
        sa(a, true);
        rra(a, true);
    }
    else if (first > second && second < third && first > third)
        ra(a, true);
    else if (first < second && second > third && first < third)
    {
        sa(a, true);
        ra(a, true);
    }
    else if (first < second && second > third && first > third)
        rra(a, true);
}

// Sort stack with 5 elements
void sort_five(t_stack **a, t_stack **b)
{
    int pushed = 0;
    // Push 2 smallest elements to stack B
    while (pushed < 2)
    {
        int min = get_min(*a);
        if ((*a)->top->value == min)
        {
            pb(a, b);
            pushed++;
        }
        else
            ra(a, true);
    }

    // Sort remaining 3 elements in stack A
    sort_three(a);

    // Push elements back from stack B
    while ((*b)->size > 0)
        pa(a, b);
}
