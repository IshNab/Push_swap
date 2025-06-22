/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inabakka <inabakka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:05:02 by inabakka          #+#    #+#             */
/*   Updated: 2025/05/23 16:21:23 by inabakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Sort stack with 3 elements
void sort_three(t_stack_node **a)
{
    if (!a || !*a || !(*a)->next || !(*a)->next->next)
        return;

    int first = (*a)->nbr;               // First node's value
    int second = (*a)->next->nbr;        // Second node's value
    int third = (*a)->next->next->nbr;   // Third node's value

    if (first > second && second < third && first < third)
        sa(a, true);
    else if (first > second && second > third)
    {
        sa(a, true);
        rra(a, true);
    }
    else if (first > second && second < third && first > third)
        ra(a, true);
    else if (first < second && second > third && first < third)
    {
        sa(a, true);
        ra(a, true);
    }
    else if (first < second && second > third && first > third)
        rra(a, true);
}

// void	sort_three(t_stack_node **a) //Define a function that handles when stack `a` has three nodes, and sorts it
// {
// 	t_stack_node	*biggest_node; //To store a pointer to the biggest node in stack `a`
// 	biggest_node = find_max_node(*a);
// 	if (biggest_node == *a) //Check if the current node is the biggest
// 		ra(a, true); //If so, rotate the top node to the bottom of the stack
// 	else if ((*a)->next == biggest_node) //Check if the second node is the biggest
// 		rra(a, true); //If so, reverse rotate the bottom node, to the top of the stack
// 	if ((*a)->nbr > (*a)->next->nbr) //Check if the bottom node is the biggest, but the top node is higher than the second node
// 		sa(a, true); //If so, simply swap the top and second nodes
// }