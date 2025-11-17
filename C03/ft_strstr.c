/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:00:19 by yufli             #+#    #+#             */
/*   Updated: 2025/11/17 11:08:19 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 返回 str（原字符串的开始地址）
 * 原因非常重要（必须记住）：
 * 在 C 标准库中，子串为空时，认为“空串总是匹配在起始位置”。
 * 也就是说：
 * strstr("hello", "")   返回指向 "hello" 的指针  (haystack)
 * strstr("", "")        返回指向 "" 的指针       (haystack)
 * 没有任何例外。
 * 为什么不是 NULL？
 * 因为 NULL 表示“完全找不到”，而空串是可以“找到”的，而且定义为“在开头”。
 * 这和 Python / JS / Java 等语言的行为一致。
 * 若 to_find[0] == '\0'，则直接返回 str */

/* str 中每遇到一个字符等于 to_find[0] → 尝试继续匹配整个子串 */

/* 匹配逻辑（最关键的一步）
 * 当你遇到一个 str[i] == to_find[0] 时，你需要做：
 * 继续看 str[i + j] == to_find[j] 是否成立
 * 直到：
 * 有字符不匹配 → 中断这次尝试
 * 匹配到 to_find 到达 '\0' → 成功找到子串
 *
 * 每遇到一个字符等于 to_find[0]，就尝试逐字检查；
 *
 * 若失败，只中断本次尝试，不退出函数 */

/* 常见写法是双层循环：
 * 外层：遍历 i（str 的每个位置）
 * 内层：遍历 j（匹配 to_find 里的每个字符）
 * 当 to_find[j] == '\0' 时表示：
 * 我们已经成功匹配完了 to_find 的全部内容
 * ⇒ 此时 strstr 要返回“匹配开始的位置”
 * 也就是：
 * return (&str[i]);
 * 示例：
 * str      = "hello world"
 * to_find  = "world"
 *
 * 匹配到 to_find 完成的那一刻：
 * str[6] = 'w' 开始的位置
 * return &str[6]; */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (to_find[0] == '\0')
	    return (str);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (to_find[j] && str[i + j] && str[i + j] == to_find[j])
			j++;
		if (to_find[j] == '\0')
			return (&str[i]);
		i++;
	}
	return (NULL);
}

/* 改动要点回顾
 * if (to_find[0] == '\0') return (str); — 处理空子串的标准行为。
 * 内层 while 条件：to_find[j] && str[i + j] && str[i + j] == to_find[j]
 * str[i + j] 的检查保证不会越界读取并在 str 尾部停止尝试。
 * 匹配成功的条件还是 to_find[j] == '\0'（匹配完所有字符）。
*/

/* 快速测试用例
 * ft_strstr("hello", "") → 返回 pointer to "hello"
 * ft_strstr("", "") → 返回 pointer to ""
 * ft_strstr("abcabc", "cab") → 返回 pointer to str + 2（即 "cab..."）
 * ft_strstr("abc", "abcd") → NULL（to_find 长于剩余 haystack）
 * ft_strstr("abababab", "bab") → 返回 pointer to first "bab"
 * ft_strstr("hello", "lo") → 返回 pointer to "lo"
 */

/* 额外的可选改进
 * 把 to_find 和 str 标注为 const char *（如果你的 API/题目允许），更安全。
 * 用 size_t 或 unsigned int 做索引（Piscine 通常用 int 也可以，但注意跨平台）。
 * 用 unsigned char 暂存比较（当你担心 char 是否带符号时）。*/

