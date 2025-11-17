/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 18:04:57 by yufli             #+#    #+#             */
/*   Updated: 2025/11/17 18:10:24 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	last;
	int	i;

	if (argc < 2)
		return (0);
	last = argc - 1;
	while (last > 0)
	{
		i = 0;
		while (argv[last][i])
		{
			write(1, &argv[last][i], 1);
			i++;
		}
		write(1, "\n", 1);
		--last;
	}
	return (0);
}
