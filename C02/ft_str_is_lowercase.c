#include <stdio.h>
#include <ctype.h>

int	ft_islower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_islower(str[i]))
			return (0);
		i++;
	}
	return (1);
}

#define MAX_LEN 100

int	main(void)
{
	FILE	*stream;
	char	line[MAX_LEN];
	char	*str;

	stream = stdin;
	if ((str = fgets(line, MAX_LEN, stream)) != NULL)
	{
		if (ft_str_is_lowercase(str))
			printf("The string only has alpha characters.\n");
		else
			printf("The string has other character.\n");
	}
	return (0);
}
