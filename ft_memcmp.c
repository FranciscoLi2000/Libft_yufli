/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 13:54:51 by yufli             #+#    #+#             */
/*   Updated: 2024/12/28 14:59:19 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, unsigned int n)
{
	unsigned int	i;

	if (str1 == NULL || str2 == NULL)
		return (0);
	i = 0;
	while (i < n)
	{
		if (((char *)str1)[i] != ((char *)str2)[i])
			return (((char *)str1)[i] - ((char *)str2)[i]);
		i++;
	}
	return (0);
}
