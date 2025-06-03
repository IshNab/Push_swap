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

void	sort_three(t_stack_node **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
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

void	sort_four_or_five(t_stack_node **a, t_stack_node **b)
{
	int	min;

	// Push 1-2 smallest elements to B
	while (stack_len(*a) > 3)
	{
		min = find_min(*a);
		if ((*a)->value == min)
			pb(a, b);
		else
			ra(a, true);
	}

	// Sort remaining 3 elements in A
	sort_three(a);

	// Push back from B to A (in order)
	while (*b)
		pa(a, b);

	// Final rotate to order A (if needed)
	if (!stack_sorted(*a))
		ra(a, true);
}
