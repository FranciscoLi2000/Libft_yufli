#include <stdlib.h>

int	*ft_map(int *tab, int lenght, int (*f)(int))
{
	int		i;
	int		*res;

	res = malloc(sizeof(int) * lenght);
	i = -1;
	while (++i < lenght)
		res[i] = (*f)(tab[i]);
	return (res);
}
