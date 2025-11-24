#ifndef FT_H
# define FT_H

/* ==== 必要的系统库 ==== */
/* 不要包含不需要的库！ */
# include <stdlib.h>
# include <unistd.h>

/* ==== 宏定义 ==== */
/* 根据需要添加 */

/* ==== typedef / struct ==== */
/* 尽量让 struct 名字有前缀，避免冲突 */

/* ==== 函数声明（function prototypes）==== */
/* 注意：函数名、参数、返回类型必须和 .c 文件完全一致 */
void	ft_putchar(char c);
int		ft_swap(int *a, int *b);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);

#endif
