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