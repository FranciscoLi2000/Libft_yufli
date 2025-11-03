#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

int	main(void)
{
	int	x;
	int	y;
	int	d;
	int	m;

	printf("Enter two values:\n");
	scanf("%i %i", &x, &y);
	ft_div_mod(x, y, &d, &m);
	printf("Div = %i, Mod = %i\n", d, m);
	return (0);
}
