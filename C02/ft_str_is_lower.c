int	ft_str_is_lower(const char *str)
{
	size_t		i;
	unsigned char	c;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		c = (unsigned char)str[i];
		if (!(c >= 'a' && c <= 'z'))
			return (0);
		i++;
	}
	return (1);
}
