void	ft_rev_int_tab(int *tab, int size)
{
	int	tmp;
	int	i;

	if (!tab || size <= 1)
		return ;
	i = 0;
	while (i < size / 2)
	{
		tmp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = tmp;
		i++;
	}
}
