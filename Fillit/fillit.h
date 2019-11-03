
#ifndef FILLIT_H
# define FILLIT_H

# include "./Libft/libft.h"

/*
** Library fcntl.h included to be able to use open(), read().
*/

# include <fcntl.h>

/*
** Library stdlib.h included to be able to use free()
*/

# include <stdlib.h>

/*
** Library unistd.h included to be able to use close()
*/

# include <unistd.h>

/*
** Macros for empty, blocks, and letter characters.
*/

# define EMPTY '.'
# define BLOCK '#'
# define LETTER 'A'
# define NEW_LINE '\n'

/*
** Macros for tetromino width, size, and the max numbers of tetromino.
*/

# define SIZE 4
# define TETROMINO_SIZE 21
# define TETROMINO_MAX_TOTAL (26 - (LETTER - 'A'))

/*
** Macro for buffer size (the biggest file can only be 546 bytes + 1).
*/

# define BUFFER_SIZE  (TETROMINO_SIZE * TETROMINO_MAX_TOTAL)

/*
** Tetrominio encoded values thingy
*/

char  *g_tetriminos_value[20];

/*
** Global variable for number of tetriminos
*/

int		g_tetriminos_count;

/*
** Structures of a tetromino, defining the coordinates by its x and y values,
** the number of the tetromino (if it's the first one, second one, etc...).
*/

typedef struct			s_tetromino
{
	char				letter;
	int					x[4];
	int					y[4];
	int					width;
	int					height;
	struct s_tetromino	*next;
}						t_tetromino;

/*
** Prototypes for fillit functions.
*/

char					**fillit_read(int fd);
char					**fillit_create_map(int size);
char					**fillit_solve(t_tetromino *tet);
t_tetromino				*fillit_tetromino(char **map);

#endif
