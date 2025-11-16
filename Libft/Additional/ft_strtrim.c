/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 21:50:44 by yufli             #+#    #+#             */
/*   Updated: 2025/11/14 21:50:50 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;

	if (!s || !set)
		return (NULL);
	start = 0;
	while (s[start] && ft_strchr(set, s[start]))
		start++;
	len = ft_strlen(s);
	if (start == len)
		return (ft_substr(s, start, 0));
	end = len - 1;
	while (end > start && ft_strchr(set, s[end]))
		end--;
	return (ft_substr(s, start, end - start + 1));
}
