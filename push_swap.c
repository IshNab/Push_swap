/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inabakka <inabakka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:04:17 by inabakka          #+#    #+#             */
/*   Updated: 2025/05/23 13:53:05 by inabakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv) //Define a program that takes in a random input of numbers and sorts them in ascending order
{
	t_stack_node	*a; //To store a pointer to stack `a`
	t_stack_node	*b; //To store a pointer to stack `b`
	bool			is_split; //To track if the input was split from a single string

	a = NULL; //Set both pointers to NULL to avoid undefined behaviour
	b = NULL;
	is_split = false; //Assume input is not split by default

	if (argc == 1 || (argc == 2 && !argv[1][0])) //Check for incorrect argument counts or if the 2nd argument is `0`
		return (1);
	else if (argc == 2) //Check if the argument count is 2 and the 2nd is not empty, this implies a string
	{
		argv = ft_split(argv[1], ' '); //Call `split()` to extract each substring
		is_split = true; //Set flag since we manually split the string
	}

	stack_init_a(&a, argv + (is_split ? 0 : 1), is_split); //Initiate stack `a`, which also handles errors

	if (!stack_sorted(a)) //Check if the stack is not sorted
	{
		if (stack_len(a) == 2) //If not, and there are two numbers, swap the first two nodes
			sa(&a, false);
		else if (stack_len(a) == 3) //If not, and there are three numbers, call the sort three algorithm
			sort_three(&a);
		else
			sort_stacks(&a, &b); //If not, and there are more than three numbers, call the sort stacks algorithm
	}

	free_stack(&a); //Clean up the stack

	if (is_split) //Free the split array if `ft_split` was used
		free_split(argv); //Make sure you implement this helper if needed

	return (0);
}
