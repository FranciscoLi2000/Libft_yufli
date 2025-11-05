#include <stdio.h>
#include <string.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	main(void)
{
	char	*s1 = "Hello world";
	char	s2[50];

	ft_strcpy(s2, s1);
	printf("%s\n", s2);
	return (0);
}
