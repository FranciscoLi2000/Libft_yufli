/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:22:48 by yufli             #+#    #+#             */
/*   Updated: 2025/11/17 08:56:32 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 非常适合练数组内存模型）
 * 这个函数是 C01 中最适合练习：
 * 双层循环
 * 索引 vs 指针遍历
 * 值交换（swap）
 * 数组内存访问顺序
 * 最后一个边界怎么处理
 * 为什么 bubble sort 需要两层循环 */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	if (size <= 1)
	    return ;
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

/* 排序方式：升序
 * 不能使用库函数。
 * 可以用任意喜欢的写法，比如：
 * 双层循环交换
 * 最简单的冒泡排序
 * 甚至自己想的比较方式 */

/* 用 i < size - 1 和 j < size 保证严格按元素数目遍历，不会越界，也不会被数组中值（比如 0）误导。
 * 这是一种选择排序/交换排序的形式（O(n²)），对 piscíne 的要求完全足够且容易理解。*/

/* 
 * 可选：稍微优化的冒泡（带提前退出）
 * 如果数组已近似有序，提前退出会快一些：

void	ft_sort_int_tab_optimized(int *tab, int size)
{
	int	swapped;
	int	i;
	int	j;
	int	tmp;

	if (size <= 1)
	    return ;
	i = 0;
	while (i < size - 1)
	{
		swapped = 0;
		j = 0;
		while (j < size - 1 - i)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
				swapped = 1;
			}
			j++;
		}
		if (!swapped)
			break ;
		i++;
	}
}

* 这是典型冒泡排序，每轮把最大值“冒”到最后，size-1-i 能减少已排好部分的比较。
* swapped 用来判断当前轮是否有交换，若无交换说明已排序好，提前退出。
* 一、为什么 optimized 冒泡排序对“部分有序”数组有加速效果？
* 普通冒泡无论数组是否已经 sorted，都要比较 n²/2 次。
* optimized 版本含义：
* 如果某一轮没有发生过交换，那数组已经完全有序了
* 冒泡排序的特性：
* 如果数组已经有序，第一轮扫描就会发现没有任何交换
* 那就直接退出，不跑剩下的 n 轮
* optimized 冒泡对“几乎有序”的数组性能接近线性（O(n)）。
* 普通冒泡则永远是 O(n²)。*/

/* 指针风格（练习指针与索引的等价性）
 * 如果你想练指针遍历与索引遍历的对比，可以试试下面的指针实现（同样基于冒泡）

void	ft_sort_int_tab_ptr(int *tab, int size)
{
	if (size <= 1)
		return ;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			int *a = tab + j;
			int *b = tab + j + 1;
			if (*a > *b)
			{
				int tmp = *a;
				*a = *b;
				*b = tmp;
			}
		}
	}
}

这里用 tab + j 得到指针，再通过 *a / *b 操作，练习指针算术和解引用。*/

#include <stdio.h>

int	main(void)
{
	int arr[] = {3, 0, -1, 5, 2, 0};
	int size = sizeof(arr) / sizeof(arr[0]);

	ft_sort_int_tab(arr, size);
	for (int i = 0; i < size; i++)
	    printf("%d ", arr[i]);
	printf("\n");
	return (0);
}
