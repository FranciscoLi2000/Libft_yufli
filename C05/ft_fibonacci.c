int	ft_fibonacci_iter(int n)
{
	int	a;
	int	b;
	int	c;

	if (n < 0)
		return (-1);
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	a = 0;
	b = 1;
	while (n >= 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return (b);
}

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	return (ft_fibonacci(index - 2) + ft_fibonacci(index - 1));
}
