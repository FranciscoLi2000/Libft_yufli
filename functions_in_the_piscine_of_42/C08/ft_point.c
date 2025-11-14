/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 21:37:06 by yufli             #+#    #+#             */
/*   Updated: 2025/11/14 21:37:08 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

include "ft_point.h"
#include <stdio.h>

void	set_point(t_point *point)
{
	point-> x = 42;
	point-> y = 21;
}

int	main(void)
{
	t_point	point;

	set_point(&point);
	printf("Valor de x: %d\n", point.x);
	printf("Valor de y: %d\n", point.y);
	return (0);
}
