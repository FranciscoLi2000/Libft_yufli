char	*ft_strupcase(char *str)
{
	size_t		i;
	unsigned char	c;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		c = (unsigned char)str[i];
		if (c >= 'a' && c <= 'z')
			str[i] = (char)(c - ('a' - 'A'));
		++i;
	}
	return (str);
}
