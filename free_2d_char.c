#include "filler.h"

void	free_2d_char(char ***str, int n)
{
	int i;

	i = -1;
	while (++i < n)
		free((*str)[i]);
	free(*str);
}

void	free_2d_int(int ***mas, int n)
{
	int i;

	i = -1;
	while (++i < n)
		free((*mas)[i]);
	free(*mas);
}