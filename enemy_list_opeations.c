#include "filler.h"

static void	adding_to_lst(t_enmlst **lst, t_point *pos)
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

static void	add_lst_condition(t_filler *flr, t_enmlst **lst, t_point *pos)
{
	if (!flr->fst_launch)
	{
		if (flr->myfigure == 'o')
		{
			if (flr->map[pos->x + 4] == 'X' &&
				flr->map_dist[pos->y][pos->x] == -2)
				adding_to_lst(lst, pos);
		}
		else
			if (flr->map[pos->x + 4] == 'O' &&
				flr->map_dist[pos->y][pos->x] == -1)
				adding_to_lst(lst, pos);
	}
	else
	{
		if (flr->myfigure == 'o')
		{
			if (flr->map[pos->x + 4] == 'X')
				adding_to_lst(lst, pos);
		}
		else
			if (flr->map[pos->x + 4] == 'O')
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

void		delele_enemlst(t_enmlst **list)
{
	t_enmlst	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
}
