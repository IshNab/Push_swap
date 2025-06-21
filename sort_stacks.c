#include "push_swap.h"

static void	rotate_both(t_stack_node **a,
						t_stack_node **b,
						t_stack_node *cheapest_node) //Define a function that rotates both the top `a` and `b` nodes to the bottom of their stacks, if it's the cheapest move
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node) //As long as the current `b` node is not `a` cheapest node's target node, and the current top `a` node is not the top node
		rr(a, b, false); //Rotate both `a` and `b` nodes
	set_current_position(*a); //Refresh current node positions
	set_current_position(*b);
}

static void	rev_rotate_both(t_stack_node **a,
								t_stack_node **b,
								t_stack_node *cheapest_node) //Define a function that rotates both the bottom `a` and `b` nodes to the top of their stacks, if it's the cheapest move
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node) //As long as the current `b` node is not `a` cheapest node's target node && and the current `a` node is not the cheapest
		rrr(a, b, false); //Reverse rotate both `a` and `b` nodes
	set_current_position(*a); //Refresh current node positions
	set_current_position(*b);
}

static void	move_a_to_b(t_stack_node **a, t_stack_node **b) //Define a function that prepares the cheapest nodes on top of the stacks for pushing `a` nodes to stack `b`, until there are three nodes left in `a`
{
	t_stack_node	*cheapest_node; //To store the pointer to the cheapest `a` node

	if (!a || !b || !*a) // OPTIMIZATION: Added null checks
		return;
	cheapest_node = return_cheapest(*a); //Get the cheapest node from stack `a`
	if (!cheapest_node) // OPTIMIZATION: Check if cheapest node exists
		return;
	// OPTIMIZATION: Handle all rotation cases more efficiently
	if (cheapest_node->above_median == cheapest_node->target_node->above_median)
	{
		if (cheapest_node->above_median) //Both above median
			rotate_both(a, b, cheapest_node);
		else //Both below median
			rev_rotate_both(a, b, cheapest_node);
	}
	else // OPTIMIZATION: Handle mixed median cases separately
	{
		if (cheapest_node->above_median)
			ra(a, false);
		else
			rra(a, false);
		if (cheapest_node->target_node->above_median)
			rb(b, false);
		else
			rrb(b, false);
	}
	prep_for_push(a, cheapest_node, 'a'); //Ensure the cheapest node is at the top, ready for pushing
	prep_for_push(b, cheapest_node->target_node, 'b'); //Ensure the target node is at the top, ready for pushing
	pb(b, a, false); //Push from `a` to `b`
}

static void	move_b_to_a(t_stack_node **a, t_stack_node **b) //Define a function that prepares `b`'s target `a` nodes for pushing all `b` nodes back to stack `a` 
{
	if (!b || !*b) // OPTIMIZATION: Added null check
		return;
	prep_for_push(a, (*b)->target_node, 'a'); //Ensure `b`'s target `a` node is on top of the stack
	pa(a, b, false); //Push from `b` to `a`
}

static void	min_on_top(t_stack_node **a) //Define a function that moves the smallest number to the top
{
	t_stack_node	*smallest; // OPTIMIZATION: Cache smallest node

	if (!a || !*a) // OPTIMIZATION: Added null check
		return;
	smallest = find_smallest(*a); //Find once instead of repeatedly
	if (!smallest)
		return;
	while ((*a)->nbr != smallest->nbr) //As long as the smallest number is not at the top
	{
		if (smallest->above_median) //Rotate or reverse rotate according to the position of the node on the median
			ra(a, false);
		else
			rra(a, false);
	}
}

void	sort_stacks(t_stack_node **a, t_stack_node **b) //Define a function that sorts stack `a` if it has more than 3 nodes
{
	int	len_a; //To store the length of stack `a`

	if (!a || !b) // OPTIMIZATION: Added null checks
		return;
	len_a = stack_len(*a);
	// OPTIMIZATION: Push more elements initially if stack is large
	if (len_a > 5 && !stack_sorted(*a))
	{
		pb(b, a, false);
		pb(b, a, false);
		pb(b, a, false);
		len_a -= 3;
	}
	else if (len_a-- > 3 && !stack_sorted(*a)) //If stack `a` has more than three nodes and aren't sorted
		pb(b, a, false);
	if (len_a-- > 3 && !stack_sorted(*a)) //If stack `a` still has more than three nodes and aren't sorted
		pb(b, a, false);
	while (len_a-- > 3 && !stack_sorted(*a)) //If stack `a` still has more than three nodes and aren't sorted
	{
		init_nodes_a(*a, *b); //Initiate all nodes from both stacks
		move_a_to_b(a, b); //Move the cheapest `a` nodes into a sorted stack `b`, until three nodes are left in stack `a`
	}
	sort_three(a); //Sort the remaining three nodes in `a`
	while (*b) //Until the end of stack `b` is reached
	{
		init_nodes_b(*a, *b); //Initiate all nodes from both stacks
		move_b_to_a(a, b); //Move all `b` nodes back to a sorted stack `a`
	}
	set_current_position(*a); //Refresh the current position of stack `a`
	min_on_top(a); //Ensure smallest number is on top
}