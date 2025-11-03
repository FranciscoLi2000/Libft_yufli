#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	tmp;

	tmp = *a / *b;
	*b = *a % *b;
	*a = tmp;
}

int	main(void)
{
	int	x;
	int	y;

	printf("Enter two values:\n");
	scanf("%i %i", &x, &y);
	ft_ultimate_div_mod(&x, &y);
	printf("x = %i, y = %i\n", x, y);
	return (0);
}
