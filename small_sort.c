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

void	small_sort(t_stack_node **a)
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
