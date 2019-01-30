#include "filler.h"

void	filler(void)
{
	char		*line;
	t_filler	flr;

	if (flr.fst_launch)
		first_value_of_vm(&flr, &line);
	else
		skip_n_lines(2, STDOUT_FILENO);
	fill_in_the_map(&flr);
	set_token_param(&flr);

}