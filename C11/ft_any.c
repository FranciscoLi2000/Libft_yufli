int	ft_any(char **tab, int(*f)(char *))
{
	int	cur;

	cur = 0;
	while (tab[cur] != 0)
	{
		if ((*f)(tab[cur]) != 0)
			return (1);
		cur++;
	}
	return (0);
}
