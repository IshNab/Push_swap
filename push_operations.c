/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inabakka <inabakka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:04:28 by inabakka          #+#    #+#             */
/*   Updated: 2025/05/30 17:38:06 by inabakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*push_node;

	push_node = *b;
	if (!*b)
		return ;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	push_node->next = *a;
	if (*a)
		(*a)->prev = push_node;
	*a = push_node;
	push_node->prev = NULL;
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*push_node;

	push_node = *a;
	if (!*a)
		return ;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	push_node->next = *b;
	if (*b)
		(*b)->prev = push_node;
	*b = push_node;
	push_node->prev = NULL;
	write(1, "pb\n", 3);
}
