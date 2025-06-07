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

t_stack	*find_last_node(t_stack *head)
{
	if (NULL == head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

int stack_len(t_stack *stack)
{
    if (!stack)
		return 0;
    return stack->size;  // O(1) access
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

int find_median(t_stack *stack)
{
    int *arr;
    int i, median;
    t_stack *current;

    if (!stack || !stack->top)
		return 0;
    arr = malloc(sizeof(int) * stack->size);
    if (!arr)
		return 0;
    current = stack->top;
    i = 0;
    while (current)
	{
        arr[i++] = current->value;  // Access via node
        current = current->next;    // Node's next pointer
    }
    sort_array(arr, stack->size);
    median = arr[stack->size / 2];
    free(arr);
    return median;
}

t_stack *find_max_node(t_stack *stack)
{  // Returns t_node*
    t_stack *max;
	t_stack *current;

    if (!stack || !stack->top)
		return NULL;
    max = stack->top;
    current = stack->top->next;
    
    while (current) {
        if (current->value > max->value)
            max = current;
        current = current->next;
    }
    return max;
}

char	*ft_substr(char const *string, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	string_len;
	size_t	i;

	if (!string)
		return (NULL);
	string_len = ft_strlen(string);
	if (start >= string_len)
		return (ft_strdup(""));
	if (len > string_len - start)
		len = string_len - start;
	sub_str = ft_calloc(len + 1, sizeof(char));
	if (!sub_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub_str[i] = string[start + i];
		i++;
	}
	return (sub_str);
}