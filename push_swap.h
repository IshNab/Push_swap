#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h> //To use bool flags, e.g, to print or not to print
# include <limits.h> //To define MIN and MAX macros
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"

typedef struct s_stack_node //A container of data enclosed in {} braces. `s_` for struct
{
	int					nbr; //The number to sort
	int					index; //The number's position in the stack
	int					push_cost; //How many commands in total
	bool				above_median; //Used to calculate `push_cost`
	bool				cheapest; //The node that is the cheapest to do commands
	struct s_stack_node	*target_node; //The target node of a node in the opposite stack
	struct s_stack_node	*next; //A pointer to the next node
	struct s_stack_node	*prev; //A pointer to the previous node
}	t_stack_node; //The "shortened name", "t_stack_node". `t_` for type

//***Input check
long	ft_atol(const char *str);
bool	check_input(char *str);
bool    check_duplicates(t_stack *stack);
void	error_exit(t_stack **a, t_stack **b,
	char **split, bool is_split);

//***Stack initiation
void	init_stack_a(t_stack_node **a, char **argv); //Initiate stack `a` before processing
void	init_stack_b(t_stack *a, t_stack *b);
int		stack_init_a(t_stack **a, char **argv, bool is_split);
char	**split(char *s, char c); //To handle input of numbers as a string argument, e.g. enclosed in " "

//***Nodes initiation
void			init_nodes_a(t_stack_node *a, t_stack_node *b); //To prep all nodes for pushing `a` to `b`
void			init_nodes_b(t_stack *a, t_stack *b); //To prep all nodes for pushing `b` back to `a`
void			set_current_position(t_stack *stack); //Set the node's current index
void			set_price(t_stack *a, t_stack *b);
void			set_cheapest(t_stack_node *stack); //Set the stack's cheapest node
t_stack			*return_cheapest(t_stack *stack);//Get the cheapest node of a stack
void			prep_for_push(t_stack_node **s, t_stack_node *n, char c); //Prep the required nodes on top for pushing

//***Stack utils
int				stack_len(t_stack_node *stack); //Calculate the length of a stack
t_stack_node	*find_last(t_stack_node *stack); //Find the last node of a stack
bool			stack_sorted(t_stack_node *stack); //To check whether a stack is sorted
t_stack_node	*find_min(t_stack_node *stack); //Find the smallest number
t_stack_node	*find_max(t_stack_node *stack); //Find the biggest number

//***Commands
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **b, t_stack_node **a, bool print);

//***Algorithm
void			small_sort(t_stack_node **a);
void			sort_stacks(t_stack_node **a, t_stack_node **b); //Turk algorithm

#endif