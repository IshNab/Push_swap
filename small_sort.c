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

void sort_five(t_stack **a, t_stack **b)
{
    int pushed = 0;
    int rotations = 0;
    int stack_size = stack_len(*a);

    if (stack_size != 5)
        return; // Only works for exactly 5 elements

    // Push 2 smallest elements to stack B
    while (pushed < 2)
    {
        int min = get_min(*a);
        if ((*a)->top->value == min)
        {
            pb(a, b, true); //is this supposed to be false?
            pushed++;
            rotations = 0; // Reset rotation counter after successful push
        }
        else
        {
            ra(a, true);
            rotations++;
            // Prevent infinite loop: if rotated full cycle without finding min
            if (rotations >= stack_size)
                break;
        }
    }

    // Sort remaining 3 elements in stack A
    sort_three(a);

    // Push back elements from stack B
    while (*b && (*b)->size > 0)
        pa(a, b, true); //is this supposed to be false?
}
