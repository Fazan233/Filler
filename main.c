#include <fcntl.h>
#include <printf.h>
#include "filler.h"
#include <stdio.h>
# define SIZE_X 99
# define SIZE_Y 100
//#include "ft_printf.h"

int	main()
{
//	ft_printf("{RED}Hello {PURPLE}{BOLD}AAANGRY {GREEN}world");
//	ft_printf("[%300.-20p]\n", "Hello");
//	printf("[%-300.--20p]\n", "Hello");
	t_filler	flr;
	flr.map = (char**)malloc(sizeof(char*) * SIZE_Y);
	flr.size_m.x = SIZE_X;
	flr.size_m.y = SIZE_Y;
	int	fd;
	fd = open("map02", O_RDONLY);
	int i = -1;
	char	*line;
	while (++i < SIZE_Y)
	{
		get_next_line(fd, &line);
		flr.map[i] = line;
//		ft_printf("%s\n", flr.map[i]);
	}
//	flr.map[0] =  "..........";
//	flr.map[1] =  "..........";
//	flr.map[2] =  "..oo......";
//	flr.map[3] =  "OOOoOOO....";
//	flr.map[4] =  "..ooXX....";
//	flr.map[5] =  "...ooX....";
//	flr.map[6] =  ".....Xxx..";
//	flr.map[7] =  ".......x..";
//	flr.map[8] =  ".......x..";
//	flr.map[9] =  "..........";

	flr.map_dist = (int**)malloc(sizeof(int*) * SIZE_Y);
	i = -1;
	int j;
	while (++i < SIZE_Y)
	{
		flr.map_dist[i] = (int*)malloc(sizeof(int) * SIZE_X);
		j = -1;
		while (++j < SIZE_X) {
			flr.map_dist[i][j] = 20000;
//			ft_printf("%5i ", flr.map_dist[i][j]);
		}
//		ft_printf("\n");
	}
	flr.myfigure = 'x';

//	flr.mas_len = SIZE_X > SIZE_Y ? SIZE_X : SIZE_Y;
//	flr.mas_pow = (int16_t*)ft_memalloc(sizeof(int16_t) * flr.mas_len);
//	i = -1;
//	while (++i < flr.mas_len)
//		ft_printf("%5i ", flr.mas_pow[i] = ft_pow(i + 1, 2));

	write_distances(&flr);
	int x, y = -1;
	while (++y < SIZE_Y)
	{
		x = -1;
		while (++x < SIZE_X)
		{
//			if (flr.map_dist[y][x] == -2)
//				ft_printf("{GREEN}");
//			if (flr.map_dist[y][x] == -1)
//				ft_printf("{RED}");
			if (flr.map_dist[y][x] > 2500)
				ft_printf("{RED}");
			else if (flr.map_dist[y][x] > 2000)
				ft_printf("{PURPLE}");
			else if (flr.map_dist[y][x] > 1000)
				ft_printf("{CYAN}");
			else if (flr.map_dist[y][x] > 500)
				ft_printf("{GREEN}");
			else if (flr.map_dist[y][x] > 200)
				ft_printf("{BLUE}");
			else
				ft_printf("{YELLOW}");
			ft_printf("%5i ", flr.map_dist[y][x]);
			if (flr.map_dist[y][x] == -2 || flr.map_dist[y][x] == -1)
				ft_printf("{EOC}");
		}
		ft_printf("\n");
	}
	return (0);
}