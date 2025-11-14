/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 21:13:13 by yufli             #+#    #+#             */
/*   Updated: 2025/11/14 21:17:34 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	index;
	int	howlong;
	int	startval;
	int	endval;

	index = 0;
	howlong = size / 2;
	while (howlong > 0)
	{
		size--;
		startval = tab[size];
		endval = tab[index];
		tab[size] = endval;
		tab[index] = startval;
		index++;
		howlong--;
	}
}
