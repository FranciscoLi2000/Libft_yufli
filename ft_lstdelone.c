#include <stdio.h>
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL)
		return ;
	del(lst->content);
	free(lst);
}
