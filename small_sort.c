#include "push_swap.h"

// Helper function for sorting 3 elements
void small_sort(t_stack_node **a)
{
    int first = (*a)->value;
    int second = (*a)->next->value;
    int third = (*a)->next->next->value;
    
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