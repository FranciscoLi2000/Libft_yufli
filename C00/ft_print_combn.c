#include <unistd.h>

void	ft_putchar(char c);

static void	print_combination(int *arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(arr[i] + '0');
		i++;
	}
}

static int     is_last_combination(int *arr, int n)
{
	int	i;
	int	expected;

	i = 0;
	expected = 10 - n;
	while (i < n)
	{
		if (arr[i] != expected + i)
			return (0);
		i++;
	}
	return (1);
}

static void	increment_combination(int *arr, int n, int pos)
{
	int	i;

	if (pos < 0)
		return ;
	if (arr[pos] < 9 - (n - 1 - pos))
	{
		arr[pos]++;
		i = pos + 1;
		while (i < n)
		{
			arr[i] = arr[i - 1] + 1;
			i++;
		}
	}
	else
		increment_combination(arr, n, pos - 1);
}

void	ft_print_combn(int n)
{
	int	arr[10];
	int	i;

	i = 0;
	while (i < n)
	{
		arr[i] = i;
		i++;
	}
	while (1)
	{
		print_combination(arr, n);
		if (is_last_combination(arr, n))
			break ;
		write(1, ", ", 2);
		increment_combination(arr, n, n - 1);
	}
}

#include <stdio.h>

int	main(void)
{
	int	nb;

	printf("Enter a number\n");
	scanf("%i", &nb);
	if (nb > 9 || nb < 0)
		return (0);
	ft_print_combn(nb);
	ft_putchar('\n');
	return (0);
}
