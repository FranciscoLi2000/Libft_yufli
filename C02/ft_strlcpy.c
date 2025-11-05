#include <stdio.h>

/*
 * get the length of src
 * check if dstsize is big enough to accomodate src length
 * plus the NUL character
 * copy the whole src into dst
 * else
 * copy dstsize - 1 characters into dst
 * return length of src
 */

unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	src_len;
	unsigned int	i;

	src_len = ft_strlen(src);
	if (size < src_len + 1)
		return (src_len);
	i = 0;
	while (src[i] && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

# define MAX_LEN 100

int	main(void)
{
	char	line[MAX_LEN];
	char	*result;
	char	str[20];

	if ((result = fgets(line, MAX_LEN, stdin)) != NULL)
	{
		ft_strlcpy(str, result, 20);
		printf("%s", str);
	}
	return (0);
}
