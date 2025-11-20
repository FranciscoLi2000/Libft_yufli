unsigned char	swap_bits(unsigned char octet)
{
	unsigned char	high;
	unsigned char	low;

	high = (octet & 0xF0) >> 4;
	low = (octet & 0x0F) << 4;
	return (high | low);
}
