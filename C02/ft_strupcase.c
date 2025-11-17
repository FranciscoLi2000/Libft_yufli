/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:44:01 by yufli             #+#    #+#             */
/*   Updated: 2025/11/17 09:53:09 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	size_t	i;
	unsigned char	c;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		c = (unsigned char)str[i];
		if (c >= 'a' && c <= 'z')
			str[i] = (char)(c - ('a' - 'A')); /* 更直观的偏移写法 */
		++i;
	}
	return (str);
}

/* 可读性 / 工业化质量清单
 * 
 * 短期（立刻能做）
 * 在项目里加 ft_string.h 并在 .c 里 #include 它（防止原型不匹配）。
 * 用 clang-format 或 astyle 统一代码格式（配置团队风格）。
 * 在函数顶部加简短注释：输入/输出约定（例如：是否接受 NULL，是否允许重叠 dest/src 等）。
 * 
 * 中期（增强健壮性）
 * 添加单元测试（见下面的测试用例），用 cmocka / Check / 直接写 assert 测试套件。
 * 使用 -Wall -Wextra -Werror -fsanitize=address,undefined 编译并修复警告/运行时错误。
 * 在 CI（GitHub Actions / GitLab CI）里自动运行编译与单测。
 * 
 * 长期（企业级）
 * 添加文档（README + API 约定）说明行为边界（NULL、重叠、编码假设）。
 * 把公共函数列入 API 文档，内部 helper 标记为 static。
 * 引入 clang-tidy / cppcheck 做静态检查并修复发现的问题。
 */
