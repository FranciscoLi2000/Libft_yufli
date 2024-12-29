/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:33:37 by yufli             #+#    #+#             */
/*   Updated: 2024/12/28 17:58:38 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	num;

	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (sign * num);
}
