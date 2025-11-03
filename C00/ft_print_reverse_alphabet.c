#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_reverse_alphabet(void)
{
	char	ch;

	ch = 'z';
	while (ch >= 'a')
	{
		ft_putchar(ch);
		ch--;
	}
}

int	main(void)
{
	ft_print_reverse_alphabet();
	ft_putchar('\n');
	return (0);
}
