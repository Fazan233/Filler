#include "filler.h"

void	skip_n_lines(int n, int fd)
{
	char	*line;

	while (n-- > 0)
	{
		get_next_line(fd, &line);
		ft_fprintf(g_fd_t, "%s\n", line);
		free(line);
	}
}

void	fill_in_the_map(t_filler *flr)
{
	int		i;
	char 	*line;

	i = -1;
	while (++i < flr->size_m.y)
	{
		get_next_line(g_fd, &line);
		ft_fprintf(g_fd_t, "%s\n", line);
		flr->map[i] = line;
	}
}