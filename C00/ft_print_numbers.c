#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_numbers(void)
{
	char	ch;

	ch = '0';
	while (ch <= '9')
	{
		ft_putchar(ch);
		ch++;
	}
}

int	main(void)
{
	ft_print_numbers();
	ft_putchar('\n');
	return (0);
}
