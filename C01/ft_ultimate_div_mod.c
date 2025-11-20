void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	if (*a == NULL || *b == NULL)
		return ;
	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}
