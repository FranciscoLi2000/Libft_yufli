/*
int	check_base(char *str)
{
	int	i;
	int	j;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
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
*/

/* 返回字符 c 在 base 中的下标，找不到返回 -1 */
int	find_index(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *str, char *base_str)
{
	int	res;
	int	i;
	int	sign;
	int	base_len;
	int	idx;

	base_len = check_base(base_str);
	if (base_len == 0)
		return (0);
	sign = 1;
	i = 0;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		idx = find_index(base, str[i]);
		if (idx == -1)
			break ;
		res = res * base_len + idx;
		i++;
	}
	return (res * sign);
}
