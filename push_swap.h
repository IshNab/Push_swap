#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

typedef	struct s_stack_node
{
	int		value;
	int		current_position;
	int		final_index;
	int		push_cost;
	bool	above_middle;
	bool	cheapest;
	struct	s_stack_node *target_node;
	struct	s_stack_node *next;
	struct	s_stack_node *prev;
}	t_stack_node;

// Stack initialization and validation
int     stack_init(t_stack_node **a, char **argv, bool is_split);
bool    check_duplicates(t_stack_node *stack);
bool    check_input(char *str);
void    free_stack(t_stack_node **stack);
void    free_split(char **split);

// Stack utilities
t_stack_node    *get_stack_bottom(t_stack_node *stack);
t_stack_node    *get_stack_before_bottom(t_stack_node *stack);
void    append_node(t_stack_node **stack, int n);

// Algorithm
void    sort_five(t_stack_node **a, t_stack_node **b);

// Error handling
void    error_exit(t_stack_node **a, t_stack_node **b, char **split, bool is_split);

#endif