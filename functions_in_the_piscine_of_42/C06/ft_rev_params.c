/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 21:32:18 by yufli             #+#    #+#             */
/*   Updated: 2025/11/14 21:32:20 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	last;

	i = 1;
	last = argc - 1;
	while (i < argc)
	{
		j = 0;
		while (argv[last][j])
		{
			ft_putchar(argv[last][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
		last--;
	}
	return (0);
}
