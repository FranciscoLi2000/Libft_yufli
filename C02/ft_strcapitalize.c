#include <stdio.h>

/*
 * For example:
 * salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un
 * Becomes:
 * Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un
 *
 * if the character is a alpha and is first letter of the word, toupper and the index is in the word
 * if the character is not a alpha , the indes is not in a word
 */

int	ft_isalpha(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int	ft_isalnum(char c)
{
	if (ft_isalpha(c) || (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

char	ft_toupper(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

char	ft_tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	in_word;

	i = 0;
	in_word = 0;
	while (str[i])
	{
		if (ft_isalnum(str[i]))
		{
			if (ft_isalpha(str[i]) && (in_word == 0))
				str[i] = ft_toupper(str[i]);
			else
				str[i] = ft_tolower(str[i]);
			in_word = 1;
		}
		else
			in_word = 0;
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
		printf("%s", ft_strcapitalize(result));
	return (0);
}
