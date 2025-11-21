int	ft_iterative_power(int nb, int power)
{
	int	res;

	res = 1;
	while (power > 0)
	{
		res = res * nb;
		power--;
	}
	return (res);
}
