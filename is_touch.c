#include "filler.h"

int 	is_touch(t_filler *flr)
{
	t_point p;
	t_point	fig;

	p.y = flr->size_m.y - 1;
	while (--p.y >= 0)
	{
		p.x = flr->size_m.x - 1;
		while (--p.x >= 0)
		{
			fig.x = flr->map_dist[p.y][p.x] == -1 ||
					flr->map_dist[p.y + 1][p.x] == -1 ||
					flr->map_dist[p.y][p.x + 1] == -1 ||
					flr->map_dist[p.y + 1][p.x + 1] == -1;
			fig.y = flr->map_dist[p.y][p.x] == -2 ||
					flr->map_dist[p.y + 1][p.x] == -2 ||
					flr->map_dist[p.y][p.x + 1] == -2 ||
					flr->map_dist[p.y + 1][p.x + 1] == -2;
			if (fig.x == 1 && fig.y == 1)
				return (1);
		}
	}
	return (0);
}