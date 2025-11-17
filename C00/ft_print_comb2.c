/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:59:11 by yufli             #+#    #+#             */
/*   Updated: 2025/11/17 09:04:22 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 固定任务 — 
 * 输出所有两位数对 00 01, 00 02, ... 98 99
 * （每个元素是 00–99 的两位数，且第一个数 < 第二个数）
 * 可以用两层循环（i 从 0 到 98，j 从 i+1 到 99）
 * 需要把数字格式化为两位字符（leading zero）*/

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	put_two_digits(int n)
{
	ft_putchar('0' + (n / 10));
	ft_putchar('0' + (n % 10));
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;
	int	first;

	first = 1;
	i = 0;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			if (!first)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			put_two_digits(i);
			ft_putchar(' ');
			put_two_digits(j);
			first = 0;
			j++;
		}
		i++;
	}
}

/* 要点：
 * 用 i、j 控制 0..99 的组合，j = i + 1 保证不重复且有序。
 * put_two_digits 负责补零并输出两位数。
 * 用 first 控制最后不多输出逗号空格（或者你也可以在每次输出后判断是否为最后一个组合）。
 */
