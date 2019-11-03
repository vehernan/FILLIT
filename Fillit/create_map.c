/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vehernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 21:05:52 by vehernan          #+#    #+#             */
/*   Updated: 2019/11/02 21:05:55 by vehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Revisar como se puede modificar la variable desde el arguments
**   fill_map(&map, '.')   ===>>   fill_map(char ***map, char val)
*/

static void  fill_map(char ***map, char val, int size)
{
  int row;
  int col;
  
  row = 0;
  while (row < size)
  {
    col = 0;
    while (col < size)
    {
      (*map)[row][col++] = val;
      (*map)[row][col] = '\0';
    }
    row += 1;
  }
}

/*
** Allocate a new map....
*/

static char  **allocate_map(int size)
{
  char **map;
  int i;

  i = 0;
  if (!(map = (char **)malloc(sizeof(char *) * size)))
    return (NULL);
  while (i < size)
  {
    if (!(map[i] = (char *)malloc(sizeof(char) * size + 1)))
      return (NULL);
    i += 1;
  }
  return (map);
}

/*
** Allocates memory to creat a new map. This function is called inside the
** fillit_solve(), in which, after retrying the function fillit_solve_map()
** recursivley, it will see if it needs to grow the map, hence why we use
** this function. I placed it in this file because of the fucking norm. :)
*/

char		**fillit_create_map(int size)
{
	char	**map;

  map = allocate_map(size);
  fill_map(&map, '.', size);
	return (map);
}
