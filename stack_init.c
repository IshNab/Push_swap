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

void free_stack(t_stack **stack)
{
    if (!stack || !*stack)
        return;
    
    t_node *current = (*stack)->top;
    t_node *tmp;
    
    while (current)
    {
        tmp = current->next;
        free(current);
        current = tmp;
    }
    
    free(*stack);
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

void append_node(t_stack **stack, int n)
{
    if (!stack)
        return;
    
    t_node *node = malloc(sizeof(t_node));
    if (!node)
        return; // or handle error
    
    node->value = n;
    node->next = NULL;
    node->prev = NULL;
    
    if (!*stack)
    {
        *stack = malloc(sizeof(t_stack));
        if (!*stack)
        {
            free(node);
            return; // or handle error
        }
        (*stack)->top = node;
        (*stack)->size = 1;
        return;
    }
    
    if (!(*stack)->top)
    {
        (*stack)->top = node;
        (*stack)->size = 1;
        return;
    }
    
    t_node *last = (*stack)->top;
    while (last->next)
        last = last->next;
    
    last->next = node;
    node->prev = last;
    (*stack)->size++;
}

int	stack_init(t_stack **a, char **argv, bool is_split)
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
