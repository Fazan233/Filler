#include "filler.h"



void	write_distances(t_filler *flr)
{
	t_point	coord;

	coord.y = -1;
	while (++coord.y < flr->size_t.y)
	{
		coord.x = -1;
		while (++coord.x < flr->size_t.x)
		{
			if (flr->map[coord.y][coord.x] == 'o' ||
				flr->map[coord.y][coord.x] == 'O')
				flr->map_dist[coord.y][coord.x] = -1;
			else if (flr->map[coord.y][coord.x] == 'x' ||
				flr->map[coord.y][coord.x] == 'X')
				flr->map_dist[coord.y][coord.x] = -2;
			else

		}
	}
}