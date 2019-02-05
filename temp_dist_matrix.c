#include "filler.h"
# define ABSM(x) ((x) < 0) ? ((x) * -1) : (x)
# define NUM 30

t_point	get_maxx(t_filler *flr)
{
	t_point	p;
	int 	fig;

	fig = flr->myfigure == 'O' ? -1 : -2;
	p.x = flr->size_m.x;
	while (--p.x >= 0)
	{
		p.y = -1;
		while (++p.y < flr->size_m.y)
			if (flr->map_dist[p.y][p.x] < 0 && flr->map_dist[p.y][p.x] != fig)
				return (p);
	}
	return (p);
}

t_point	get_maxy(t_filler *flr)
{
	t_point	p;
	int 	fig;

	fig = flr->myfigure == 'O' ? -1 : -2;
	p.y = flr->size_m.y;
	while (--p.y >= 0)
	{
		p.x = -1;
		while (++p.x < flr->size_m.x)
			if (flr->map_dist[p.y][p.x] < 0 && flr->map_dist[p.y][p.x] != fig)
				return (p);
	}
	return (p);
}

void	get_temp_d_matix(t_filler *flr)
{
	t_point	p;
	t_point	tmp;

	flr->maxx = get_maxx(flr);
	flr->maxy = get_maxy(flr);
	p.x = -1;
	while (++p.x < flr->size_m.x)
	{
		p.y = -1;
		while (++p.y < flr->size_m.y)
		{
			tmp.x = p.x - flr->maxx.x - NUM;
			tmp.y = p.y - flr->maxx.y + NUM + 1;
			flr->map_d_x[p.y][p.x] = (ABSM(tmp.x)) + (ABSM(tmp.y));
			tmp.x = p.x - flr->maxy.x + NUM + 1;
			tmp.y = p.y - flr->maxy.y - NUM;
			flr->map_d_y[p.y][p.x] = ft_pow(ABSM(tmp.x), 2) + ft_pow(ABSM(tmp.y), 2);
		}
	}
}

