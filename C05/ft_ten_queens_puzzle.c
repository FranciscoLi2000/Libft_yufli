#include <unistd.h>

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	is_safe(int queens[], int column, int row)
{
	int	i;

	i = 0;
	while (i < column)
	{
		if (queens[i] == row || ft_abs(queens[i] - row) == column - i)
			return (0);
		i++;
	}
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	solve(int queens[], int column)
{
	int	row;
	int	count;
	int	i;

	if (column == 10)
	{
		i = 0;
		while (i < column)
		{
			ft_putchar(queens[i] + '0');
			i++;
		}
		ft_putchar('\n');
		return (1);
	}
	row = 0;
	count = 0;
	while (row < 10)
	{
		if (is_safe(queens, column, row))
		{
			queens[column] = row;
			count += solve(queens, column + 1);
		}
		row++;
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	int	queens[10];
	int	count;
	int	i;

	i = 0;
	while (i < 10)
	{
		queens[i] = 0;
		i++;
	}
	count = solve(queens, 0);
	return (count);
}

#include <stdio.h>

int	main(void)
{
	printf("Solutions = %i\n", ft_ten_queens_puzzle());
	return (0);
}
