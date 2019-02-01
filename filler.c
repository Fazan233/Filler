#include <fcntl.h>
#include "filler.h"

void	filler(void)
{
	char		*line;
	t_filler	flr;
	t_point		pos;

//	g_fd = open("test", O_RDWR);
//
//
//	ft_printf("%i\n", g_fd);

	g_fd = 0;

	g_fd_t = open("fd_t", O_RDWR);
//	ft_fprintf(g_fd_t, "%i\n", g_fd_t);


	get_next_line(g_fd, &line);
	flr.fst_launch = *line == '$' ? 1 : 0;
	ft_fprintf(g_fd_t, "%s\n", line);


	if (flr.fst_launch)
		first_value_of_vm(&flr, &line);
	else
	{
		free(line);
		skip_n_lines(1, g_fd);
	}
	fill_in_the_map(&flr);
//	ft_fprintf(g_fd_t, "HELLO\n");
	set_token_param(&flr);
//	ft_fprintf(g_fd_t, "HELLO\n");
	write_distances(&flr);
//	ft_fprintf(g_fd_t, "HELLO\n");
	pos = put_token(&flr);
	ft_fprintf(g_fd_t, "HELLO\n");
//	if (pos.x != -1)
	ft_fprintf(g_fd_t, "%i %i\n", pos.x, pos.y);
	ft_fprintf(1, "%i %i\n", pos.x, pos.y);
	ft_fprintf(g_fd_t, "HELLO\n");
//	t_point p;
//	p.y = -1;
//	while (++p.y < flr.size_m.y)
//	{
//		p.x = -1;
//		while (++p.x < flr.size_m.x)
//			ft_printf("%5i ", flr.map_dist[p.y][p.x]);
//		ft_printf("\n");
//	}

}

int 	main(void)
{
	filler();
	return (0);
}