#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

/* ==== 必要的系统库 ==== */
/* 不要包含不需要的库！ */
# include <unistd.h>

/* ==== 宏定义 ==== */
/* 根据需要添加 */
# define SUCCESS 0
# define ODD_MSG "I have an odd number of arguments.\n"
# define EVEN_MSG "I have an even number of arguments.\n"
# define TRUE 1
# define FALSE 0
# define EVEN(nb) ((nb % 2 == 0) ? 1 : 0)

/* ==== typedef / struct ==== */
/* 尽量让 struct 名字有前缀，避免冲突 */

/* ==== 函数声明（function prototypes）==== */
/* 注意：函数名、参数、返回类型必须和 .c 文件完全一致 */
void	ft_putstr(char *str);
int     ft_is_even(int nbr);

#endif
