#include <unistd.h>
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char    *str;
    int i;
    int len;

    if (!s || !f)
        return (NULL);
    len = 0;
    while (s[len] != '\0')
        len++;
    str = malloc((len + 1) * sizeof(char));
    if (!str)
        return (NULL);
    i = 0;
    while (i < len)
    {
        str = f(i, s[i]);
        i++;
    }
    str[i] = '\0';
    return (str);
}