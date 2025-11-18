/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:19:28 by yufli             #+#    #+#             */
/*   Updated: 2025/11/18 14:30:26 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep);

/* append n bytes from src into buffer (no '\0' appended here) */
int	buffer_ensure_and_append(char **pbuf, size_t *plen, size_t *pcap,
		const char *src, size_t n)
{
	size_t	needed = *plen + n + 1; /* +1 for final '\0' maybe */
	size_t	new_cap;
	void	*tmp;

	needed = *plen + n + 1;
	if (needed > *pcap)
	{
		/* 向上按 2 倍增长直到能容纳 needed（防止多次 realloc) */
		if (*pcap == 0)
			new_cap = 1;
		else
			new_cap = *pcap;
		while (new_cap < needed)
		{
			if (new_cap > SIZE_MAX / 2) /* 溢出保护 */
				return (-1);
			new_cap *= 2;
		}
		tmp = ft_realloc(*pbuf, *pcap, new_cap); /* 注意 old_size = *pcap */
		if (tmp == NULL)
			return (-1);
		*pbuf = tmp;
		*pcap = new_cap;
	}
	/* 现在可以安全追加 */
	ft_memcpy(*pbuf + *plen, (const void *)src, n);
	*plen += n;
	(*pbuf)[*plen] = '\0'; /* 保证随时是 C 字符串 */
	return (0);
}

char	*ft_strjoin(int size, char **strs)
{
	char	*buf;
	int		len;
	int		cap;
	int		i;
	int		add;

	buf = NULL;
	len = 0;
	cap = 0;
	i = 0;
	while (i < size)
	{
		add = ft_strlen(strs[i]);
		if (buffer_ensure_and_append(&buf, &len, &cap, parts[i], add) < 0)
		{
			free(buf);
			return (NULL);
		}
		++i;
	}
	return (buf); /* buf is malloc'd and '\0' terminated */
}
