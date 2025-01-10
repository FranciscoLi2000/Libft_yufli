#include <stdio.h>
#include "libft.h"
#include <unistd.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
