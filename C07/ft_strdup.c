#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*res;
	int		i;
	int		len;

	if (!src)
		return (NULL);
	len = ft_strlen(src);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (src[i])
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
