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
