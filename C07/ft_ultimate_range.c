#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	len;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	len = max - min;
	*range = malloc(len * sizeof(int));
	if (!*range)
	{
		*range = NULL;
		return (-1);
	}
	i = 0;
	while (i < len)
	{
		(*range)[i] = min++;
		i++;
	}
	return (len);
}
