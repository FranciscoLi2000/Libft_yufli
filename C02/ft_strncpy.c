/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:30:28 by yufli             #+#    #+#             */
/*   Updated: 2025/11/17 09:54:20 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	if (dest == NULL || src == NULL)
		return (dest);
	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	/* if n > strlen(src) pad with '\0' */
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}

/* 推荐测试用例
 * 
 * 空字符串 "" 对所有 is_* 返回值的期望（通常视为 true，或取决于 spec）。
 * 
 * 含有空格的字符串（" "）对 is_printable 返回 1。
 * 
 * 含有 \n 或 \t 的字符串对 is_printable 返回 0。
 * 
 * ft_strncpy：src = "abc", n = 2 → dest 应为 "ab"（没有终止符在 dest[2] 附加时要注意）。
 * ft_strncpy：src = "ab", n = 5 → dest 前两个为 a,b，其余填 \0。
 * 
 * 字符边界测试（127、128、负值 cast 的情况）以验证 unsigned char 的必要性。
 * 
 * ft_strupcase/lowcase 对混合字符的转换与非字母字符保持不变。
 */
