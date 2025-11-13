#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*squared_tab;

	squared_tab = (int *)malloc(sizeof(int) * length);
	if (squared_tab == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		squared_tab[i] = (*f)(tab[i]);
		i++;
	}
	return (squared_tab);
}
