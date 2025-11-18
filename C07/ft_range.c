/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 21:33:43 by yufli             #+#    #+#             */
/*   Updated: 2025/11/18 10:40:13 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	i;
	int	len;
	int	*range;
	int	cur;

	if (start <= end)
		len = (size_t)(end - start);
	else
		len = (size_t)(start - end);
	range = malloc(len * sizeof(int));
	cur = start;
	i = 0;
	while (i < len)
	{
		range[i] = cur;
		if (start < end)
			++cur;
		else
			--cur;
		++i;
	}
	return (range);
}
