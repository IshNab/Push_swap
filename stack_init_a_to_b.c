#include "push_swap.h"

/*
 * Set the current position of every node 
 * in the current state-configuration
*/
void	set_current_position(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (NULL == stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

/*
 *	Best match is..
 *   | "The Smallest-bigger value" |
 *
 *  if no node is Bigger, best_match is the Smallest node.
 *  TLDR 
 *  With this function every node in b gets its target node in a
*/
static void	set_target_node(t_stack_node *a,
							t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr > b->nbr
				&& current_a->nbr < best_match_index)
			{
				best_match_index = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best_match_index)
			b->target_node = find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

/*
 * Set the prices to push the node
 * from b -> a
 * The price checks for the relative positions in the stack
 * for every node, setting the respective price
*/
void	set_price(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push_cost = b->current_position;
		if (!(b->above_median))
			b->push_cost = len_b - (b->current_position);
		if (b->target_node->above_median)
			b->push_cost += b->target_node->current_position;
		else
			b->push_cost += len_a - (b->target_node->current_position);
		b = b->next;
	}
}

/*
 * Flag the cheapest node in the current
 * stacks configurations
*/
void	set_cheapest(t_stack_node *b)
{
	long			best_match_value;
	t_stack_node	*best_match_node;

	if (NULL == b)
		return ;
	best_match_value = LONG_MAX;
	while (b)
	{
		if (b->push_cost < best_match_value)
		{
			best_match_value = b->push_cost;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheapest = true;
}

/*
 * All the necessary values to make the push
 * 		~Relative Positions
 * 		~Target node, the b node to make emerge
 * 		~Price for every configuration
 * 		~Cheapest in the current configuration
*/
void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}