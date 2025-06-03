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

// Helper function to check if stack is sorted
int is_sorted(t_stack *a)
{
    t_node *current = a->top;
    
    while (current && current->next)
    {
        if (current->value > current->next->value)
            return 0;
        current = current->next;
    }
    return 1;
}
