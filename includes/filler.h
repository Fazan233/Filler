
#ifndef FILLER_FILLER_H
# define FILLER_FILLER_H
# include "libft.h"

typedef struct		s_point
{
	int				y;
	int				x;
}					t_point;

typedef struct		s_filler
{
	int8_t			fst_launch;
	int				**map_dist;
	char			*map;
	char			**map_t;
	t_point			size_m;
	t_point			size_t;
	t_point			real_s_t;
	t_point			min_t;
	t_point			max_t;
	char			myfigure;
}					t_filler;

int 	g_fd;

void		skip_n_lines(int n, int fd);
void		set_token_param(t_filler *flr);
t_point		put_token(t_filler *flr);
void		free_2d_char(char ***str, int n);
void		free_2d_int(int ***mas, int n);
t_point		get_real_size_token(t_filler *flr);

#endif