/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 13:37:52 by yufli             #+#    #+#             */
/*   Updated: 2024/12/28 20:47:15 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, unsigned int n)
{
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)&((unsigned char *)s)[i]);
		i++;
	}
	return (NULL);
}
