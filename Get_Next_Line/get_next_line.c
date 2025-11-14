/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 21:57:25 by yufli             #+#    #+#             */
/*   Updated: 2025/11/14 21:57:41 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line;

	leftover = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	leftover = fill_line_buffer(fd, leftover);
	if (!leftover)
		return (NULL);
	line = extract_line(&leftover);
	return (line);
}
