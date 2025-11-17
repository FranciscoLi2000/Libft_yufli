/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:32:37 by yufli             #+#    #+#             */
/*   Updated: 2025/11/17 09:34:20 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(const char *str)
{
	size_t	i;
	unsigned char	c;

	if (str == NULL)
		return (0); /* 约定：NULL 视为非字母字符串 */
	i = 0;
	while (str[i] != '\0')
	{
		c = (unsigned char)str[i];
		if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')))
			return (0);
		++i;
	}
	return (1);
}
