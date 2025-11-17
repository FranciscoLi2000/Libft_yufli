/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:46:48 by yufli             #+#    #+#             */
/*   Updated: 2025/11/17 10:59:59 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 边界处理 + 字符分类思维的函数 
 * 当遇到一个“单词”时：
 * 单词 第一个字符 要变成大写
 * 单词 后续字符 要变成小写
 */

/* 单词由 字母(a–z, A–Z) 和 数字(0–9) 组成。
 * 遇到其他任何字符（包括 -, +, *, 空格, !, / 等）就算“单词分隔符”。*/

/* 数字是单词的一部分
 * 所以像：
 * "42abc" → 整串是一个单词
 * "ab3cd" → 整串是一个单词
 * "123hello" → 整串是一个单词
 * 这会让后续大小写处理的逻辑更简单，因为单词的界限非常明确：
 * “字母/数字连续 = 单词；其他字符 = 分隔符。” */

/* 可以用一个状态机来写（不是难，是最清晰的）。
 * 我们只需要维护一个布尔：
 * int new_word = 1;
 * 意思是：
 * new_word == 1: 下一个遇到的“字母数字字符”必须做“单词开头格式化”
 * new_word == 0: 我们正处在单词中间，遇到字母时要转小写 */

/* 核心思路（一句话版）
 * 用 new_word 状态（初始为 1）。遍历每个字符 c：
 * 如果 c 是字母或数字：
 * 如果 new_word == 1 且 c 是字母：把它 大写（如果不是字母就保持不变）；把 new_word = 0。
 * 否则（new_word == 0）：如果 c 是字母，把它 小写（数字保持不变）。
 * 如果 c 不是字母/数字：把 new_word = 1（下一个字母/数字是新单词开头）。
 */

/* 实现细节要点（记在心里）
 * 使用 unsigned char 暂存字符再比较，避免 char 带符号问题（工业写法）。在 Piscine 可选，但推荐。
 * 用 if (c >= 'a' && c <= 'z') / if (c >= 'A' && c <= 'Z') 判断并用 c += 'a' - 'A' 或 c -= 'a' - 'A' 做大小写转换（不要用魔法数字）。
 * 初始 new_word = 1（字符串开头视为新单词）。
 * 保持对 '\0' 的正确终止条件：while (str[i])。
 * 不需要处理 NULL（Piscine 不要求），但用注释注明假设 str != NULL。
 */

char	*ft_strcapitalize(char *str)
{
	unsigned char	*s;
	int		new_word;
	int		i;

	s = (unsigned char *)str;
	new_word = 1;
	i = 0;
	/* 假设 new_word 已初始化为 1, i 已初始化为 0, s = (unsigned char *)str */
	while (s[i])
	{
		if (ft_isalpha(s[i]) || ft_isdigit(s[i]))
		{
			if (new_word)
			{
				if (ft_isalpha(s[i]))
					s[i] = s[i] - ('a' - 'A'); /* uppercase */
				new_word = 0;
			}
			else
			{
				if (ft_isalpha(s[i]))
					s[i] = s[i] + ('a' - 'A'); /* lowercase */
			}
		}
		else
			new_word = 1;
		i++;
	}
	return ((char *)s);
}

/* 几点说明：
 * new_word 只在遇到非字母数字时设回 1（外层 else）。
 * i++ 在循环尾部统一执行。
 * 使用 ('a' - 'A') 代替 32 更直观。
 * 循环结束后 return (char *)s; 或 return (str);。 */

/* 建议的快速测试（手工或用小程序跑）
 * "hello, world" → "Hello, World"
 * "salut, 42mots quarante-deux; cinquante+et+un" → "Salut, 42mots Quarante-Deux; Cinquante+Et+Un"（注意数字在单词内不分割）
 * ""（空串） → 仍为空串
 * "aBc dEf" → "Abc Def"（连续空格不会破坏逻辑）
 * 包含已经大写首字母的单词："Hello" → 仍为 "Hello"（验证我们不把 'H' 改坏）*/

