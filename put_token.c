#include "filler.h"

int		cell_manipulation(t_filler *flr, t_point *pos, t_point *tok, int *inter)
{
	t_point	p;

	p.x = pos->x + tok->x;
	p.y = pos->y + tok->y;
	if (flr->map_dist[p.y][p.x] < 0)
	{
		if (flr->myfigure == 'O')
				*inter += flr->map_dist[p.y][p.x] == -1 ? 1 : 2;
		else
				*inter += flr->map_dist[p.y][p.x] == -2 ? 1 : 2;
		return (0);
	}
	return (1);
}

int 	can_put_token(t_filler *flr, t_point *pos, int *sum)
{
	int 	intersection;
	t_point	tok;


	*sum = 0;
	intersection = 0;
	tok.y = flr->min_t.y - 1;
	while (++tok.y <= flr->max_t.y)
	{
		tok.x = flr->min_t.x - 1;
		while (++tok.x <= flr->max_t.x)
			if (flr->map_t[tok.y][tok.x] == '*')
			{
				if (cell_manipulation(flr, pos, &tok, &intersection))
						*sum += flr->map_dist[pos->y + tok.y][pos->x + tok.x];
				else if (intersection > 1)
					return (0);
			}
	}
	return (intersection);
}

t_point	put_token(t_filler *flr)
{
	t_point	pos;
	t_point	t;
	t_point	finish;
	int 	fin_sum;
	int 	sum;

	finish.x = 0;
	finish.y = 0;
	fin_sum = 1000000000;
	t.x = flr->size_m.x - flr->size_t.x;
	t.y = flr->size_m.y - flr->size_t.y;
	pos.y = -1;
	while (++pos.y <= t.y)
	{
		pos.x = -1;
		while (++pos.x <= t.x)
			if (can_put_token(flr, &pos, &sum))
				if (sum < fin_sum)
				{
					finish = pos;
					fin_sum = sum;
				}
	}
	return (finish);
}