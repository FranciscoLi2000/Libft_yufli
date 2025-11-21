#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check_base(char *str)
{
	int	i;
	int	j;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-'
			|| str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

/* helper: 使用 long 做递归与输出，安全处理绝对值 */
void	ft_putnbr_base_long(long n, char *base_str, int base_len)
{
	if (n >= base_len)
		putnbr_base_long(n / base_len, base_str, base_len);
	ft_putchar(base_str[n % base_len]);
}

/* 公共接口：保持 int 签名，做 base 校验与符号处理，然后调用 helper */
void	ft_putnbr_base(int nb, char *base_str)
{
	long	n;
	int		base_len;

	base_len = check_base(base_str);
	if (base_len == 0)
		return ;
	n = nb;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n; /* safe because n is long */
	}
	ft_putnbr_base_long(n, base_str, base_len);
}
