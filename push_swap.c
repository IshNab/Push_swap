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
}
