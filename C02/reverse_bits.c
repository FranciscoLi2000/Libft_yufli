unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	result;
	int			i;

	i = 0;
	result = 0;
	while (i < 8)
	{
		result |= ((octet >> i) & 1) << (7 - i);
		++i;
	}
	return (result);
}
