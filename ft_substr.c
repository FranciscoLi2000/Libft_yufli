#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	unsigned int	i;
	char			*substr;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
	{
		substr = malloc((ft_strlen(s) + 1) * sizeof(char));
		if (substr == NULL)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (len > (unsigned int)ft_strlen(s) - start)
		len = (unsigned int)ft_strlen(s) - start;
	substr = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

int	main(void)
{
	int	start = 5;
	int	len = 3;
	char			*s;
	char				*substr;

	s = 'abcdefghijklmn';
	ft_substr(s, start, len);
	printf("substr: %s\n", substr);
	return (0);
}