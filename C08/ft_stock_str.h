#ifndef MYLIB_H
# define MYLIB_H

/* ==== 必要的系统库 ==== */
/* 不要包含不需要的库！ */
# include <unistd.h>

/* ==== 宏定义 ==== */
/* 根据需要添加 */

/* ==== typedef / struct ==== */
/* 尽量让 struct 名字有前缀，避免冲突 */
typedef struct s_stock_str
{
	int		size;
	char	*str;
	char	*copy;
}	t_stock_str;

/* ==== 函数声明（function prototypes）==== */
/* 注意：函数名、参数、返回类型必须和 .c 文件完全一致 */
struct s_stock_str	*ft_strs_to_tab(int ac, char **av);
void				ft_show_tab(struct s_stock_str *par);
int					ft_strlen(char *str);
char				*ft_strdup(char *src);
void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putnbr(int nb);

#endif
