#include "filler.h"

void	set_token_param(t_filler *flr)
{
	char	*line;
	char	*tmp;
	int 	i;

	get_next_line(STDOUT_FILENO, &line);
	tmp = line;
	while (!ft_isdigit(*tmp))
		tmp++;
	flr->size_t.y = (t_byte)ft_atoi(tmp);
	while (!ft_isdigit(*tmp))
		tmp++;
	flr->size_t.x = (t_byte)ft_atoi(tmp);
	free(line);
	flr->map_t = (char**)malloc(sizeof(char*) * flr->size_t.y);
	i = -1;
	while (++i < flr->size_t.y)
	{
		get_next_line(STDOUT_FILENO, &line);
		flr->map_t[i] = line;
	}
	get_next_line(STDOUT_FILENO, &line);
}

