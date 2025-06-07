/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inabakka <inabakka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:03:56 by inabakka          #+#    #+#             */
/*   Updated: 2025/05/28 15:03:46 by inabakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_chunks_to_b(t_stack **a, t_stack **b, int chunk_size);
void sort_and_push_back(t_stack **a, t_stack **b);

// Main sorting function
// void push_swap(t_stack **a, t_stack **b)
// {
//     if (stack_sorted(*a)) // expects t_stack *, so pass *a
//         return;
    
//     int size = (*a)->size; // a is t_stack **, so use (*a)->size
    
//     if (size <= 3)
//         sort_three(a); // expects t_stack **, so pass a
//     else if (size <= 5)
//         sort_five(a, b); // expects t_stack **, so pass a and b
//     else
//     {
//         // Determine optimal chunk size based on input size
//         int chunk_size = (size <= 100) ? 15 : 30;
        
//         // Phase 1: Push elements to stack B in chunks
//         push_chunks_to_b(a, b, chunk_size); // expects t_stack **, so pass a and b
        
//         // Phase 2: Sort and push back to stack A
//         sort_and_push_back(a, b); // expects t_stack **, so pass a and b
//     }
// }

// Push elements to stack B in chunks
// void push_chunks_to_b(t_stack **a, t_stack **b, int chunk_size)
// {
//     int min;
//     int max;
//     int pushed;
//     int chunk_count = 0;
//     int total_chunks = ((*a)->size / chunk_size) + 1;
    
//     while (chunk_count < total_chunks && (*a)->size > 3)
//     {
//         min = get_min(*a); // expects t_stack *, so pass *a
//         max = get_max(*a); // expects t_stack *, so pass *a
//         int chunk_min = min + (chunk_count * chunk_size);
//         int chunk_max = chunk_min + chunk_size;
//         if (chunk_max > max)
//             chunk_max = max;
        
//         pushed = 0;
//         while (pushed < chunk_size && (*a)->size > 3)
//         {
//             int current = (*a)->top->value;
//             if (current >= chunk_min && current <= chunk_max)
//             {
//                 pb(a, b);
//                 pushed++;
//                 // Rotate to keep larger numbers at bottom of B
//                 if ((*b)->size > 1 && current < chunk_min + (chunk_size / 2))
//                     rb(b, true); // pass bool print
//                 else
//                     ra(a, true); // pass bool print
//             }
//             else
//                 ra(a, true);
//         }
//         chunk_count++;
//     }
// }

// Sort stack B and push elements back to stack A
void sort_and_push_back(t_stack **a, t_stack **b)
{
    while ((*b)->size > 0)
    {
        int max = get_max(*b); // expects t_stack *, so pass *b
        int position = 0;
        t_node *current = (*b)->top;
     
        // Find position of max value in stack B
        while (current && current->value != max)
        {
            position++;
            current = current->next;
        }
        
        // Rotate stack B to bring max to top
        if (position <= (*b)->size / 2)
            while ((*b)->top->value != max)
                rb(b, true);
        else
            while ((*b)->top->value != max)
                rrb(b, true);
        pa(a, b);
    }
}

// Helper function to get minimum value in stack
int get_min(t_stack *s)
{
    t_node *current = s->top;
    int min = INT_MAX;

    while (current)
    {
        if (current->value < min)
            min = current->value;
        current = current->next;
    }
    return min;
}

// Helper function to get maximum value in stack
int get_max(t_stack *s)
{
    t_node *current = s->top;
    int max = INT_MIN;
    
    while (current)
    {
        if (current->value > max)
            max = current->value;
        current = current->next;
    }
    return max;
}