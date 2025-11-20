unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	dst_len;
	unsigned int	src_len;
	unsigned int	i;
	unsigned int	max_copy;

	if (dest == NULL || src == NULL)
		return (UINT_MAX);
	dst_len = 0;
	src_len = 0;
	while (dest[dst_len])
		dst_len++;
	while (src[src_len])
		src_len++;
	if (size <= dst_len)
		return (dst_len + src_len);
	max_copy = size - dst_len - 1;
	i = 0;
	while (i < max_copy && src[i])
	{
		dest[dst_len + i] = src[i];
		i++;
	}
	dest[dst_len + i] = '\0';
	return (dst_len + src_len);
}
