
void	ft_rev_int_tab(int *tab, int size)
{
	int	index;
	int	howlong;
	int	startval;
	int	endval;

	index = 0;
	howlong = size / 2;
	while (howlong > 0)
	{
		size--;
		startval = tab[size];
		endval = tab[index];
		tab[size] = endval;
		tab[index] = startval;
		index++;
		howlong--;
	}
}
