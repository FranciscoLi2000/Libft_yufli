/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:18:51 by yufli             #+#    #+#             */
/*   Updated: 2025/11/17 10:32:39 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* strlcpy 的设计目的就是：
 * “无论是否截断，都要让调用者知道 src 有多长。”
 * 这让调用者可以：
 * 判断是否发生了截断（当返回值 ≥ destsize 时，就是截断）
 * 决定是否需要重新分配更大的缓冲区 */

/* strlcpy 最容易被忽略的行为之一：
 * 当 destsize == 0 时：
 * 完全不拷贝
 * 不能写 '\0'（因为缓冲区大小为 0）
 * 返回 src 的长度 */

/* 在拷贝阶段必须同时满足：
 * i < destsize - 1（保证有空间留给终止符 '\0'）
 * src[i] != '\0'（不能超过源字符串） */

/* destsize > 0 时必须写 dest[i] = '\0'。
 * 当 destsize == 0 时不能写（会越界）。 */

/* Conclusion:
 * 1. 计算 src 的长度（提示：需要一个变量来计数） -> 不能用 strlen，这是 42 C02 的要求
 *
 * 2. 如果 size == 0： return src 的长度；
 *
 * 3. 否则：
 * 	拷贝字符：
 * 		while (??? && ???)
 * 			dest[i] = src[i];
 *
 * 4. 写入 '\0' 终止符（但必须确保 size > 0）
 *
 * 5. 返回：src 的长度（不是拷贝长度）
 */

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	s_len;
	unsigned int	i;

	s_len = 0;
	while (src[s_len])
		s_len++;
	if (size == 0)
		return (s_len);
	i = 0;
	while (i < size - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (s_len);
}

#include <stdio.h>
#include <string.h>
#include <assert.h>

void	run_case(const char *src, unsigned int size)
{
	char	dest[32];
	unsigned int	r1;
	unsigned int	r2;

	/* clear dest to see termination */
	for (int i = 0; i < 32; ++i)
		dest[i] = '?';
	r1 = ft_strlcpy(dest, src, size);
	r2 = (unsigned int)strlen(src);

	printf("src=\"%s\", size=%u -> returned=%u, strlen=%u, dest=\"%s\"\n",
		src, size, r1, r2, (size > 0 ? dest : "(not written)"));
	/* sanity asserts */
	assert(r1 == r2);
	if (size == 0)
	{
		/* dest unchanged */
	}
	else
	{
		/* dest must be NUL terminated */
		assert(dest[size - 1] == '\0' || strlen(dest) < size);
	}
}

int	main(void)
{
	run_case("", 0);
	run_case("", 1);
	run_case("a", 0);
	run_case("a", 1);
	run_case("a", 2);
	run_case("hello", 3);
	run_case("hello", 6);
	run_case("this is a longer string", 10);
	printf("All tests ran (check output above).\n");
	return (0);
}
