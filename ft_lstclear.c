#include <stdio.h>
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (*lst == NULL || lst == NULL)
		return ;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}
