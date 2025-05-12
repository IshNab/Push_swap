#include "push_swap.h"

void pa(t_stack_node **a, t_stack_node **b)
{
    if (!*b)
        return;
        
    t_stack_node *push_node = *b;
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

void pb(t_stack_node **a, t_stack_node **b)
{
    if (!*a)
        return;
        
    t_stack_node *push_node = *a;
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