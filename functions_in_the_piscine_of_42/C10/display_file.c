/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 21:41:57 by yufli             #+#    #+#             */
/*   Updated: 2025/11/14 21:45:25 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	display_file(char *filename)
{
	int		file;
	int		size;
	char	buf[4097];

	file = open(filename, O_RDONLY);
	if (file != -1)
	{
		while ((size = read(file, buf, 4096)) != 0)
			ft_putstr_fd(buf, 1);
	}
	else
		ft_putstr_fd("Cannot read file.\n", 2);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putstr_fd("File name missing.\n", 2);
		return (1);
	}
	else if (argc != 2)
	{
		ft_putstr_fd("Too many arguments.\n", 2);
		return (1);
	}
	else
		display_file(argv[1]);
	return (0);
}
