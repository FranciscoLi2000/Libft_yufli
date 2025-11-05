#include <stdio.h>

char	ft_tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}

# define MAX_LEN 100

int	main(void)
{
	char	line[MAX_LEN];
	char	*result;

	if ((result = fgets(line, MAX_LEN, stdin)) != NULL)
		printf("%s", ft_strlowcase(result));
	return (0);
}
