#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

char	**ft_split(char const *s, char c);

int count_substrings(char const *s, char c)
{
    int i;
    int count;  // This will store our total word count
    int in_word;  // Flag to track if we're currently in a word

    i = 0;
    count = 0;
    in_word = 0;  // Start assuming we're not in a word
    if (s == NULL)
        return (0);
    while (s[i] != '\0')
    {
        if (s[i] != c)  // If we find a non-delimiter character
        {
            if (in_word == 0)   // If we weren't in a word before, this is the start of a new word
            {
                count++;  // Increment our word count
                in_word = 1;  // Mark that we're now in a word
            }   // If we were already in a word, we just continue
        }
        else  // If we find a delimiter
            in_word = 0;  // Mark that we're no longer in a word
        i++;
    }
    return (count);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char **ft_split(char const *s, char c)
{
    char **result;  // 存储最终的字符串数组
    int i;          // 主字符串的索引
    int j;          // 结果数组的索引
    int word_start; // 每个单词的起始位置

    result = malloc((count_substrings(s, c) + 1) * sizeof(char *)); // +1 是为了存储最后的 NULL
    if (!s || !result)
        return NULL;
    i = 0;
    j = 0;
    while (s[i] != '\0' && s[i] == c)   // 跳过分隔符
    {
        if (s[i] != '\0') // 如果还没到字符串末尾
        {
            word_start = i; // 记录单词起始位置
            while (s[i] && s[i] != c)   // 找到单词结束位置
                i++;
            result[j] = ft_substr(s, word_start, i - word_start);   // 提取子字符串
            if (!result[j]) // 如果分配失败
            {
                while (j > 0)   // 需要释放之前分配的所有内存
                    free(result[--j]);
                free(result);
                return (NULL);
            }
            j++;
        }
        i++;
    }
    result[j] = NULL; // 设置最后的 NULL 指针
    return (result);
}