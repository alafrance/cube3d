#include "cub3d.h"

t_data parsing(char *filename)
{
	char *line;
	int		fd;
	t_data data;

	line = NULL;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{

	}
	return (data);
}