/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:27:29 by yufli             #+#    #+#             */
/*   Updated: 2025/11/17 15:24:58 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdio.h>

/* 理解了因子“成对出现”的原理
 * 理解了 sqrt 剪枝的数学来源
 * 理解了为什么循环写到 “i * i <= nb” 就足够
 * 理解了为什么这在判断质数和平方根里都适用
 * 用自己的话解释了原因（最重要）
 * 所以现在你已经「真正学会了」。
 * 你以后再也不会忘。
 * 
 * N 皇后是 C05 的终极题，是整个 piscine 里逻辑含量最高的之一。
 * 它会让你用到：
 * 递归
 * 回溯（backtracking）
 * 剪枝（pruning）
 * 多维限制条件（行、列、主对角线、副对角线）
 * 状态恢复 */

/* 1.	棋盘表示（建议用一维数组，不是必须但更简洁、也更常用）
 *  •	二维矩阵能表示棋盘，但对 N 皇后来说没必要把整张棋盘存下来。
 *  •	常用且高效的表示是：int placed[N]; 其中 placed[col] = row 表示在第 col 列放了一个皇后，放在第 row 行。
 *  •	这样每列恰好放一个皇后，节省了空间和检查工作。
 *  
 *  2.	冲突判断（不是用行+列完全比较）
 *  •	因为我们按列逐列放皇后，列是天然不冲突（每列只放一次）。
 *  •	需要检查的只有：
 *  •	同一行（是否有别的列也放在相同行）
 *  •	同一主/副对角线（两皇后在对角线冲突的判定可用行差等于列差）
 *  •	判定两个皇后 (c1,r1) 和 (c2,r2) 是否冲突的快速条件：
 *  •	r1 == r2（同行冲突） 或 abs(r1 - r2) == abs(c1 - c2)（对角线冲突）
 *
 *  3.	回溯的核心流程（模板化，很简单）
 *  •	试着把皇后放在当前列的某一行 → 调用递归去放下一列 → 如果失败就撤销（undo）并尝试下一行。
 *  •	模板（伪代码）：
 *  solve(col):
 *      if col == N: record_solution; return;
 *          for row in 0..N-1:
 *                  if is_valid(col, row):
 *                              placed[col] = row;
 *                                          solve(col + 1); // undo 可选：placed[col] = -1;
 *  •	“撤销”通常只需覆盖 placed[col] 下一个尝试时会覆盖上一值，所以显式撤销不是必须但常写以便清晰。
 *
 * 4.	复杂度与“指数级”误区
 * •	典型 N 皇后是按列分支，每列有 N 个选择，理论上是 O(N^N) 的上界，
 * 但通过剪枝（is_valid）实际搜索空间远小于穷举全盘。
 *
 * 常见的直觉说法是“指数级”，这概念上没错，但更精确的是回溯树的分支因子随列而降，实际复杂度依 N 而异。
 * 
 * 重点是：剪枝决定能否在合理时间内解决 10 皇后这个规模 —— 对 N=10 是可行的。*/

/* placed: 已放置的列->行 映射
 * col:  当前要放的列
 * row:  当前尝试放的行
 * n:    棋盘大小（这里是 10，但写通用更好）
 * 返回 1 表示可以放，0 表示冲突 */
static int	is_valid(int placed[], int col, int row, int n)
{
	int	i;
	int	diff_row;
	int	diff_col;

	i = 0;
	while (i < col)
	{
		if (placed[i] == row)
			return (0);
		diff_row = placed[i] - row;
		if (diff_row < 0)
			diff_row = -diff_row;
		diff_col = i - col;
		if (diff_col < 0)
			diff_col = -diff_col;
		if (diff_row == diff_col)
			return (0);
		i++;
	}
	return (1);
}
/* 怎样用递归 + 回溯求出十皇后问题的“解的数量”
 */

/* 写回溯 solve(col)
 *
 * solve 只负责一件事：
 *
 * 在第 col 列放一个皇后，然后递归处理下一列。
 *
 * 我们只放 10 列，所以当 col == 10 时 —— 找到一个完整解。*/
static int	solve(int placed[], int col, int n)
{
	int	count;
	int	row;

	if (col == n)
		return (1);
	count = 0;
	row = 0;
	while (row < n)
	{
		if (is_valid(placed, col, row, n))
		{
			placed[col] = row;
			count += solve(placed, col + 1, n);
			placed[col] = -1;
		}
		row++;
	}
	return (count);
}
/* solve(col+1) 会尝试所有后续列的摆法
 * 每条摆法会最终返回完整解的数量
 * count 累加这个返回值
 *
 * 只有当 col == n 时（所有列放完）才真正返回 1（+1）。*/

/* 这种负责「初始化环境并启动递归/回溯」的函数通常就叫入口函数（entry function）。
 * 它的职责很简单：准备状态（比如数组、计数器），然后调用核心递归函数 solve(...)，
 * 最后把结果返回或输出。
 * 入口函数把复杂的实现细节包起来，调用者只关心“我要多少解”或“我要打印解”。*/
/* 入口函数：初始化并返回 10 皇后解的数量 */
int	ft_ten_queens_puzzle(void)
{
	int	placed[10];
	int	i;

	i = 0;
	while (i < 10)
	{
		placed[i] = -1;
		i++;
	}
	return (solve(placed, 0, 10));
}

int	main(void)
{
	printf("Solution: %i\n", ft_ten_queens_puzzle());
	return (0);
}
