#include <stdio.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

#define  MAX_LEN  100
 
int	main(void)
{
	FILE	*stream;
	char	line[MAX_LEN];
	char	*result;
	char	str[20];

	stream = stdin;
	if ((result = fgets(line, MAX_LEN, stream)) != NULL)
	{
		printf("The string is %s\n", result);
		printf("copy is %s\n", ft_strncpy(str, result, 5));
	}
	return (0);
}
