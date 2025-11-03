#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_comb2(void)
{
	int	arr[2];
	int	i;

	arr[0] = 0;
	while (arr[0] <= 98)
	{
		arr[1] = arr[0] + 1;
		while (arr[1] <= 99)
		{
			ft_putchar(arr[0] / 10 + '0');
			ft_putchar(arr[0] % 10 + '0');
			ft_putchar(' ');
			ft_putchar(arr[1] / 10 + '0');
			ft_putchar(arr[1] % 10 + '0');
			if (!(arr[0] == 98 && arr[1] == 99))
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			arr[1]++;
		}
		arr[0]++;
	}
}

int	main(void)
{
	ft_print_comb2();
	ft_putchar('\n');
	return (0);
}
