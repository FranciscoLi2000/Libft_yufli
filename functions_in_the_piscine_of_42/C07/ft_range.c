#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	i;
	int	len;
	int	*range;

	i = 0;
	if (end < start)
		len = start - end + 1;
	else
		len = end - start + 1;
	range = (int *)malloc(len * sizeof(int));
	while (i < len)
	{
		if (start < end)
			range[i] = start++;
		else
			range[i] = start--;
		i++;
	}
	return (range);
}
