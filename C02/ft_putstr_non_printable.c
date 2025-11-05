#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_isprint(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

void	ft_print_hex(unsigned char v)
{
	char	*hex;
	char	out[2];

	hex = "0123456789abcdef";
	out[0] = hex[v / 16];
	out[1] = hex[v % 16];
	ft_putstr(out);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	uc;
	int			i;

	i = 0;
	while (str[i])
	{
		uc = (unsigned char)str[i];
		if (ft_isprint(str[i]))
			ft_putchar(str[i]);
		else
		{
			ft_putchar('\\');
			ft_print_hex(uc);
		}
		i++;
	}
}

# define MAX_LEN 100

int	main(void)
{
	char	line[MAX_LEN];
	char	*s;

	printf("Enter a string:\n");
	if ((s = fgets(line, MAX_LEN, stdin)) != NULL)
		ft_putstr_non_printable(s);
	return (0);
}
