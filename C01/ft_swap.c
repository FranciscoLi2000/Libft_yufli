#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	main(void)
{
	int	x;
	int	y;

	printf("enter two values:\n");
	scanf("%i %i", &x, &y);
	printf("x = %i, y = %i\n", x, y);
	ft_swap(&x, &y);
	printf("x = %i, y = %i\n", x, y);
	return (0);
}
