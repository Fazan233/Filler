#include "libft.h"

int 	main()
{
	char	*line;

	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (line[0] == '0')
		{
			ft_printf("%s\n", line + 4);
			free(line);
			while (get_next_line(STDIN_FILENO, &line) > 0)
			{
				if (ft_atoi(line))
					ft_printf("%s\n", line + 4);
				else
					break ;
				free(line);
			}
			ft_printf("\n");
		}
		free(line);
	}
	return (0);
}