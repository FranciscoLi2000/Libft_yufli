#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

char	**ft_split(char const *s, char c);

int	count_substr(char const *s, char c)
{
    int i;
    int count;

    count = 0;
    if (!s)
        return (NULL);
    i = 0;
    while (s[i] != '\0')
    {
        while (s[i] == c)
            i++;
        if (s[i] != '\0')
        {
            count++;
            while (s[i] != '\0' && s[i] != c)
                i++;
        }
    }
    return (count);
}

char	**ft_split(char const *s, char c)
{
    char    *result;
    int         i;
    int         j;

    j = 0;
    result = malloc((count_substr(s, c) + 1) * sizeof(char *));
    if (!result || !s)
        return (NULL);
    i = 0;
    while (s[i] != '\0')
    {
        while (s[i] == c)
            i++;
        if (s[i] != '\0')
        {
            start = i;
            while (s[i] != '\0' && s[i] != c)
                i++;
            result[j] = malloc((i - start + 1) * sizeof(char));
            if (!result[j])
            {
                while (j > 0)
                    free(result[j]);
                free(result);
                return (NULL);
            }
            ft_strlcpy(result[j], &s[start], i - start);
            result[j][i - start] = '\0';
            j++;
        }
        result[j] = NULL;
        return (result);
    }
}