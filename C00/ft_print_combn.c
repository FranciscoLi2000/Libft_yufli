/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:04:30 by yufli             #+#    #+#             */
/*   Updated: 2025/11/17 09:13:43 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 通用 n 的组合生成（0 < n < 10），
 * 要求输出从 0..9 中选 n 个数的升序组合（每个组合内部递增，组合间按字典序）。
 * 这不是简单的固定层数循环，适合用递归/回溯或通用的迭代组合生成算法。
 * 所以：ft_print_comb 和 ft_print_comb2 都可以用嵌套循环（固定层数），
 * 但 ft_print_combn 要用递归或通用组合生成（更通用、更优雅）*/

/* 核心思想：
 * 维护一个长度为 n 的数组 comb[]，从最小可能值开始填；
 * 递归层 pos 表示当前要填入第 pos 位（0..n-1）。
 * 每一层尝试的数字从 start 到 9 - (n - pos) + 1（确保后面还能填够数字），
 * 当 pos == n 时打印当前组合。
 */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	print_comb(int *comb, int n)
{
	int	i;

	for (i = 0; i < n; i++)
	    ft_putchar('0' + comb[i]);
}

/* recursion:
 * pos: current index to fill (0..n-1)
 * start: smallest digit candidate for this pos
 */
static void	build(int pos, int n, int start, int *comb, int *first)
{
	int	d;

	if (pos == n)
	{
		if (!*first)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
		print_comb(comb, n);
		*first = 0;
		return ;
	}
	/* maximum starting digit so that there are enough digits left:
	 * last possible digit is 9, so start can go up to 9 - (n - pos) + 1 */
	for (d = start; d <= 9 - (n - pos) + 1; d++)
	{
		comb[pos] = d;
		build(pos + 1, n, d + 1, comb, first);
	}
}

void	ft_print_combn(int n)
{
	int	comb[10]; /* n < 10 so safe */
	int	first = 1;

	if (n <= 0 || n >= 10)
	    return ;
	build(0, n, 0, comb, &first);
}

/* 关键细节解释：
 * for (d = start; d <= 9 - (n - pos) + 1; d++)：
 * 这是为了保证剩下的位置能放下足够的数字（避免后续无法填满）。
 * 也可以写成 d <= 10 - (n - pos)，两种写法等价（你可以自己推一遍）。
 * 每次递归调用时把 d+1 作为下一层的 start，保证递增且不重复。
 * 用 first 控制逗号空格输出。
 */
