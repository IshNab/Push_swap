/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inabakka <inabakka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:03:56 by inabakka          #+#    #+#             */
/*   Updated: 2025/05/28 15:03:46 by inabakka         ###   ########.fr       */
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

static void	push_to_b(t_stack_node **a, t_stack_node **b, int median)
{
	int	len;
	int	i;

	len = stack_len(*a);
	i = 0;
	while (i < len && stack_len(*a) > 3)
	{
		if ((*a)->value < median)
			pb(a, b);
		else
			ra(a, true);
		i++;
	}
}

static void	push_back_to_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*max_node;
//	int				len;

	while (*b)
	{
	//	len = stack_len(*b);
		max_node = find_max_node(*b);
		if (max_node->value == (*b)->value)
			pa(a, b);
		else if (max_node->value == (*b)->next->value)
		{
			sb(b, true);
			pa(a, b);
		}
		else
		{
			if (max_node->value > (*b)->value)
				rb(b, true);
			else
				rrb(b, true);
		}
	}
}

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	int	median;

	if (stack_len(*a) <= 3)
	{
		small_sort(a);
		return ;
	}
	median = find_median(*a);
	push_to_b(a, b, median);
	small_sort(a);
	push_back_to_a(a, b);
}
