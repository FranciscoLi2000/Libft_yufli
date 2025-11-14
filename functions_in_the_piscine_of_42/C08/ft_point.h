/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 21:37:11 by yufli             #+#    #+#             */
/*   Updated: 2025/11/14 21:37:15 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_POINT_H
# define FT_POINT_H

# include <unistd.h>

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

void	set_point(t_point *point);

#endif
