/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inabakka <inabakka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:52:36 by inabakka          #+#    #+#             */
/*   Updated: 2025/05/30 12:55:10 by inabakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

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

<<<<<<< HEAD
// Returns a sorted array of the stack's values
int	*stack_to_sorted_array(t_stack_node *stack, int len)
{
    int	*arr = malloc(sizeof(int) * len);
    int	i = 0;
    t_stack_node *tmp = stack;

    if (!arr)
        return (NULL);
    while (tmp)
    {
        arr[i++] = tmp->value;
        tmp = tmp->next;
    }
    // Simple bubble sort (replace with quicksort for large stacks)
    for (int j = 0; j < len - 1; j++)
    {
        for (int k = 0; k < len - j - 1; k++)
        {
            if (arr[k] > arr[k + 1])
            {
                int temp = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = temp;
            }
        }
    }
    return arr;
}

// Returns the maximum value in the stack
int	find_max(t_stack_node *stack)
{
    int	max = stack->value;
    while (stack)
    {
        if (stack->value > max)
            max = stack->value;
        stack = stack->next;
    }
    return max;
}

// Returns the position (0-based) of value in the stack
int	find_position(t_stack_node *stack, int value)
{
    int	pos = 0;
    while (stack)
    {
        if (stack->value == value)
            return pos;
        pos++;
        stack = stack->next;
    }
    return -1; // Not found
}

// Quick sort helper
static void	quick_sort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
        int tmp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = tmp;
        int pi = i + 1;
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

// Replace bubble sort with quick sort in sort_array
=======
>>>>>>> c083e4b6398d73946c3483f7b79f62f5497a26e8
static void	sort_array(int *arr, int len)
{
    quick_sort(arr, 0, len - 1);
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
