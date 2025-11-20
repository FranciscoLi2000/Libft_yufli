#include <unistd.h>
#include <stddef.h>

void	print_address(void *addr)
{
	intptr_t	val;
	char				hex[] = "0123456789abcdef";
	char				out[16];
	int					k;

	val = (intptr_t)addr;
	/* 填充 out[0..15]，高位在 out[0] */
	k = 0;
	while (k < 16)
	{
		/* 这里写位运算逻辑 */
		out[k] = hex[(val >> ((15 - k) * 4)) & 0xF];
		++k;
	}
	write(1, out, 16);
	write(1, " : ", 3);
}

void	print_hex_byte(unsigned char c)
{
	char	*hex = "0123456789abcdef";
	char	out[2];

	out[0] = hex[c >> 4];
	out[1] = hex[c & 0x0F];
	write(1, out, 2);
}

void	print_hex_block(unsigned char *p, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		print_hex_byte(p[i]);
		write(1, " ", 1);
		i++;
	}
	while (i < 16)
	{
		write(1, "   ", 3);
		i++;
	}
}

void	print_ascii_block(unsigned char *p, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (p[i] >= 32 && p[i] <= 126)
			write(1, &p[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, size_t size)
{
	unsigned char	*p;
	size_t		i;
	size_t		line_size;

	p = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		if (size - i >= 16)
			line_size = 16;
		else
			line_size = size - i;
		print_address(p + i);
		print_hex_block(p + i, line_size);
		print_ascii_block(p + i, line_size);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}

#include <string.h>

int	main(void)
{
	char s[] = "Hello Barcelona!\nThis is 42 test.";

	ft_print_memory(s, strlen(s));
	return (0);
}
