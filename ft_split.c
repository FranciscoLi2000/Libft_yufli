#include <unistd.h>
#include <stdlib.h>

char	**ft_split(char const *s, char c);

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

int count_substrings(char const *s, char c)
{
    int i;
    int count;  // This will store our total word count
    int in_word;  // Flag to track if we're currently in a word

    i = 0;
    count = 0;
    in_word = 0;  // Start assuming we're not in a word
    if (s == NULL)
        return (0);
    while (s[i] != '\0')
    {
        if (s[i] != c)  // If we find a non-delimiter character
        {
            if (in_word == 0)   // If we weren't in a word before, this is the start of a new word
            {
                count++;  // Increment our word count
                in_word = 1;  // Mark that we're now in a word
            }   // If we were already in a word, we just continue
        }
        else  // If we find a delimiter
            in_word = 0;  // Mark that we're no longer in a word
        i++;
    }
    return (count);
}

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	unsigned int	i;
	char			*substr;

	substr = malloc((len + 1) * sizeof(char));
	if (s == NULL || substr == NULL)
		return (NULL);
	i = 0;
	if (start >= (unsigned int)ft_strlen(s))
	{
		substr[0] = '\0';
		return (substr);
	}
	if (len > (unsigned int)ft_strlen(s) - start)
		len = (unsigned int)ft_strlen(s) - start;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}