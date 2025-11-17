/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:34:25 by yufli             #+#    #+#             */
/*   Updated: 2025/11/17 16:18:44 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_putstr_non_printable（打印不可打印字符，用 \xx 的十六进制表示） */
/* 当你打印不可打印字符
 * 当你把字符转成 \xx 十六进制
 * 当你打印内存区域
 *
 * 你必须把 char 当成 0–255 的整数值（无符号 byte） 来处理 */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int			i;
	unsigned char	c;
	unsigned char	high;
	unsigned char	low;
	char		hex[17] = "0123456789abcdef";

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		c = (unsigned char)str[i];
		if (c >= 32 && c <= 126)
			write(1, &c, 1);
		else
		{
			high = c / 16;
			low  = c % 16;
			write(1, "\\", 1);
			write(1, &hex[high], 1);
			write(1, &hex[low], 1);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	ft_putstr_non_printable(argv[1]);
	write(1, "\n", 1);
	return (0);
}
