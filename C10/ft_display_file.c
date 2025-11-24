/* ft_display_file.c
 * 编译: cc -Wall -Wextra -Werror -o ft_display_file ft_display_file.c
 */
#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		fd;
	ssize_t	read_bytes;
	ssize_t	write_bytes;
	ssize_t	written;
	char	buf[4096];

	if (argc == 1)
	{
		write(2, "File name missing.\n", 19);
		return (1);
	}
	if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(2, "Cannot read file.\n", 18);
		return (1);
	}
	while ((read_bytes = read(fd, buf, sizeof(buf))) > 0)
	{
		write_bytes = 0;
		while (write_bytes < read_bytes)
		{
			written = write(1, buf + write_bytes, read_bytes - write_bytes);
			if (written <= 0)
			{
				close(fd);
				return (1);
			}
			write_bytes += written;
		}
	}
	close(fd);
	return (0);
}
