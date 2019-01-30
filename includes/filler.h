
#ifndef FILLER_FILLER_H
# define FILLER_FILLER_H
# include "libft.h"

typedef struct		s_point
{
	int8_t			y;
	int8_t			x;
}					t_point;

typedef struct		s_filler
{
	int8_t			fst_launch;
	int8_t			**map_dist;
	char			**map;
	char			**map_t;
	t_point			size_m;
	t_point			size_t;
	char			myfigure;
}					t_filler;

void	first_value_of_vm(t_filler *filler, char **line);
void	filler(void);
void	skip_n_lines(int n, int fd);
void	fill_in_the_map(t_filler *flr);
void	set_token_param(t_filler *flr);


#endif
