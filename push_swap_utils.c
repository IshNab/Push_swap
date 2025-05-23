/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inabakka <inabakka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:52:36 by inabakka          #+#    #+#             */
/*   Updated: 2025/05/23 16:55:21 by inabakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	sort_array(int *arr, int len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	find_median(t_stack_node *stack)
{
	int				len;
	int				*arr;
	int				i;
	int				median;
	t_stack_node	*current;

	len = stack_len(stack);
	arr = malloc(sizeof(int) * len);
	if (!arr)
		return (0);
	current = stack;
	i = 0;
	while (current)
	{
		arr[i++] = current->value;
		current = current->next;
	}
	sort_array(arr, len);
	median = arr[len / 2];
	free(arr);
	return (median);
}

t_stack_node	*find_max_node(t_stack_node *stack)
{
	t_stack_node	*max_node;
	t_stack_node	*current;

	max_node = stack;
	current = stack;
	while (current)
	{
		if (current->value > max_node->value)
			max_node = current;
		current = current->next;
	}
	return (max_node);
}

void	rotate_to_top(t_stack_node **b, t_stack_node *max_node)
{
	while (*b != max_node)
	{
		if (max_node->above_middle)
			rb(b, true);
		else
			rrb(b, true);
	}
}
