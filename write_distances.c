#include "filler.h"
# define ABSM(x) ((x) < 0) ? ((x) * -1) : (x)

//int		found_distance(t_filler *flr, t_point *pos, int8_t n)
//{
//	t_point	p;
//	int8_t 	flag;
//	int 	min_x;
//	int 	max_x
//
//	p.x = pos->x - n - (int16_t)1;
//	while (++p.x <= pos->x + n)
//		if (p.x >= 0 && p.x < flr->size_m.x)
//		{
//			p.y = pos->y - n - (int16_t)1;
//			while (++p.y <= pos->y + n)
//				if (p.y >= 0 && p.y < flr->size_m.y)
//				{
//					if (flr->myfigure == 'x')
//						flag = flr->map[p.y][p.x] == 'o' ||
//								flr->map[p.y][p.x] == 'O';
//					else
//						flag = flr->map[p.y][p.x] == 'x' ||
//								flr->map[p.y][p.x] == 'X';
//					if (p.x != pos->x - n && p.x != pos->x + n && p.y != pos->y + n)
//						p.y = pos->y + n - (int16_t)1;
//					if (flag)
//						return (1);
//				}
//		}
//	return (0);
//}

//Better then above function
//int		found_distance(t_filler *flr, t_point *pos, int8_t n)
//{
//
//
//	flr->min_x = pos->x - n;
//	flr->max_x = pos->x + n;
//
//	flr->min_y = pos->y - n;
//	flr->max_y = pos->y + n;
//
//	flr->p.x = flr->min_x - 1;
//	while (++flr->p.x <= flr->max_x)
//		if (flr->p.x >= 0 && flr->p.x < flr->size_m.x)
//		{
//			flr->p.y = flr->min_y - 1;
//			while (++flr->p.y <= flr->max_y)
//				if (flr->p.y >= 0 && flr->p.y < flr->size_m.y)
//				{
//					if (flr->myfigure == 'x')
//						flr->flag = flr->map[flr->p.y][flr->p.x] == 'o' ||
//							   flr->map[flr->p.y][flr->p.x] == 'O';
//					else
//						flr->flag = flr->map[flr->p.y][flr->p.x] == 'x' ||
//							   flr->map[flr->p.y][flr->p.x] == 'X';
//					if (flr->p.x != flr->min_x && flr->p.x != flr->max_x && flr->p.y != flr->max_y)
//						flr->p.y = flr->max_y - 1;
//					if (flr->flag)
//						return (1);
//				}
//		}
//		else if (flr->p.x < flr->size_m.x)
//			flr->p.x = -1;
//	return (0);
//}

//void	finding_dist(t_filler *flr, t_point *pos)
//{
//	int8_t	n;
//
//	n = 1;
//	while (!found_distance(flr, pos, n))
//		n++;
//	flr->map_dist[pos->y][pos->x] = n;
//}
//
//void	write_distances(t_filler *flr)
//{
//	t_point	p;
//
//	p.y = -1;
//	while (++p.y < flr->size_m.y)
//	{
//		p.x = -1;
//		while (++p.x < flr->size_m.x)
//		{
//			if (flr->map[p.y][p.x] == 'o' ||
//				flr->map[p.y][p.x] == 'O')
//				flr->map_dist[p.y][p.x] = -1;
//			else if (flr->map[p.y][p.x] == 'x' ||
//				flr->map[p.y][p.x] == 'X')
//				flr->map_dist[p.y][p.x] = -2;
//			else
//				finding_dist(flr, &p);
////			ft_printf("%4i ", flr->map_dist[p.y][p.x]);
//		}
////		ft_printf("\n");
//	}
//}

void		adding_to_lst(t_enmlst **lst, t_point *pos)
{
	t_enmlst	*new_lst;
	t_enmlst	*tmp;

	new_lst = (t_enmlst*)malloc(sizeof(t_enmlst));
	new_lst->next = NULL;
	new_lst->pos = *pos;
	tmp = *lst;
	if (!tmp)
		*lst = new_lst;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_lst;
	}
}

void		add_lst_condition(t_filler *flr, t_enmlst **lst, t_point *pos)
{
	if (!flr->fst_launch)
	{
		if (flr->myfigure == 'o')
		{
			if (flr->map[pos->y][pos->x] == 'x')
				adding_to_lst(lst, pos);
		}
		else
			if (flr->map[pos->y][pos->x] == 'o')
				adding_to_lst(lst, pos);
	}
	else
	{
		if (flr->myfigure == 'o')
		{
			if (flr->map[pos->y][pos->x] == 'x' ||
				flr->map[pos->y][pos->x] == 'X')
				adding_to_lst(lst, pos);
		}
		else
			if (flr->map[pos->y][pos->x] == 'o' ||
				flr->map[pos->y][pos->x] == 'O')
				adding_to_lst(lst, pos);
	}
}

t_enmlst	*add_points_to_list(t_filler *flr)
{
	t_enmlst	*lst;
	t_point		pos;

	lst = NULL;
	pos.y = -1;
	while (++pos.y < flr->size_m.y)
	{
		pos.x = -1;
		while (++pos.x < flr->size_m.x)
			add_lst_condition(flr, &lst, &pos);
	}
	return (lst);
}

void	finding_dist(t_filler *flr, t_point *pos, t_point *pos2)
{
	int n1;
	int n2;
	int res;

	n1 = pos->x - pos2->x;
	n2 = pos->y - pos2->y;
	res = ft_pow(ABSM(n1), 2) + ft_pow(ABSM(n2), 2);
	if (res < flr->map_dist[pos->y][pos->x])
		flr->map_dist[pos->y][pos->x] = res;
}

void	print_lst(t_enmlst *list)
{
	while (list)
	{
		ft_printf("%i %i\n", list->pos.x, list->pos.y);
		list = list->next;
	}
}

void	first_launch_wrt(t_enmlst *tmp, t_point *pos, t_filler *flr)
{
	while (tmp)
	{
		pos->y = -1;
		while (++pos->y < flr->size_m.y) {
			pos->x = -1;
			while (++pos->x < flr->size_m.x)
			{
				if (flr->map[pos->y][pos->x] == 'x' ||
					flr->map[pos->y][pos->x] == 'X')
					flr->map_dist[pos->y][pos->x] = -2;
				else if (flr->map[pos->y][pos->x] == 'o' ||
						 flr->map[pos->y][pos->x] == 'O')
					flr->map_dist[pos->y][pos->x] = -1;
				else
					finding_dist(flr, pos, &tmp->pos);
			}
		}
		tmp = tmp->next;
	}
	flr->fst_launch = 0;
}

void	write_distances(t_filler *flr)
{
	t_point		pos;
	t_enmlst	*tmp;

	flr->fst_launch = 0;
	flr->list = add_points_to_list(flr);
	tmp = flr->list;
	print_lst(tmp);
	while (tmp)
	{
		pos.y = -1;
		while (++pos.y < flr->size_m.y)
		{
			pos.x = -1;
			while (++pos.x < flr->size_m.x)
				if (flr->map[pos.y][pos.x] == 'x' ||
					flr->map[pos.y][pos.x] == 'X')
					flr->map_dist[pos.y][pos.x] = -2;
				else if (flr->map[pos.y][pos.x] == 'o' ||
						flr->map[pos.y][pos.x] == 'O')
					flr->map_dist[pos.y][pos.x] = -1;
				else
					finding_dist(flr, &pos, &tmp->pos);
		}
		tmp = tmp->next;
	} 
}
















































