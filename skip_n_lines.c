#include "filler.h"

void	skip_n_lines(int n, int fd)
{
	char	*line;

	while (n-- > 0)
	{
		get_next_line(fd, &line);
		free(line);
	}
}