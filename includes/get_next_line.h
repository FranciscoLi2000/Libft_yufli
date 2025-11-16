/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 21:54:46 by yufli             #+#    #+#             */
/*   Updated: 2025/11/16 10:35:29 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

# define BUFFER_SIZE 42

char	*fill_line_buffer(int fd, char *left);
char	*extract_line(char **left);
char	*get_next_line(int fd);

#endif
