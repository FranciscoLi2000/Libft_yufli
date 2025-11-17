/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:41:26 by yufli             #+#    #+#             */
/*   Updated: 2025/11/17 09:43:20 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(const char *str)
{
	size_t	i;
	unsigned char	c;
	
	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		c = (unsigned char)str[i];
		if (!(c >= 'A' && c <= 'Z'))
			return (0);
		++i;
	}
	return (1);
}
