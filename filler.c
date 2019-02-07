#include <fcntl.h>
#include "filler.h"
# define ABSM(x) ((x) < 0) ? ((x) * -1) : (x)

static void	set_size_of_field(t_filler *filler, char **line)
{
	char	*tmp;
	int 	i;
	int		j;

	tmp = *line;
	while (!ft_isdigit(*tmp))
		tmp++;
	filler->size_m.y = ft_atoi(tmp);
	while ((*tmp) != ' ')
		tmp++;
	filler->size_m.x = ft_atoi(++tmp);
	free(*line);
	filler->map_dist = (int**)malloc(sizeof(int*) * filler->size_m.y);
	i = -1;
	while (++i < filler->size_m.y)
	{
		filler->map_dist[i] = (int*)malloc(sizeof(int) * filler->size_m.x);
		j = -1;
		while (++j < filler->size_m.x)
			filler->map_dist[i][j] = 20000;
	}
}

static void	first_value_of_vm(t_filler *filler, char **line)
{
	filler->myfigure = (*line)[10] == '1' ? 'O' : 'X';
	free(*line);
	get_next_line(STDIN_FILENO, line);
	set_size_of_field(filler, line);
	skip_n_lines(1, g_fd);
	filler->fst_launch = 0;
}

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
					res = (ABSM(n1)) + (ABSM(n2));
					if (res < flr->map_dist[p.y][p.x])
						flr->map_dist[p.y][p.x] = res;
				}
		}
	}
}

static void	write_distances(t_filler *flr, int fd)
{
	t_point		pos;

	pos.y = -1;
	while (++pos.y < flr->size_m.y)
	{
		pos.x = -1;
		get_next_line(STDIN_FILENO, &flr->map);
		while (++pos.x < flr->size_m.x)
		{
			if ((flr->map[pos.x + 4] == 'X' || flr->map[pos.x + 4] == 'O') &&
				flr->map_dist[pos.y][pos.x] > 0)
				finding_dist(flr, &pos);
		}
		ft_fprintf(fd, "%s\n", flr->map + 4);
		free(flr->map);
	}
	ft_fprintf(fd, "\n");
}

int 		main(void)
{
	int 		fd;
	char		*line;
	t_filler	flr;
	t_point		pos;

	fd = open("filler_maps", O_CREAT | O_RDWR | O_TRUNC);
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		flr.fst_launch = *line == '$' ? 1 : 0;
		if (flr.fst_launch)
			first_value_of_vm(&flr, &line);
		else
		{
			free(line);
			skip_n_lines(1, STDIN_FILENO);
		}
		write_distances(&flr, fd);
		set_token_param(&flr);
		pos = put_token(&flr);
		free_2d_char(&flr.map_t, flr.size_t.y);
		ft_printf("%d %d\n", pos.y, pos.x);
	}
	free_2d_int(&flr.map_dist, flr.size_m.y);
	return (0);
}
