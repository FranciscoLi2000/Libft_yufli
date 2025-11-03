#include <unistd.h>

void	ft_putchar(char c);

void	ft_is_negative(int n)
{
	if (n >= 0)
		ft_putchar('P');
	else
		ft_putchar('N');
}

#include <stdio.h>

int	main(void)
{
	int	nb;

	printf("Enter a number\n");
	scanf("%i", &nb);
	ft_is_negative(nb);
	ft_putchar('\n');
	return (0);
}
