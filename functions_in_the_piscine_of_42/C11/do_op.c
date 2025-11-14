/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 21:45:55 by yufli             #+#    #+#             */
/*   Updated: 2025/11/14 21:46:02 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		switch(argv[2][0])
		{
			case '+':
				printf("%d", atoi(av[1]) + atoi(av[3]));
				break ;
			case '-':
				printf("%d", atoi(av[1]) - atoi(av[3]));
				break ;
			case '*':
				printf("%d", atoi(av[1]) * atoi(av[3]));
				break ;
			case '/':
				printf("%d", atoi(av[1]) / atoi(av[3]));
				break ;
			case '%':
				printf("%d", atoi(av[1]) % atoi(av[3]));
				break ;
		}
	}
	printf("\n");
	return (0);
}
