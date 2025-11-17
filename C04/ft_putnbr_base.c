/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:26:43 by yufli             #+#    #+#             */
/*   Updated: 2025/11/17 11:40:06 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_putnbr_base(n, base_str)
 * 思路跟 ft_putnbr(n) 一样：
 * 十进制时，你是把数字分成「高位」和「低位」打印
 * 任意进制时也一样，只不过分母变成 base_len
 * 也就是说：
 * ft_putnbr(n):
 * 	print(n / 10)
 * 	print(n % 10)
 *
 * ft_putnbr_base(n):
 * 	print(n / base_len)
 * 	print(n % base_len)
 * 
 * 核心难点就在 「base_str[index] 代表这个数字的某个符号」。
 * 例：base = "01" → 二进制
 * 例：base = "0123456789ABCDEF" → 十六进制 */

/* base_str 的含义
 * "01" → 代表 0 和 1 → binary（二进制）
 * "01234567" → 代表 0~7 → octal（八进制）
 * "0123456789ABCDEF" → 代表十六进制符号 → hex（十六进制）
 * 
 * 但还有一个更重要的点：
 * base 字符串里的“字符位置（index）”就是数字的值。
 * 
 * 例如 "0123456789ABCDEF"
 * 'A' 的位置是 index 10 → 所以代表十进制的 10。
 * 这行代码你马上会写：
 * write(1, &base[n % base_len], 1); */

/* ft_putnbr_base 的过程其实就是：
 * 1. 算出 base_len
 * 2. 处理负号
 * 3. 递归打印高位 → 打印低位
 * 4. 低位字符从 base_str 中取：base_str[n % base_len] */

/* ft_putnbr_base — base 合法性检查需要的 4 项条件
 * 
 * ① base 长度必须 ≥ 2
 * 因为：
 * base 长度为 0 → 无意义
 * base 长度为 1 → 只能表示一个数字，无法进制
 * 
 * ② base 中不能有重复字符（你已经说对了）
 * 例如 "001"、"012233" 都是非法的。
 * 
 * base 必须满足：
 * len >= 2
 * 不能包含 + 或 -
 * 不能包含空白字符（space、tab、\n 等 ASCII 9~13）
 * 不能有重复字符（你最先想到的那个最关键）
 * 如果 base 不合法 → 不打印任何东西。
 *
 * ③ base 中不能包含 + 或 -
 * 因为 + / - 会和数字符号冲突。
 * 
 * ④ base 中不能包含空白字符（space 或 ASCII 9~13）
 * 因为它们也会在解析数字时造成歧义。
 *
 * 核心公式：
 * 高位： n / base_len
 * 低位： n % base_len
 * 并且：
 * 如果 n < base_len → base case → 只打印一位
 * 否则 → 递归打印高位再打印低位
 * 最终打印字符：
 * write(1, &base[n % base_len], 1); */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_valid_base(char *base)
{
	int	i;
	int	j;
	int	len;

	len = ft_strlen(base);
	if (len < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' ||
				base[i] == ' ' ||
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

static void	putnbr_base_long(long n, char *base, int base_len)
{
	if (n < base_len)
	{
		write(1, &base[n], 1);
		return ;
	}
	putnbr_base_long(n / base_len, base, base_len);
	write(1, &base[n % base_len], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	n;
	int		base_len;

	if (!is_valid_base(base))
		return ;
	base_len = ft_strlen(base);
	n = (long)nbr;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	putnbr_base_long(n, base, base_len);
}

/* 测试建议
 * ft_putnbr_base(5, "01") → 输出 101
 * ft_putnbr_base(255, "0123456789ABCDEF") → 输出 FF
 * ft_putnbr_base(-42, "0123456789") → 输出 -42
 * 非法 base（如 "0"、含重复或含 +/空白）应不打印任何内容 */

