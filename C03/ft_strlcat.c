/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:34:10 by yufli             #+#    #+#             */
/*   Updated: 2025/11/17 10:45:55 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 即使发生截断，也必须返回 原 dest 的长度 + src 的总长度。
 * 这是 strlcat 最关键的行为，也是 42 学员最容易搞错的地方之一。
 * 
 * 标准行为是：
 * 返回的永远是“理论上拼接完成后的总长度”，
 * 而不是实际写入多少。
 * 
 * 这让调用者能判断是否截断：
 * 如果返回值 < size：没有截断
 * 如果返回值 ≥ size：发生截断（或者空间一开始就不够）
 * 
 * 和 strlcpy 一样，这是一个“我告诉你原本应该多长”的思路。
 * strlcat 返回：dest 原长度 + src 的总长度。与是否写满无关。*/

/* 第三个参数 size 是 dest 缓冲区的总容量。这是理解 strlcat 的核心前提。*/

/* 如果 size <= strlen(dest)，一个字节都不能写入
 * 但这里还有一条隐藏规则：
 * 返回值依然是 strlen(dest) + strlen(src)，
 * 即使你一个字符都没写入。*/

/* 写入量 = 剩余可用空间减去 1（留给 '\0'）
 * 也就是：
 * 可写入最大数量 = size - strlen(dest) - 1
 * 在我们的例子里：
 * size          = 10
 * strlen(dest)  = 5
 * size - strlen(dest) - 1 = 4
 * 所以你能写最多 4 个字符（并不是 9 个）。
 * 但因为 src 长度是 5，所以你实际写 min(5, 4) = 4 个。*/

/* 1. 计算 dest_len 和 src_len
 *
 * 2. 如果 size <= dest_len： return dest_len + src_len;
 * 
 * 3. 否则可以写入 (size - dest_len - 1) 个字符：
 * 	while ( ??? )
 * 	{
 * 		dest[dest_len + i] = src[i];
 * 		i++;
 * 	}
 * 4. 写 '\0'
 *
 * 5. 返回 dest_len + src_len
 */

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	i;
	unsigned int	max_copy;

	dest_len = 0;
	src_len = 0;
	while (dest[dest_len])
		dest_len++;
	while (src[src_len])
		src_len++;
	if (size <= dest_len)
		return (dest_len + src_len);
	max_copy = size - dest_len - 1;
	/* guaranteed no underflow because size > dest_len */
	i = 0;
	while (i < max_copy && src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

/* 每处改动的简短理由
 * dest_len = 0; src_len = 0;：避免使用未初始化变量。
 * 先计算 dest_len 与 src_len：函数返回值需要两者。
 * if (size <= dest_len) return dest_len + src_len;：当 buffer 太小时不写入，但仍返回“理论长度”。
 * max_copy = size - dest_len - 1;：剩余可复制字符数（保留一字节给 '\0'）。
 * 拷贝循环 i < max_copy && src[i]：防止越界和拷完源。
 * 直接写 dest[dest_len + i] = '\0';：此处安全，因为 size > dest_len 已保证。
 */

/* 推荐的快速测试用例
 * dest = "", src = "abc", size = 0 → 不写入，返回 3。
 * dest = "", src = "abc", size = 1 → 写入 0 个字符（留下 '\0'），返回 3。
 * dest = "hello", src = "42", size = 3 → size <= dest_len（5），不写，返回 7。
 * dest = "hello", src = "world", size = 10 → dest_len=5, src_len=5, max_copy = 4 → 写入 "worl"，dest = "helloworl"，返回 10。
 * dest = "abc", src = "", size = 5 → 不改 dest（除了可能写终止符在正确位置），返回 3。
 * dest capacity 边界： dest_len + 1 == size（只有终结符空间）→ 不写任何 src 字符。
 * 你可以把之前给你的 test_strlcpy.c 改造成 test_strlcat.c 来跑这些用例（我可以把示例给你，如果你需要）。
 */

/* 小的风格 / Norm 建议
 * 名字：dest_len、src_len、max_copy、i 都很直观，保持即可。
 * 注释：在函数顶部写一行短注释说明行为（size 表示 buffer 容量、返回值语义）。
 * 如果你想更工业化，未来把 unsigned int 换成 size_t 并包含 <stddef.h>。
 */
