/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:36:58 by yufli             #+#    #+#             */
/*   Updated: 2025/11/17 09:38:40 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(const char *str)
{
	size_t	i;
	unsigned char	c;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		c = (unsigned char)str[i];
		if (!(c >= '0' && c <= '9'))
			return (0);
		++i;
	}
	return (1);
}
