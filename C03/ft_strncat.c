char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	size_t	dst_len;
	size_t	src_len;

	if (dest == NULL || src == NULL)
		return (NULL);
	dst_len = 0;
	src_len = 0;
	while (dest[dst_len] != '\0')
		dst_len++;
	while (src_len < nb && src[src_len] != '\0')
		dest[dst_len++] = src[src_len++];
	dest[dst_len] = '\0';
	return (dest);
}
