
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
	char			*map;
	char			**map_t;
	t_point			size_m;
	t_point			size_t;
	char			myfigure;

	t_enmlst		*list; // have to initialize by NULL DONE
}					t_filler;

int 	g_fd;

void	first_value_of_vm(t_filler *filler, char **line);
//void	filler(void);
void	skip_n_lines(int n, int fd);
//void	fill_in_the_map(t_filler *flr);
void	set_token_param(t_filler *flr);
void	write_distances(t_filler *flr);
//t_enmlst	*add_points_to_list(t_filler *flr);
//void		delele_enemlst(t_enmlst **list);
t_point		put_token(t_filler *flr);
void	free_2d_char(char ***str, int n);


#endif
