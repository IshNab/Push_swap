/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inabakka <inabakka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:05:14 by inabakka          #+#    #+#             */
/*   Updated: 2025/05/23 16:57:23 by inabakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_node **a, bool print)
{
	t_stack_node	*first;
	t_stack_node	*second;

	first = *a;
	second = first->next;
	if (!*a || !(*a)->next)
		return ;
	first->next = second->next; 	// Update prev/next pointers
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	*a = second;
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stack_node **b, bool print)
{
	t_stack_node	*first;
	t_stack_node	*second;

	first = *b;
	second = first->next;
	first->next = second->next;
	if (!*b || !(*b)->next)
		return ;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	*b = second;
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	sa(a, false);
	sb(b, false);
	write(1, "ss\n", 3);
}
