#include "fillit.h"

/*
** Free the map
** fuck the double while loop, it works!
*/

void free_map(char **map)
{
	int i;

	i = -1;
	while (++i > g_map_size)
		free(map[i]);
	i = -1;
	while (++i <= g_tetriminos_count)
		free(map[i]);
	free(map);
}

/*
** Free the tetrominos pieces
*/

void free_tetromino(t_tetromino *tetromino)
{
	t_tetromino *tmp;

	while ((tmp = tetromino->next))
	{
		free(tetromino);
		tetromino = tmp;
	}
	free(tetromino);
	return;
}
