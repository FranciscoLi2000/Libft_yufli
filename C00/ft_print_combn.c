#include <unistd.h>

void	ft_putchar(char c);

void	print_digits_and_separator(int digits[], int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(digits[i] + '0');
		++i;
	}
	if (digits[0] != 10 - n)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	generate_recursive(int index, int n, int digits[])
{
	int	start;
	int	end;
	int	d;

	if (index == n)
	{
		print_digits_and_separator(digits, n);
		return ;
	}
	if (index == 0)
		start = 0;
	else
		start = digits[index - 1] + 1;
	end = 9 - (n - index - 1);
	d = start;
	while (d <= end)
	{
		digits[index] = d;
		generate_recursive(index + 1, n, digits);
		++d;
	}
}

void	ft_print_combn(int n)
{
	int	digits[10];

	if (n <= 0 || n >= 10)
		return ;
	generate_recursive(0, n, digits);
}
