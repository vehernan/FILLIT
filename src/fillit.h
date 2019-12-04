/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vehernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 22:43:56 by vehernan          #+#    #+#             */
/*   Updated: 2019/11/16 20:19:31 by vehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"

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
** Macros for letter characters, and rows, colum, cord.
*/

# define LETTER     'A'
# define NUM_TETS   (0)
# define ROW        (1)
# define COL        (2)
# define COORD      (3)

/*
** Macros for tetromino width, size, and the max numbers of tetromino.
*/

# define SIZE       (4)
# define SIZE_TET   (21)
# define MAX_TETS   (26)

/*
** Tetrominio encoded values
*/

char	*g_tetrominos_value[20];

/*
** Global variable for number of tetriminos
*/

int		g_tetrominos_count;
int		g_map_size;

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

char					**read_file(int fd);
char					**create_map(int size);
char					**solve(t_tetromino *tet);
t_tetromino				*get_tetrominos(char **map);
void					free_tetromino(t_tetromino *tetromino);
void					free_map(char **map);

#endif
