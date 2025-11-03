#include <stdio.h>
#include <unistd.h>

void	ft_putnbr(int nb);

void	ft_rev_int_tab(int *tab, int size)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	j = size - 1;
	while (i < j)
	{
		tmp = tab[i];
		tab[i] = tab[j];
		tab[j] = tmp;
		i++;
		j--;
	}
}

int	main(void)
{
	int	arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int	i;

	ft_rev_int_tab(arr, 10);
	i = 0;
	while (i < 10)
	{
		ft_putnbr(arr[i]);
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
