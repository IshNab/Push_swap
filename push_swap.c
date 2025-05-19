/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inabakka <inabakka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:03:56 by inabakka          #+#    #+#             */
/*   Updated: 2025/05/19 20:28:04 by inabakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Helper functions
int	stack_len(t_stack_node *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

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

// Main sorting algorithm
void	push_swap(t_stack_node **a, t_stack_node **b)
{
	int	len;
	int	median;

	len = stack_len(*a);
	t_stack_node *current = *a;

	// Find median
	int *arr = malloc(sizeof(int) * len);
	int i = 0;
	while (current)
	{
	arr[i++] = current->value;
	current = current->next;
	}
	// Simple bubble sort to find median
	for (i = 0; i < len - 1; i++)
		for (int j = 0; j < len - i - 1; j++)
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
	median = arr[len / 2];
	free(arr);
	// Push smaller numbers to stack b
	while (stack_len(*a) > 3)
	{
		if ((*a)->value < median)
			pb(a, b);
		else
			ra(a, true);
	}
	// Sort remaining 3 elements in stack a
	small_sort(a);
	// Push back elements from b to a in sorted order
	while (*b)
	{
		// Find the largest number in b
		t_stack_node *max_node = *b;
		t_stack_node *current = *b;
		while (current)
		{
			if (current->value > max_node->value)
				max_node = current;
			current = current->next;
		}
		// Rotate b until largest number is on top
		while (*b != max_node)
		{
			if (max_node->above_middle)
				rb(b, true);
			else
				rrb(b, true);
		}
		// Push to a
		pa(a, b);
	}
}
