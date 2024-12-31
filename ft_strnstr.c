#include <unistd.h>

char	*ft_strnstr(const char *big, const char *little, unsigned int len);

char	*ft_strnstr(const char *big, const char *little, unsigned int len)
{
	unsigned int	i;
	unsigned int	j;

	if (*little == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	if (!big || !little)
		return (NULL);
	i = 0;
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while ((i + j) < len && big[i + j] == little[j])
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
