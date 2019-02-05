#include "filler.h"

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
	filler->map_d_x = (int**)malloc(sizeof(int*) * filler->size_m.y);
	filler->map_d_y = (int**)malloc(sizeof(int*) * filler->size_m.y);
	i = -1;
	while (++i < filler->size_m.y)
	{
		filler->map_d_x[i] = (int*)malloc(sizeof(int) * filler->size_m.x);
		filler->map_d_y[i] = (int*)malloc(sizeof(int) * filler->size_m.x);
		filler->map_dist[i] = (int*)malloc(sizeof(int) * filler->size_m.x);
		j = -1;
		while (++j < filler->size_m.x)
			filler->map_dist[i][j] = 20000;
	}
}

void	first_value_of_vm(t_filler *filler, char **line)
{
	filler->myfigure = (*line)[10] == '1' ? 'O' : 'X';
	free(*line);
	get_next_line(g_fd, line);
	set_size_of_field(filler, line);
	skip_n_lines(1, g_fd);
	filler->fst_launch = 0;
	filler->count = 0;

} 
