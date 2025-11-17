/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:12:17 by yufli             #+#    #+#             */
/*   Updated: 2025/11/17 10:17:25 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *dest, const char *src, int nb)
{
	int	i;

	i = 0;
	while ((dest[i] != '\0' || src[s] != '\0') && i <= nb)
	{
		if (dest[i] == src[i])
			return (i);
		i++;
	}
	return (i);
}
