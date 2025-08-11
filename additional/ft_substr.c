#include "libft.h"

char *ft_substr(const char *s, unsigned int start, size_t len)
{
    unsigned int    i;
    char        *res;

    if (len > ft_strlen(s + start))
        len = ft_strlen(s + start);
    res = malloc((len + 1) * sizeof(char));
    if (!res)
        return (NULL);
    i = start;
    while (i < len)
    {
        res[i] = s[i];
        i++;
    }
}