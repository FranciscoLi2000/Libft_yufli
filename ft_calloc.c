/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:59:36 by yufli             #+#    #+#             */
/*   Updated: 2024/12/28 21:25:02 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(unsigned int nmemb, unsigned int size)
{
	void	*ptr;
	int		i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	if (nmemb > 0 && size > (unsigned int)(-1) / nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while ((unsigned int)i < nmemb * size)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
