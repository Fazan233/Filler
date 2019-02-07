#include "filler.h"

static int	cell_manipulation(t_filler *flr, t_point *pos, t_point *tok, int *inter)
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

static int 	can_put_token(t_filler *flr, t_point *pos, int *sum)
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



t_point		put_token(t_filler *flr)
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
	t.y = flr->size_m.y - flr->size_t.y + 1;
	pos.y = t.y;
	while (--pos.y >= 0)
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

void		set_token_param(t_filler *flr)
{
	char	*line;
	char	*tmp;
	int 	i;

	get_next_line(g_fd, &line);
	tmp = line;
	while (!ft_isdigit(*tmp))
		tmp++;
	flr->size_t.y = ft_atoi(tmp);
	while ((*tmp) != ' ')
		tmp++;
	flr->size_t.x = ft_atoi(tmp);
	free(line);
	flr->map_t = (char**)malloc(sizeof(char*) * flr->size_t.y);
	i = -1;
	while (++i < flr->size_t.y)
	{
		get_next_line(g_fd, &line);
		flr->map_t[i] = line;
	}
	flr->real_s_t = get_real_size_token(flr);
}

void		skip_n_lines(int n, int fd)
{
	char	*line;

	while (n-- > 0)
	{
		get_next_line(fd, &line);
		free(line);
	}
}