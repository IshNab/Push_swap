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