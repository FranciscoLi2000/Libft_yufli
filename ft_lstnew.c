#include <stdio.h>
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
	{
		write(2, "Memory allocation failed\n", 25);
		return (NULL);
	}
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
