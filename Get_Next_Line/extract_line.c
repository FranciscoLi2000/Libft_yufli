/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 07:55:39 by yufli             #+#    #+#             */
/*   Updated: 2025/11/16 11:03:41 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char **left)
{
	char	*line;
	char	*nl_pos;
	size_t	len;

	if (!*left || !**left)
		return (NULL);
	nl_pos = ft_strchr(*left, '\n');
	if (nl_pos)
	{
		len = nl_pos - *left + 1;
		line = ft_substr(*left, 0, len);
		nl_pos = ft_strdup(*left + len);
		free(*left);
		*left = nl_pos;
		return (line);
	}
	line = ft_strdup(*left);
	free(*left);
	*left = NULL;
	return (line);
}
