/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 18:28:00 by yufli             #+#    #+#             */
/*   Updated: 2025/11/17 21:25:24 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 把字符串 nbr（以 base_from 表示）转换成用 base_to 表示的字符串并返回
 * （按 42 风格通常返回 char *，需 malloc 出新的字符串；
 * 若 base 非法应返回 NULL 或按题目约定处理）*/

/*
 * 1.	校验两个 base 的合法性
 * •	len >= 2
 * •	不包含 + - 或空白（’ ’ 或 ASCII 9–13）
 * •	无重复字符
 * （用和 ft_putnbr_base / ft_atoi_base 同样的 is_valid_base）
 * 
 * 2.	把输入字符串解析成整数（有符号）
 * •	跳过前导空白（' ' 或 \t..\r）
 * •	处理多个 +/-（累乘符号）
 * •	从当前字符开始，按 base_from 查索引（index_in_base helper）
 * •	累加： value = value * base_from_len + digit，用 long 存储以避免 INT_MIN 溢出
 * •	遇到第一个不在 base_from 的字符停止解析（和 ft_atoi 行为一致）
 * 
 * 3.	把解析出来的整数转换为目标 base 的字符串
 * •	特殊处理 value == 0（直接返回 "0" 对应的字符）
 * •	记录并输出负号（如果 value < 0，先记号再对 -value 处理）
 * •	反向生成位（用 value % base_to_len 推索引，然后 value /= base_to_len），
 * 把字符收集到临时缓冲（例如固定长度数组或 malloc 动态扩展），
 * 最后反转顺序得到正确的高位→低位字符串。
 * •	使用 long 做内部运算以安全处理边界（INT_MIN）。
 * 
 * 4.	返回一个新分配的、以 \0 结尾的字符串
 * •	包含可能的 '-' 前缀
 * •	使用 malloc（或题目允许的分配方式），长度 = 位数 + 1(for sign maybe) + 1(for ‘\0’)。
 */

#include <stdlib.h>

static int	is_valid_base(char *base)
{
    	int	i;
		int	j;
			int	len;

				len = 0;
					while (base[len])
					    		len++;
						if (len < 2)
						    		return (0);
							i = 0;
								while (base[i])
								    	{
									    		if (base[i] == '+' || base[i] == '-' || base[i] == ' ' ||
														    (base[i] >= 9 && base[i] <= 13))
											    			return (0);
													j = i + 1;
															while (base[j])
															    		{
																	    			if (base[i] == base[j])
																				    				return (0);
																							j++;
																									}
																	i++;
																		}
									return (1);
}

static int	index_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static long	ft_strtol_base(char *str, char *base_from)
{
	int		i;
	int		sign;
	int		digit;
	long	value;
	int		base_len;

	value = 0;
	i = 0;
	sign = 1;
	base_len = 0;
	while (base_from[base_len])
		base_len++;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while ((digit = index_in_base(str[i], base_from)) != -1)
	{
		value = value * base_len + digit;
		i++;
	}
	return (sign * value);
}

static char	*build_to_base(long value, char *base_to)
{
	int		base_len;
	long	n;
	int		neg;
	char	buf[66];
	int		pos;
	char	*res;
	int		i;

	base_len = 0;
	while (base_to[base_len])
		base_len++;
	if (base_len < 2)
		return (NULL);
	if (value == 0)
	{
		res = (char *)malloc(2);
		if (!res)
			return (NULL);
		res[0] = base_to[0];
		res[1] = '\0';
		return (res);
	}
	neg = 0;
	n = value;
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	pos = 0;
	while (n > 0)
	{
		buf[pos++] = base_to[n % base_len];
		n /= base_len;
	}
	res = (char *)malloc(pos + neg + 1);
	if (!res)
		return (NULL);
	i = 0;
	if (neg)
		res[i++] = '-';
	while (pos > 0)
		res[i++] = buf[--pos];
	res[i] = '\0';
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	value;
	char		*result;

	if (!is_valid_base(base_from) || !is_valid_base(base_to))
		return (NULL);
	value = ft_strtol_base(nbr, base_from);
	result = build_to_base(value, base_to);
	return (result);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	printf("%s\n", ft_convert_base(argv[1], argv[2], argv[3]));
	return (0);
}
