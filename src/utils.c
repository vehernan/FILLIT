/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vehernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 19:32:56 by vehernan          #+#    #+#             */
/*   Updated: 2019/11/30 19:35:16 by vehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Revisar como se puede modificar la variable desde el arguments
**   fill_map(&map, '.')   ===>>   fill_map(char ***map, char val)
*/

static void	fill_map(char **map, char val, int size)
{
	int		row;
	int		col;

	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			map[row][col++] = val;
			map[row][col] = '\0';
		}
		row += 1;
	}
	return ;
}

/*
** Allocate a new map....
*/

static char	**allocate_map(int size)
{
	char	**map;
	int		i;

	i = -1;
	if (!(map = (char **)malloc(sizeof(char *) * size)))
		return (NULL);
	while (++i < size)
		if (!(map[i] = ft_strnew(size)))
			return (NULL);
	return (map);
}

/*
** Allocates memory to creat a new map. This function is called inside the
** solve(), in which, after retrying the function fillit_solve_map()
** recursivley, it will see if it needs to grow the map, hence why we use
** this function. I placed it in this file because of the fucking norm. :)
*/

char		**create_map(int size)
{
	char	**map;

	map = allocate_map(size);
	fill_map(map, '.', size);
	return (map);
}

/*
** Free the map
** fuck the double while loop, it works!
*/

void			free_map(char **map)
{
	int			i;

	i = -1;
	while (++i < g_map_size)
		free(map[i]);
	free(map);
}

/*
** Free the tetrominos pieces
*/

void			free_tetromino(t_tetromino *tetromino)
{
	t_tetromino	*tmp;

	while ((tmp = tetromino->next))
	{
		free(tetromino);
		tetromino = tmp;
	}
	free(tetromino);
	return ;
}
