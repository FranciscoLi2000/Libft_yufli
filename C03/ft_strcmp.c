int	ft_strcmp(const char *dest, const char *src)
{
	int	i;

	i = 0;
	while (dest[i] != '\0' || src[i] != '\0')
	{
		if (dest[i] != src[i])
			return (dest[i] - src[i]);
		i++;
	}
	return (dest[i] - src[i]);
}
