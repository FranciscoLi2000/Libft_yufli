#include <stdio.h>

char	ft_toupper(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
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
		printf("%s\n", ft_strupcase(result));
	return (0);
}
