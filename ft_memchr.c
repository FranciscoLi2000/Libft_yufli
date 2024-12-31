#include <unistd.h>

void	*ft_memchr(const void *s, int c, unsigned int n);

void	*ft_memchr(const void *s, int c, unsigned int n)
{
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)&((unsigned char *)s)[i]);
		i++;
	}
	return (NULL);
}