#include "filler.h"

static void	set_size_of_field(t_filler *filler, char **line)
{
	char	*tmp;
	int 	i;

	tmp = *line;
	while (!ft_isdigit(*tmp))
		tmp++;
	filler->size_m.y = (t_byte)ft_atoi(tmp);
	while (!ft_isdigit(*tmp))
		tmp++;
	filler->size_m.x = (t_byte)ft_atoi(tmp);
	free(*line);
	filler->map = (char**)malloc(sizeof(char*) * filler->size_m.y);
	filler->map_dist = (int**)malloc(sizeof(int*) * filler->size_m.y);
	i = -1;
	while (++i < filler->size_m.y)
		filler->map_dist[i] = (int*)ft_memalloc_chr((filler->size_m.x * 2) + 1, 101);
	free(*line);
}

void	first_value_of_vm(t_filler *filler, char **line)
{
	get_next_line(STDOUT_FILENO, line);
	if (*line[10] == '1')
		filler->myfigure = 'o';
	else
		filler->myfigure = 'x';
	free(*line);
	get_next_line(STDOUT_FILENO, line);
	set_size_of_field(filler, line);
	filler->fst_launch = 0;
	skip_n_lines(1, STDOUT_FILENO);
} 
