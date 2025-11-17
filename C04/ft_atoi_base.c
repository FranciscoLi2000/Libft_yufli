/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:40:15 by yufli             #+#    #+#             */
/*   Updated: 2025/11/17 11:58:17 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 需要一个把字符映射到“位值”的环节，以及和 ft_atoi 一样的空白/符号处理逻辑。
 *
 * 要点总结：
 * 保留 ft_strlen 和 is_valid_base（并先用 is_valid_base 判断合法性）。
 * 先处理空白（space / \t..\r）和符号（+/-）——和 ft_atoi 一样。
 * 然后逐字读取输入字符串：把当前字符在 base 中查找其索引（索引就是该位的数值）。
 * 如果字符不在 base 中，就停止解析（像 ft_atoi 一样遇非数字就结束）。
 * 累加公式为：value = value * base_len + digit。
 * 最后返回 sign * value。*/

/* 要求：
 * 如果 c 在 base 中，返回它的索引（0..base_len-1）。
 * 如果 c 不在 base 中，返回 -1。
 * 符合你之前 ft_strlen / is_valid_base 的风格（简洁、规范）。 */
int	index_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	/* 返回 -1 表示字符不在 base 中；
	 * 否则返回字符在 base 中的索引 */
	return (-1);
}

static int	skip_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

static int	get_sign(char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

/* 用 index_in_base(str[i], base) 获得该字符对应的“位值”，记作 digit
 * 如果 digit == -1 → 停止解析（和 ft_atoi 遇到非数字时行为一致）
 * 否则累计： res = res * base_len + digit
 * 这样它就能处理任何 base（2〜62之类都行，只要 base 合法）*/

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		sign;
	int		digit;
	long	res;
	int		base_len;

	if (!is_valid_base(base))
		return (0);
	sign = 1;
	res = 0;
	i = skip_spaces(str);
	i += get_sign(str + i, &sign);
	while (str[i])
	{
		digit = index_in_base(str[i], base);
		if (digit == -1)
			break ;
		res = res * base_len + digit;
		i++;
	}
	return ((int)(sign * res));
}

