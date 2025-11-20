char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (str == NULL || to_find == NULL)
		return (NULL);
	if (to_find[0] == '\0')
		return (str);
	i = 0;
	while (str[i])
	{
		if ((unsigned char)str[i] == (unsigned char)to_find[0])
		{
			j = 0;
			while (to_find[j] && (unsigned char)str[i + j] == to_find[j])
				j++;
			if (to_find[j] == '\0')
				return (&str[i]);
		}
		i++;
	}
	return (NULL);
}
