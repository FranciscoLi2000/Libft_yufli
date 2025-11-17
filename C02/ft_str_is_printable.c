/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:39:11 by yufli             #+#    #+#             */
/*   Updated: 2025/11/17 09:40:52 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(const char *str)
{
	size_t	i;
	unsigned char	c;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		c = (unsigned char)str[i];
		/* 可打印 ASCII 范围通常是 32..126（127 是 DEL） */
		if (!(c >= 32 && c <= 126))
			return (0);
		++i;
	}
	return (1);
}
