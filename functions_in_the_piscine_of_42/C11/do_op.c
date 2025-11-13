#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		switch(argv[2][0])
		{
			case '+':
				printf("%d", atoi(av[1]) + atoi(av[3]));
				break ;
			case '-':
				printf("%d", atoi(av[1]) - atoi(av[3]));
				break ;
			case '*':
				printf("%d", atoi(av[1]) * atoi(av[3]));
				break ;
			case '/':
				printf("%d", atoi(av[1]) / atoi(av[3]));
				break ;
			case '%':
				printf("%d", atoi(av[1]) % atoi(av[3]));
				break ;
		}
	}
	printf("\n");
	return (0);
}
