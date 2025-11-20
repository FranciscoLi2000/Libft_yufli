int	ft_strncmp(const char *dest, const char *src, int nb)
{
	int	i;

	i = 0;
	while (i < nb && (dest[i] != '\0' || src[i] != '\0'))
	{
		if (dest[i] != src[i])
			return (dest[i] - src[i]);
		i++;
	}
	return (dest[i] - src[i]);
}
