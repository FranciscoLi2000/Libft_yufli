/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:18:52 by yufli             #+#    #+#             */
/*   Updated: 2025/11/17 11:22:01 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 用 long 处理 INT_MIN（必须，否则会溢出）
 * 递归逻辑清晰
 * 先打印符号，再处理正数
 * 基础部分 0~9 单独处理
 * 完全符合 norminette
 * 
 * 唯一一点工业级优化（非必须，但更可读）
 * 把 base case 和 recursive case 明确分组：*/
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	n;

	n = nb;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n < 10)
	{
		ft_putchar(n + '0');
		return ;
	}
	ft_putnbr(n / 10);
	ft_putnbr(n % 10);
}
/* 这样逻辑更“块状”，一眼就知道哪里是 BASE，哪里是 RECURSION。 */
