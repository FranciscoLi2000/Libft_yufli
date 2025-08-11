#include "libft.h"

void	ft_putnbr_fd(int nbr, int fd)
{
	if (nbr == -2147483648)
	{
		ft_putstr_fd("-2147483648\n", fd);
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar('-', fd);
		nb = -nb;
	}
	else if (nbr > 9)
		ft_putnbr_fd(nbr / 10, fd);
	else
		ft_putchar_fd(nbr % 10 + '0', fd);
}
