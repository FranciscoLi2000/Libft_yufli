#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	len;
	int	i;

	if (min >= max)
		return (NULL);
	len = max - min;
	tab = malloc(len * sizeof(int));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < len)
	{
		tab[i] = min++;
		i++;
	}
	return (tab);
}
