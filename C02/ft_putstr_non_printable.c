#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	print_hex_byte(unsigned char c)
{
	char	*hex = "0123456789abcdef";
	char	out[2];

	out[0] = hex[c >> 4];
	out[1] = hex[c & 0x0F];
	write(1, out, 2);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	c;
	int			i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		c = (unsigned char)str[i];
		if (c >= 32 && c <= 126)
			ft_putchar(c);
		else
		{
			ft_putchar('\\');
			print_hex_byte(c);
		}
		i++;
	}
}
