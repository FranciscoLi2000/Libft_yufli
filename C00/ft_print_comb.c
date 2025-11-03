#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_comb(void)
{
	int	arr[3];

	arr[0] = 0;
	while (arr[0] <= 7)
	{
		arr[1] = arr[0] + 1;
		while (arr[1] <= 8)
		{
			arr[2] = arr[1] + 1;
			while (arr[2] <= 9)
			{
				ft_putchar(arr[0] + '0');
				ft_putchar(arr[1] + '0');
				ft_putchar(arr[2] + '0');
				if (arr[0] != 7 || arr[1] != 8 || arr[2] != 9)
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
				arr[2]++;
			}
			arr[1]++;
		}
		arr[0]++;
	}
}

int	main(void)
{
	ft_print_comb();
	ft_putchar('\n');
	return (0);
}
