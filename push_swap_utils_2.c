#include <push_swap.h>

bool stack_sorted(t_stack *stack)
{
    t_stack *current;

    if (!stack || !stack->top)  // Empty stack is considered sorted
        return (true);
    current = stack->top;  // Start at the top node
    while (current->next)  // While not at the last node
    {
        if (current->value > current->next->value)
            return (false);  // Found unsorted pair
        current = current->next;  // Move to next node
    }
    return (true);  // All elements are in order
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*temp;
	size_t			i;

	temp = malloc(count * size);
	if (!temp)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		temp[i] = 0;
		i++;
	}
	return ((void *)temp);
}

char	*ft_strdup(const char *src)
{
	int		org_size;
	char	*dup;
	size_t	i;

	org_size = ft_strlen(src);
	dup = (char *)malloc(sizeof(char) * (org_size + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int ft_strlen(const char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}