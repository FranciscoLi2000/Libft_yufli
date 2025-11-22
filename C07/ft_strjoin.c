#include <stdlib.h>

/* 计算字符串长度 */
int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

/* 返回堆上可 free 的空字符串（size == 0 使用） */
char	*ft_strdup_empty(void)
{
	char	*r;

	r = malloc(1);
	if (!r)
		return (NULL);
	r[0] = '\0';
	return (r);
}

/* 把 src 拷贝到 dest[pos...]，返回更新后的 pos */
int	copy_to(char *dest, int pos, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[pos] = src[i];
		pos++;
		i++;
	}
	return (pos);
}

/* 计算需要分配的总长度（含终结符） */
int	total_len(int size, char **strs, char *sep)
{
	int	i;
	int	sum;
	int	sep_len;

	if (size <= 0)
		return (1);
	sep_len = ft_strlen(sep);
	sum = 0;
	i = 0;
	while (i < size)
	{
		sum += ft_strlen(strs[i]);
		i++;
	}
	sum += sep_len * (size - 1);
	sum += 1;
	return (sum);
}

/* 主函数：把 strs 用 sep 连接起来，返回 malloc 出来的字符串 */
char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		len;
	int		i;
	int		pos;

	if (size == 0)
		return (ft_strdup_empty());
	len = total_len(size, strs, sep);
	res = malloc(len);
	if (!res)
		return (NULL);
	pos = 0;
	i = 0;
	while (i < size)
	{
		pos = copy_to(res, pos, strs[i]);
		if (i < size - 1)
			pos = copy_to(res, pos, sep);
		i++;
	}
	res[pos] = '\0';
	return (res);
}
