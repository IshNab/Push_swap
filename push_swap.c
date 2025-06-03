/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inabakka <inabakka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:03:56 by inabakka          #+#    #+#             */
/*   Updated: 2025/05/28 14:50:40 by inabakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	push_swap(t_stack_node **a, t_stack_node **b)
{
    int	len = stack_len(*a);

    if (len <= 3)
    {
        small_sort(a);
        return;
    }

    int chunk_count = len > 100 ? 11 : 5;
    int chunk_size = len / chunk_count;
    int *sorted = stack_to_sorted_array(*a, len);

    for (int chunk = 0; chunk < chunk_count; chunk++)
    {
        int lower = chunk * chunk_size;
        int upper = (chunk == chunk_count - 1) ? len : (chunk + 1) * chunk_size;
        int pushed = 0;
        int to_push = upper - lower;

        // Keep looping until all values in this chunk are pushed
        while (pushed < to_push)
        {
            int idx = 0;
            t_stack_node *tmp = *a;
            // Find if any value in this chunk exists in stack a
            int found = 0;
            while (tmp)
            {
                int value = tmp->value;
                idx = 0;
                while (idx < len && value != sorted[idx])
                    idx++;
                if (idx >= lower && idx < upper)
                {
                    found = 1;
                    break;
                }
                tmp = tmp->next;
            }
            if (!found)
                break; // No more values in this chunk

            // If the top of a is in the chunk, push it
            int value = (*a)->value;
            idx = 0;
            while (idx < len && value != sorted[idx])
                idx++;
            if (idx >= lower && idx < upper)
            {
                pb(a, b);
                pushed++;
            }
            else
                ra(a, true);
        }
    }
    free(sorted);

    small_sort(a);

    // Push back from b to a in descending order
    while (*b)
    {
        int max = find_max(*b);
        int pos = find_position(*b, max);
        if (pos <= stack_len(*b) / 2)
            while ((*b)->value != max)
                rb(b, true);
        else
            while ((*b)->value != max)
                rrb(b, true);
        pa(a, b);
    }
}
