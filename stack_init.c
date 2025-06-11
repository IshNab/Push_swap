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

**where do these go?**
// void free_stack(t_stack **stack)
// {
//     if (!stack || !*stack)
//         return;
    
//     t_stack *current = (*stack)->top;
//     t_stack *tmp;
    
//     while (current)
//     {
//         tmp = current->next;
//         free(current);
//         current = tmp;
//     }
    
//     free(*stack);
//     *stack = NULL;
// }

// void	free_split(char **split)
// {
// 	int	i;

// 	i = 0;
// 	while (split[i])
// 	{
// 		free(split[i]);
// 		i++;
// 	}
// 	free(split);
// }

void append_node(t_stack_node **stack, int n)
{
    if (!stack)
        return;
    
    t_stack *node = malloc(sizeof(t_stack));
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
    
    t_stack *last = (*stack)->top;
    while (last->next)
        last = last->next;
    
    last->next = node;
    node->prev = last;
    (*stack)->size++;
}

int	stack_init_a(t_stack_node **a, char **argv, bool is_split)
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

t_stack_node	*return_cheapest(t_stack_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_stack_node **stack,
						t_stack_node *top_node,
						char stack_name) //Define a function that moves the required node to the top of the stack
{
	while (*stack != top_node) //Check if the required node is not already the first node
	{
		if (stack_name == 'a') //If not, and it is stack `a`, execute the following
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b') //If not, and it is stack `b`, execute the following
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}	
	}
}