/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:53:43 by yufli             #+#    #+#             */
/*   Updated: 2024/12/28 20:41:19 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, unsigned int n)
{
	unsigned int	i;

	if (dest == NULL || src == NULL)
		return (NULL);
	if ((char *)dest > (const char *)src
		&& (char *)dest < (const char *)src + n)
	{
		i = n;
		while (i > 0)
		{
			i--;
			((char *)dest)[i] = ((const char *)src)[i];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((char *)dest)[i] = ((const char *)src)[i];
			i++;
		}
	}
	return (dest);
}