/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inabakka <inabakka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:03:56 by inabakka          #+#    #+#             */
/*   Updated: 2025/05/30 17:16:10 by inabakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_swap(t_stack_node **a, t_stack_node **b)
{
	int i = 0;
	if (stack_sorted(*a))
		return;
	if (stack_len(*a) <= 5)
	{
		small_sort(a);
		return;
	}
	// 2. Push chunks to B (multi-median partitioning)
	int chunks = 4; // Adjust based on stack size
	while (i < chunks)
	{
		int min = /* min of current chunk */;
		int max = /* max of current chunk */;
		push_chunk_to_b(a, b, min, max);
		i++;
	}
	// 3. Sort A (now only largest elements remain)
	small_sort(a);

    // 4. Push back from B (already in descending order)
	while (*b)
		pa(a, b);
}

<<<<<<< HEAD
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
=======
// Push a chunk of A (between min/max) to B, keeping B sorted in reverse
void push_chunk_to_b(t_stack_node **a, t_stack_node **b, int min, int max) {
	int i = 0;
	int len = stack_len(*a);
	while (i < len && stack_len(*a) > 3) {
		if ((*a)->value >= min && (*a)->value <= max) {
			pb(a, b);
			if (*b && (*b)->next && (*b)->value < (*b)->next->value)
				sb(b); // Keep B in descending order
		} else {
			ra(a);
		}
		i++;
	}
>>>>>>> c083e4b6398d73946c3483f7b79f62f5497a26e8
}
