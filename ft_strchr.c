#include <unistd.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
	{
		if (s[len] == (char)c)
			return ((char *)&s[len]);
		len++;
	}
	return ((char *)&s[i]);
}
