int	ft_iterative_factorial(int nb)
{
	int	res;

	res = 1;
	while (nb > 1)
	{
		res = res * nb;
		nb--;
	}
	return (res);
}
