void	print_bits(unsigned char octet)
{
	char		c;
	unsigned char	bit;
	int			i;

	i = 7;
	while (i >= 0)
	{
		bit = (octet >> i) & 1;
		c = (char)(bit + '0');
		write(1, &c, 1);
		i--;
	}
}
