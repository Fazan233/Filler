#include "filler.h"

static int	get_min_x(t_filler *flr)
{
	t_point	p;

	p.x = -1;
	while (++p.x < flr->size_t.x)
	{
		p.y = -1;
		while (++p.y < flr->size_t.y)
		{
			if (flr->map_t[p.y][p.x] == '*')
				return (p.x);
		}
	}
	return (0);
}

static int	get_max_x(t_filler *flr)
{
	t_point	p;

	p.x = flr->size_t.x;
	while (--p.x >= 0)
	{
		p.y = -1;
		while (++p.y < flr->size_t.y)
		{
			if (flr->map_t[p.y][p.x] == '*')
				return (p.x);
		}
	}
	return (0);
}

static int	get_min_y(t_filler *flr)
{
	t_point	p;

	p.y = -1;
	while (++p.y < flr->size_t.y)
	{
		p.x = -1;
		while (++p.x < flr->size_t.x)
		{
			if (flr->map_t[p.y][p.x] == '*')
				return (p.y);
		}
	}
	return (0);
}

static int	get_max_y(t_filler *flr)
{
	t_point	p;

	p.y = flr->size_t.y;
	while (--p.y <= 0)
	{
		p.x = -1;
		while (++p.x < flr->size_t.x)
		{
			if (flr->map_t[p.y][p.x] == '*')
				return (p.y);
		}
	}
	return (0);
}

t_point		get_real_size_token(t_filler *flr)
{
	t_point	real_size;

	real_size.x = get_max_x(flr) - get_min_x(flr);
	real_size.y = get_max_y(flr) - get_min_y(flr);
	return (real_size);
}