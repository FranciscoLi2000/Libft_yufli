/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:09:32 by yufli             #+#    #+#             */
/*   Updated: 2025/11/18 14:17:38 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ptr: 旧指针
 * size: 新的字节数
 * void	*ft_realloc(void *ptr, size_t size);
 */
#include <stdlib.h>
#include <limits.h> /* for SIZE_MAX */

void	*ft_memcpy(void *dst, const void *src, size_t n);

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*newp;

	/* If new_size is 0, free ptr and return NULL (common safe behavior) */
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	/* If ptr is NULL, behave like malloc(new_size) */
	if (ptr == NULL)
		return (malloc(new_size));
	/* If sizes equal, nothing to do */
	if (new_size == old_size)
		return (ptr);
	/* Optional overflow check for extreme cases (new_size should be <= SIZE_MAX) */
	/* (Usually not necessary, but be defensive) */
	if (new_size > SIZE_MAX - 0) /* trivial, kept for pattern */
		return (NULL);
	newp = malloc(new_size);
	if (newp == NULL)
		return (NULL); /* malloc failed, keep old ptr intact */
	/* copy the minimal bytes between old and new size */
	if (old_size > 0)
	{
		if (old_size < new_size)
			copy = old_size;
		else
			copy = new_size;
		ft_memcpy(newp, (const void *)ptr, copy);
	}
	free(ptr);
	return (newp);
}
