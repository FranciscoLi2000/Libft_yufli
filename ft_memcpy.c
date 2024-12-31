#include <unistd.h>

void	*ft_memcpy(void *dest, const void *src, unsigned int n);

void	*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	unsigned int	i;

	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((const char *)src)[i];
		i++;
	}
	return (dest);
}
