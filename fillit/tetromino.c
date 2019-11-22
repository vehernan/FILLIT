/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetromino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vehernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 19:44:44 by vehernan          #+#    #+#             */
/*   Updated: 2019/11/03 19:44:47 by vehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Set the correct dimensions, width and height, to the tetromino.
** If the row x coordinate is equal to the col x coordinate, we increment the
** width. Same way with the height, just swaping x with y. If the division of
** width or height by 4 (4) isn't exact, we increment to both width and
** height by four (4), to have the correct values of those weirds tetrominos.
** The -1 in both row and col is because... you guessed it, the fucking norm.
*/

static void			set_dimensions(t_tetromino *tet)
{
	int				row;
	int				col;
	int				width;
	int				height;

	row = -1;
	width = 0;
	height = 0;
	while (++row < 4)
	{
		col = -1;
		while (++col < 4)
		{
			width += (tet->x[row] == tet->x[col]) ? 1 : 0;
			height += (tet->y[row] == tet->y[col]) ? 1 : 0;
		}
	}
	if ((width % 4) || (height % 4))
	{
		width += 4;
		height += 4;
	}
	tet->width = (width / 4);
	tet->height = (height / 4);
}

/*
** Split the map (2D Array) to convert it to fullmap (3D Array), so we can
** work with the number of the tetrominos (working as an ID for each one).
*/

static char			***split_tetromino(char ***fullmap, char **map)
{
	int				i;

	i = -1;
	while (++i < g_tetriminos_count)
		fullmap[i] = ft_strsplit(map[i], '\n');
	return (fullmap);
}

/*
** Makes new tetrominos by mallocing them. We will give the size of the
** t_tetromino type, to allocate them correctly.
*/

static t_tetromino	*new_tetrominos(int size)
{
	int				i;
	t_tetromino		*new;
	t_tetromino		*head;

	if (!(new = (t_tetromino *)malloc(sizeof(t_tetromino) + 1)))
		return (NULL);
	head = new;
	i = 0;
	while (i++ < size)
	{
		if (!(new->next = (t_tetromino *)malloc(sizeof(t_tetromino) + 1)))
			return (NULL);
		new = new->next;
	}
	ft_memset(new, 0, (sizeof(t_tetromino) + 1));
	return (head);
}

/*
** Creates new tetrominos by assigning the x and y coordinates of every '#'
** into its structure, and also assigning the letter (A, B, C...) into its
** structure. We used an array of counters because of the fucking norm.
** The counters represent:
** Counter[0] = Number of tetrominos.
** Counter[1] = Rows of the tetromino.
** Counter[2] = Columns of the tetromino.
** Counter[3] = X and Y coordinates of the position of the tetromino.
**
** Every tetromino gets assigned a certain letter. Starting from the first one,
** then the second one gets assigned the next letter, and so on and so forth.
** Example: tetromino1 -> A; tetromino2 -> B; tetromino3 -> C; ...
*/

static t_tetromino	*create_tetrominos(char ***fullmap, \
					t_tetromino *tet, char letter, int *data)
{
	t_tetromino		*head;

	head = tet;
	data[NUM_TET] = -1;
	while (++data[NUM_TET] < g_tetriminos_count)
	{
		data[COORD] = 0;
		data[ROW] = -1;
		while (++data[ROW] < 4)
		{
			data[COL] = -1;
			while (++data[COL] < 4)
			{
				if (fullmap[data[NUM_TET]][data[ROW]][data[COL]] == '#')
				{
					tet->x[data[COORD]] = data[ROW];
					tet->y[data[COORD]++] = data[COL];
				}
			}
		}
		set_dimensions(tet);
		tet->letter = letter++;
		tet = tet->next;
	}
	return (head);
}

/*
** Pretty much call all the other functions, and returns the newly created
** tetrominos from the map. In this function, the array of counter is defined.
*/

t_tetromino			*fillit_tetromino(char **map)
{
	int				i;
	int				*counter;
	char			***fullmap;
	t_tetromino		*tetrominos;
	t_tetromino		*list;

	i = -1;
	if (!(counter = (int *)malloc(sizeof(int) * 4)))
		return (NULL);
	if (!(fullmap = (char ***)malloc(sizeof(char **) * g_tetriminos_count + 1)))
		return (NULL);
	tetrominos = new_tetrominos(g_tetriminos_count);
	fullmap = split_tetromino(fullmap, map);
	list = create_tetrominos(fullmap, tetrominos, LETTER, counter);
	free(counter);
	while (++i < g_tetriminos_count)
		free(fullmap[i]);
	free(fullmap);
	return (list);
}
