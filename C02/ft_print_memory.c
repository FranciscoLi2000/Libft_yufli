/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:25:24 by yufli             #+#    #+#             */
/*   Updated: 2025/11/17 17:20:07 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
 * • 字节 (unsigned char) 的概念
 * • 十六进制高/低 nibble 的处理
 * • 打印不可打印字符的判定
 * • 字符串只是 char 数组
 * • 使用 write(1, &c, 1) 操作底层输出
 *
 * 那么你已经具备写 mini-hexdump 的所有基础技能
 */
/*
 * 每一行包含：
 * 1.	内存地址（16进制，宽度 16）
 * 2.	冒号 + 空格
 * 3.	16 个字节，每字节两位 hex，中间空格分隔（8 字节分组）
 * 4.	空格
 * 5.	ASCII 区（不可打印显示为 .）
 */
/*
 * 1) 16 是 2⁴，一个“自然字节块”
 *
 * CPU、内存调试工具、网络协议里都习惯以 16 字节（aka 1 行） 展示，因为：
 * •	容易以十六进制表示（1 行 = 0x10 字节）
 * •	每行刚好能对应到一个对齐的指针地址范围
 * •	是 hexdump/binutils 的默认格式
 *
 * 2) 当然也“因为它整齐”
 *
 * 对人类阅读更友好。
 *
 * 所以你答的是“看起来整齐”，完全没错，但它其实背后有更深的原因：
 * 和底层的字节对齐有关。
 */
/*
 * 1.	每次打印 16 字节：i += 16
 * 2.	每行格式 = 地址 + hex 区 + ASCII 区
 * 3.	ASCII 部分不可打印字符要显示成 .
 */
/*
 * 内存不是变量，是从某个起点开始的一段连续字节。
 * 要访问其中任何一行，只需 addr + 偏移。*/
/*
 * 为什么不是 void* 直接打印？
 * 因为：
 * •	你不能 print 指针本身（不能用 printf）
 * •	指针作为整数使用时必须用能容纳它的整数类型
 * •	在 64-bit 系统中指针是 8 bytes = 64 bits
 * •	打成 16 个 hex digit 刚刚好
 */

#include <unistd.h>

/*
 * print_address: 打印 addr（任意指针）为 16 个 hex 字符（不带 0x），
 * 例如: 0000000000000abc
 * 
 * 约定：addr 是 void* 指针，使用 unsigned long 来保存指针整数值。
 */
void	print_address(void *addr)
{
	unsigned long	val;
	int				k;
	char			hex[] = "0123456789abcdef";
	char			c;

	/* 把指针转成无符号整数以安全处理位移（在 64-bit 上能容纳指针） */
	val = (unsigned long)addr;
	/* 从最高 nibble（第 15 个）到最低 nibble（第 0 个）依次打印 */
	k = 15;
	while (k >= 0)
	{
		/* 取出第 k 个 nibble：右移 (k*4) 位，再和 0xF 掩码 */
		c = hex[(val >> (k * 4)) & 0xF];
		write(1, &c, 1);
		k--;
	}
}

/* print_hex: print up to 16 bytes starting at p.
 * - p: pointer to the start of this line
 * - len: number of remaining bytes from overall buffer (may be >16), so use min(len,16)
 *
 * Behavior:
 * For each byte that exists: print two hex chars then a space.
 * For non-existing bytes (tail padding): print three spaces to keep columns aligned.
 * After 8 bytes, print an extra space.
 */
void	print_hex(void *addr, unsigned int len)
{
	unsigned char	*p;
	unsigned int		i;
	unsigned int		n;
	char		hex[] = "0123456789abcdef";
	char		buf[3];

	p = (unsigned char *)addr;
	if (len > 16)
	    n = 16;
	else
	    n = len;
	i = 0;
	while (i < 16)
	{
		if (i < n)
		{
			/* high nibble */
			buf[0] = hex[(p[i] >> 4) & 0xF];
			/* low nibble */
			buf[1] = hex[p[i] & 0xF];
			buf[2] = '\0';
			write(1, buf, 2);
			/* write separating space after every byte */
			write(1, " ", 1);
		}
		else
			/* padding for missing byte: two hex positions + one space */
			write(1, "   ", 3);
		/* extra space after 8 bytes for readability */
		if (i == 7)
			write(1, " ", 1);
		i++;
	}
}

/* print_ascii: print ASCII area for up to 16 bytes.
 * - For printable characters (32..126) print them.
 * - For non-printable print a dot '.'.
 * - Only print for existing bytes (i < n), not for padded spots.
 */
void	print_ascii(void *addr, unsigned int len)
{
	unsigned char	*p;
	unsigned int		i;
	unsigned int		n;
	char		c;

	p = (unsigned char *)addr;
	if (len > 16)
		n = 16;
	else
		n = len;
	i = 0;
	while (i < n)
	{
		c = p[i];
		if (c >= 32 && c <= 126)
			write(1, &c, 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		print_address(addr + i);
		write(1, ": ", 2);
		print_hex(addr + i, size - i);
		print_ascii(addr + i, size - i);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}

/* Test the print_address function
int	main(void)
{
	char	buf[1];

	 实际缓冲区地址（你的第一个测试） 
	print_address(buf);
	write(1, "\n", 1);
	直接以 64-bit 字面量作为地址（注意后缀 ULL） 
	print_address((void *) (unsigned long) 0x000000001234abcdULL);
	write(1, "\n", 1);
	 以 32-bit 字面量作为地址（看看编译器如何扩展）
	print_address((void *) (unsigned long) 0x1234abcd);
	write(1, "\n", 1);
	return (0);
}*/

int	main(void)
{
	char	data[] = "Hello, this is a test of ft_print_memory!\nAnd a second line.";

	ft_print_memory(data, sizeof(data) - 1);
	return (0);
}
