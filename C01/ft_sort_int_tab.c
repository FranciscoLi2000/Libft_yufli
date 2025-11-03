#include <stdio.h>
#include <unistd.h>

void	ft_putnbr(int nb);

void	ft_sort_int_tab(int *tab, int size)
{
	int	tmp;
	int	i;
	int	j;
	int	swapped;

	i = 0;
	while (i < size - 1)
	{
		swapped = 0;
		j = 0;
		while (j < size - 1 - i)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
				swapped = 1;
			}
			j++;
		}
		if (!swapped)
			break ;
		i++;
	}
}

int	main(void)
{
	int	arr[10] = {3, 9, 2, 6, 10, 5, 4, 1, 8, 7};
	int	i;

	ft_sort_int_tab(arr, 10);
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
