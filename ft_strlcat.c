/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:21:59 by yufli             #+#    #+#             */
/*   Updated: 2024/12/28 21:10:20 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	destsz;
	unsigned int	srcsz;
	unsigned int	i;

	i = 0;
	if (src == NULL || dest == NULL)
		return (0);
	destsz = 0;
	while (dest[destsz] != '\0' && destsz < size)
		destsz++;
	srcsz = 0;
	while (src[srcsz] != '\0')
		srcsz++;
	if (destsz >= size)
		return (size + srcsz);
	while (src[i] != '\0' && (i + destsz + 1) < size)
	{
		dest[destsz + i] = src[i];
		i++;
	}
	dest[destsz + 1] = '\0';
	return (destsz + srcsz);
}
