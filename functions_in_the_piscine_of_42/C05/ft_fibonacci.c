
int	ft_fibonacci(int index)
{
	if (index <= 0)
		return (0);
	if (index < 2)
		return (1);
	return (index + ft_fibonacci(index - 1));
}
