#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*last;
	int		i;

	last = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			last = (char *)(str + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(str + i));
	return (last);
}
