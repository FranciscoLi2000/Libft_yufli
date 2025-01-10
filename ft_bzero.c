#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

void	ft_bzero(void *s, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

int main(void)
{
    // Test case 1: zeroing a string
    char str1[] = "Hello, World!";
    printf("Before ft_bzero: %s\n", str1);
    ft_bzero(str1, 5);  // Zero first 5 bytes
    printf("After ft_bzero(5 bytes): ");
    for (int i = 0; i < 13; i++)
        printf("%c", str1[i] ? str1[i] : '_');
    printf("\n\n");

    // Test case 2: zeroing an integer array
    int numbers[] = {1, 2, 3, 4, 5};
    printf("Before ft_bzero: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", numbers[i]);
    printf("\n");
    
    ft_bzero(numbers, sizeof(int) * 3);  // Zero first 3 integers
    printf("After ft_bzero(3 integers): ");
    for (int i = 0; i < 5; i++)
        printf("%d ", numbers[i]);
    printf("\n");

    return 0;
}
