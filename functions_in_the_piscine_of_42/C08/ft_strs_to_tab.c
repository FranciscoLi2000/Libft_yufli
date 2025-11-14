/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 21:37:28 by yufli             #+#    #+#             */
/*   Updated: 2025/11/14 21:37:54 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_stock_str.h"

int	ft_lenght(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*arr;

	arr = (char *) malloc(sizeof(char) * (ft_lenght(str) + 1));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		arr[i] = str[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

void	print_array(t_stock_str *str)
{
	int	i;

	i = 0;
	while (str[i].str != NULL)
	{
		printf("Indice: %d - Size: %d - String: %s - Copy: %s\n",
				i, str[i].size, str[i].str, str[i].copy);
		i++;	
	}
	free(str);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*arr;
	int					i;

	arr = (t_stock_str *) malloc(sizeof(t_stock_str) * (ac + 1));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		if (av[i] == NULL)
			return (NULL);
		arr[i].size = ft_lenght(av[i]);
		arr[i].str = ft_strdup(av[i]);
		arr[i].copy = ft_strdup(av[i]);
		if (arr[i].str == NULL || arr[i].copy == NULL)
			return (NULL);
		i++;
	}
	arr[i].str = NULL;
	return (arr);
}
