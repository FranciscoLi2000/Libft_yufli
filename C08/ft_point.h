#ifndef MYLIB_H
# define MYLIB_H

/* ==== 必要的系统库 ==== */
/* 不要包含不需要的库！ */
# include <unistd.h>

/* ==== 宏定义 ==== */
/* 根据需要添加 */

/* ==== typedef / struct ==== */
/* 尽量让 struct 名字有前缀，避免冲突 */
typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

/* ==== 函数声明（function prototypes）==== */
/* 注意：函数名、参数、返回类型必须和 .c 文件完全一致 */
void	set_point(t_point *point);

#endif
