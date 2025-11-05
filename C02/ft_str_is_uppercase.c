#include <stdio.h>
#include <ctype.h>

int	ft_isupper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isupper(str[i]))
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
		if (ft_str_is_uppercase(str))
			printf("The string only has alpha characters.\n");
		else
			printf("The string has other character.\n");
	}
	return (0);
}
