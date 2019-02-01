#include "filler.h"

void	free_2d_char(char ***str, int n)
{
	int i;

	i = -1;
	while (++i < n)
		free((*str)[i]);
	free(*str);
}