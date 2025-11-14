/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 21:13:23 by yufli             #+#    #+#             */
/*   Updated: 2025/11/14 21:17:41 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	hold[2];
	int	index[3];

	index[2] = 1;
	while (index[2] < size)
	{
		index[0] = 0;
		hold[0] = -2147483648;
		while (index[0] <= size - index[2])
		{
			if (hold[0] < tab[index[0]])
			{
				hold[0] = tab[index[0]];
				index[1] = index[0];
				hold[1] = tab[size - index[2]];
			}
			index[0]++;
			if (index[0] > size - index[2])
			{
				tab[size - index[2]] = hold[0];
				tab[index[1]] = hold[1];
			}
		}
		index[2]++;
	}
}
