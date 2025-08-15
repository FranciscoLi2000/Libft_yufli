#include "libft.h"

static int	num_len(long nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*res;
	int		len;
	int		i;

	nb = n;
	len = num_len(nb);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	i = len - 1;
	while (nb != 0)
	{
		res[i] = ((nb % 10) + '0');
		nb = nb / 10;
		i--;
	}
	res[len] = 0;
	return (res);
}
