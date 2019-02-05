
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
	int 			**map_d_x;
	int 			**map_d_y;
	char			*map;
	char			**map_t;
	t_point			size_m;
	t_point			maxx;
	t_point			maxy;
	t_point			size_t;
	t_point			real_s_t;
	t_point			min_t;
	t_point			max_t;
	char			myfigure;
	int 			count;
	int 			touch;
	int 			alg_mode;
//	t_point			sum;
}					t_filler;

int 	g_fd;

void	first_value_of_vm(t_filler *filler, char **line);
//void	filler(void);
void	skip_n_lines(int n, int fd);
void	set_token_param(t_filler *flr);
void	write_distances(t_filler *flr);
t_point		put_token(t_filler *flr);
void	free_2d_char(char ***str, int n);
t_point		get_real_size_token(t_filler *flr);
int 	is_touch(t_filler *flr);
void	get_temp_d_matix(t_filler *flr);

#endif
