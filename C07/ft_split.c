#include <stdlib.h>

/* 判断是否为分隔符 */
static int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

/* 统计 tokens 数（不包括空 token） */
static int	count_tokens(char *s, char *charset)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && is_sep(s[i], charset))
			i++;
		if (!s[i])
			break ;
		count++;
		while (s[i] && !is_sep(s[i], charset))
			i++;
	}
	return (count);
}

/* 分配失败时释放已分配的 tokens 数组 */
static void	free_tokens(char **arr, int filled)
{
	int	t;

	t = 0;
	while (t < filled)
	{
		free(arr[t]);
		t++;
	}
	free(arr);
}

/* 主函数：先 count，再 alloc 指针数组，然后单扫描填充每个 token */
char	**ft_split(char *str, char *charset)
{
	int		tokens;
	char	**res;
	int		i;
	int		k;
	int		start;
	int		len;
	int		j;
	int		in_word;

	tokens = count_tokens(str, charset);
	res = malloc((tokens + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	res[tokens] = NULL;
	i = 0;
	k = 0;
	in_word = 0;
	while (str[i])
	{
		if (!in_word && !is_sep(str[i], charset))
		{
			start = i;
			in_word = 1;
		}
		if (in_word && (is_sep(str[i + 1], charset) || str[i + 1] == '\0'))
		{
			len = i - start + 1;
			res[k] = malloc(len + 1);
			if (!res[k])
			{
				free_tokens(res, k);
				return (NULL);
			}
			j = 0;
			while (j < len)
			{
				res[k][j] = str[start + j];
				j++;
			}
			res[k][len] = '\0';
			k++;
			in_word = 0;
		}
		i++;
	}
	return (res);
}
