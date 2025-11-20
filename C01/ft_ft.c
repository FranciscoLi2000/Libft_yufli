void	ft_ft(int *nbr)
{
	*nbr = 42;
}

#include <stdio.h>

int	main(void)
{
	int	x;

	x = 5;
	printf("%i\n", x);
	ft_ft(&x);
	printf("%i\n", x);
	return (0);
}
