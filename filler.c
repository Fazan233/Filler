#include <fcntl.h>
#include "filler.h"
# define ABSM(x) ((x) < 0) ? ((x) * -1) : (x)

static void	finding_dist(t_filler *flr, t_point *pos)
{
	int n1;
	int n2;
	int res;
	t_point	p;

	flr->map_dist[pos->y][pos->x] = flr->map[pos->x + 4] == 'O' ? -1 : -2;
	if (flr->map[pos->x + 4] != flr->myfigure)
	{
		p.y = -1;
		while (++p.y < flr->size_m.y)
		{
			p.x = -1;
			while (++p.x < flr->size_m.x)
				if (flr->map_dist[p.y][p.x] > -1)
				{
					n1 = pos->x - p.x;
					n2 = pos->y - p.y;
					res = ft_pow(ABSM(n1), 2) + ft_pow(ABSM(n2), 2);
					if (res < flr->map_dist[p.y][p.x])
						flr->map_dist[p.y][p.x] = res;
				}
		}
	}
}

void		write_distances(t_filler *flr)
{
	t_point		pos;

	pos.y = -1;
	while (++pos.y < flr->size_m.y)
	{
		pos.x = -1;
		get_next_line(g_fd, &flr->map);
		while (++pos.x < flr->size_m.x)
			if ((flr->map[pos.x + 4] == 'X' ||  flr->map[pos.x + 4] == 'O')
				&& flr->map_dist[pos.y][pos.x] > 0)
				finding_dist(flr, &pos);
		free(flr->map);
	}
	get_temp_d_matix(flr);
}

int 	main(void)
{
	char		*line;
	t_filler	flr;
	t_point		pos;

	g_fd = 0;
//	g_fd = open("test2", O_RDONLY);

	while (get_next_line(g_fd, &line) > 0)
	{
		flr.fst_launch = *line == '$' ? 1 : 0;
		if (flr.fst_launch)
			first_value_of_vm(&flr, &line);
		else
		{
			free(line);
			skip_n_lines(1, g_fd);
		}

		write_distances(&flr);
		flr.touch = is_touch(&flr);
//		int x, y;
//		y = -1;
//		while (++y < flr.size_m.y)
//		{
//			x = -1;
//			while (++x < flr.size_m.x)
//				ft_printf("%5i ", flr.map_dist[y][x]);
//			ft_printf("\n");
//		}
//
//		y = -1;
//		ft_printf("YYYYYY\n");
//		while (++y < flr.size_m.y)
//		{
//			x = -1;
//			while (++x < flr.size_m.x)
//				ft_printf("%5i ", flr.map_d_y[y][x]);
//			ft_printf("\n");
//		}
//		y = -1;
//		ft_printf("XXXXXX\n");
//		while (++y < flr.size_m.y)
//		{
//			x = -1;
//			while (++x < flr.size_m.x)
//				ft_printf("%5i ", flr.map_d_x[y][x]);
//			ft_printf("\n");
//		}


		set_token_param(&flr);
		pos = put_token(&flr);
		free_2d_char(&flr.map_t, flr.size_t.y);
		ft_printf("%d %d\n", pos.y, pos.x);

		flr.count++;
	}
	return (0);
}
