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