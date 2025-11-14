/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 21:33:43 by yufli             #+#    #+#             */
/*   Updated: 2025/11/14 21:33:45 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	i;
	int	len;
	int	*range;

	i = 0;
	if (end < start)
		len = start - end + 1;
	else
		len = end - start + 1;
	range = (int *)malloc(len * sizeof(int));
	while (i < len)
	{
		if (start < end)
			range[i] = start++;
		else
			range[i] = start--;
		i++;
	}
	return (range);
}
