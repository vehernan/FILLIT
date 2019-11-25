/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vehernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 19:48:48 by vehernan          #+#    #+#             */
/*   Updated: 2019/11/21 17:12:32 by vehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Display a usage message on how to use fillit. :)
** Function ft_progname(), will output in a string, the name of the program.
*/

static void		usage(char *argv0)
{
	ft_putstr("usage: ");
	ft_putstr(argv0);
	ft_putstr(" [fillit_file]\n");
}

/*
** Prints the map after the smallest square made up with the given tetrominos
** is finally found. This will be the output of the program.
*/

static void		print_map(char **map)
{
	size_t		i;
	size_t		len;

	i = -1;
	len = ft_strlen(*map);
	while (++i < len)
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
	}
}

/*
** If the number of arguments isn't equal to two (2), it will print the usage
** message.
**
** If there is an error while opening the file, the output will print "error",
** then it closes the file.
**
** If the reading is successfull (there is at least one tetromino in the map),
** and if the file is not empty, we will solve the map, by assigning the correct
** to the tetrominos, solving the map with the given tetrominos, and then
** printing the smallest possible square formed with the tetrominos.
*/

int				main(int argc, char *argv[])
{
	int			fd;
	char		**parse;
	char		**map;
	t_tetromino *tetrominos;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			ft_putstr("error\n");
		else if ((parse = f_read(fd)) && (ft_strlen(parse[0])))
		{
			tetrominos = fillit_tetromino(parse);
			map = solve(tetrominos); //5 leaks here
			print_map(map); //no leaks
			free_map(map); //8 leaks
			free_tetromino(tetrominos);
		}
		else
			ft_putstr("error\n");
		close(fd);
	}
	else
		usage(argv[0]);
						while (1);
	return (0);
}
