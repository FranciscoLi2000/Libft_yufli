#include <stdio.h>

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

int	main(void)
{
	int	n;

	printf("enter a number:\n");
	scanf("%i", &n);
	ft_ft(&n);
	printf("new value: %i\n", n);
	return (0);
}
