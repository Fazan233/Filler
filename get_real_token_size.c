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
	while (--p.y >= 0)
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

	flr->min_t.x = get_min_x(flr);
	flr->min_t.y = get_min_y(flr);
	flr->max_t.x = get_max_x(flr);
	flr->max_t.y = get_max_y(flr);
	real_size.x = flr->max_t.x - flr->min_t.x;
	real_size.y = flr->max_t.y - flr->min_t.y;
	return (real_size);
}