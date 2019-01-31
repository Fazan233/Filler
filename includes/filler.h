
#ifndef FILLER_FILLER_H
# define FILLER_FILLER_H
# include "libft.h"

typedef struct		s_point
{
	int				y;
	int				x;
}					t_point;

typedef struct		s_enmlst
{
	t_point			pos;
	struct s_enmlst	*next;
}					t_enmlst;

typedef struct		s_filler
{
	int8_t			fst_launch;
	int				**map_dist;
	char			**map;
	char			**map_t;
	t_point			size_m;
	t_point			size_t;
	char			myfigure;

	t_point	p;
	int8_t 	flag;
	int 	min_x;
	int 	max_x;
	int 	min_y;
	int 	max_y;

	int16_t 		*mas_pow;
	int8_t 			mas_len;

	t_enmlst		*list;
}					t_filler;

void	first_value_of_vm(t_filler *filler, char **line);
void	filler(void);
void	skip_n_lines(int n, int fd);
void	fill_in_the_map(t_filler *flr);
void	set_token_param(t_filler *flr);
void	write_distances(t_filler *flr);


#endif
