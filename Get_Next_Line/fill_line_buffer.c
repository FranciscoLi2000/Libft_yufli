/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_line_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 21:58:34 by yufli             #+#    #+#             */
/*   Updated: 2025/11/16 10:58:40 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_and_null(char *p)
{
	if (p)
		free(p);
	return (NULL);
}

char	*fill_line_buffer(int fd, char *left)
{
	char	*buf;
	ssize_t	rbytes;
	char	*tmp;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free_and_null(left));
	rbytes = 1;
	while (rbytes > 0 && !(left && ft_strchr(left, '\n')))
	{
		rbytes = read(fd, buf, BUFFER_SIZE);
		if (rbytes <= 0)
			break ;
		buf[rbytes] = '\0';
		if (!left)
			left = ft_strdup(buf);
		tmp = ft_strjoin(left, buf);
		free(left);
		left = tmp;
	}
	free(buf);
	if (rbytes < 0)
		return (free_and_null(left));
	return (left);
}
