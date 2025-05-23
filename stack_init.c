/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inabakka <inabakka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:05:08 by inabakka          #+#    #+#             */
/*   Updated: 2025/05/23 14:02:34 by inabakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last;

	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->value = n;
	node->next = NULL;
	node->prev = NULL;
	if (!*stack)
	{
		*stack = node;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = node;
	node->prev = last;
}

int	stack_init(t_stack_node **a, char **argv, bool is_split)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (!check_input(argv[i]))
			error_exit(a, NULL, argv, is_split);
		n = ft_atol(argv[i]);
		append_node(a, (int)n);
		i++;
	}
	if (check_duplicates(*a))
		error_exit(a, NULL, argv, is_split);
	return (1);
}
