#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (!stack_init(&a, argv + 1, argc == 2))
		return (1);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, true);
		else if (stack_len(a) == 3)
			small_sort(&a);
		else if (stack_len(a) <= 5)
			sort_five(&a, &b);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	if (argc == 2)
		free_split(argv);
	return (0);
}
