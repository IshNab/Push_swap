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
#include <stdlib.h>

int	stack_len(t_stack *stack)
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
