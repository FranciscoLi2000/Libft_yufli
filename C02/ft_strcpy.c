/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:24:40 by yufli             #+#    #+#             */
/*   Updated: 2025/11/17 09:26:13 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 注意：在 C 标准库实现中，char 可能带符号，
 * 为了比较字符数值安全地使用 unsigned char */
char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	if (dest == NULL || src == NULL)
	    return (dest); /* 工业代码通常会选择断言或返回 NULL，根据项目风格决定 */
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}
