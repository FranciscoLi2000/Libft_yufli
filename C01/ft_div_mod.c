void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (*div == NULL || *mod == NULL)
		return ;
	div = *a / *b;
	mod = *a % *b;
}
