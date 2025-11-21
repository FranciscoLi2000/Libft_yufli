#include <unistd.h>

int	ft_strcmp(const char *dest, const char *src)
{
	int	i;

	i = 0;
	while (dest[i] != '\0' || src[i] != '\0')
	{
		if (dest[i] != src[i])
			return (dest[i] - src[i]);
		i++;
	}
	return (dest[i] - src[i]);
}

void	ft_swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
				ft_swap(&argv[i], &argv[j]);
			j++;
		}
		i++;
	}
	return (0);
}
