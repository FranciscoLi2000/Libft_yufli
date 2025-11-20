int	ft_isalnum(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int	ft_islower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	ft_isupper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	word;

	word = 1;
	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (word && ft_isalnum(str[i]))
		{
			if (ft_islower(str[i]))
				str[i] -= ('a' - 'A');
			word = 0;
		}
		else if (!word)
		{
			if (ft_isupper(str[i]))
				str[i] += ('a' - 'A');
			if (!ft_isalnum(str[i]))
				word = 1;
		}
		i++;
	}
	return (str);
}
