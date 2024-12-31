#include <unistd.h>
#include <stdlib.h>

char	*ft_itoa(int n);

unsigned int    num_len(int n)
{
    int len;

    if (n <= 0)
    {
        len = 1;
        while (n)
        {
            n = n / 10;
            len++;
        }
    }
    else
    {
        len = 0;
        while (n)
        {
            n = n / 10;
            len++;
        }
    }
    return (len);
}

char    *ft_itoa(int n)
{
        char    *str;
        int             len;
        int             num;

        num = n;
        str = malloc(num_len(n) * sizeof(char));
        if (str == NULL)
                return (NULL);
        str[len] = '\0';
        if (num < 0)
        {
                str[0] = '-';
                num = -num;
        }
        else
        {
                while (len > 0 && num >= 0)
                {
                        str[len] = num % 10 + '0';
                        num = num / 10;
                        len--;
                }
        }
        return (str);
}