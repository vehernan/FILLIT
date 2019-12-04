/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vehernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 19:44:52 by vehernan          #+#    #+#             */
/*   Updated: 2019/11/06 03:32:34 by vehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Possible tetriminos values just using binary as the representation.
** Might be also useful in the future for other modes such as special chars,
** or emojis or whatever...
*/

char		*g_tetrominos_values[] =
{
	"#...\n#...\n#...\n#...",
	".#..\n.#..\n.#..\n.#..",
	"..#.\n..#.\n..#.\n..#.",
	"...#\n...#\n...#\n...#",
	"####\n....\n....\n....",
	"....\n####\n....\n....",
	"....\n....\n####\n....",
	"....\n....\n....\n####",
	"##..\n.##.\n....\n....",
	".##.\n..##\n....\n....",
	"....\n##..\n.##.\n....",
	"....\n.##.\n..##\n....",
	"....\n....\n##..\n.##.",
	"....\n....\n.##.\n..##",
	".#..\n##..\n#...\n....",
	"..#.\n.##.\n.#..\n....",
	"...#\n..##\n..#.\n....",
	"....\n.#..\n##..\n#...",
	"....\n..#.\n.##.\n.#..",
	"....\n...#\n..##\n..#.",
	".##.\n##..\n....\n....",
	"..##\n.##.\n....\n....",
	"....\n.##.\n##..\n....",
	"....\n..##\n.##.\n....",
	"....\n....\n.##.\n##..",
	"....\n....\n..##\n.##.",
	"#...\n##..\n.#..\n....",
	".#..\n.##.\n..#.\n....",
	"..#.\n..##\n...#\n....",
	"....\n#...\n##..\n.#..",
	"....\n.#..\n.##.\n..#.",
	"....\n..#.\n..##\n...#",
	"##..\n##..\n....\n....",
	".##.\n.##.\n....\n....",
	"..##\n..##\n....\n....",
	"....\n##..\n##..\n....",
	"....\n.##.\n.##.\n....",
	"....\n..##\n..##\n....",
	"....\n....\n##..\n##..",
	"....\n....\n.##.\n.##.",
	"....\n....\n..##\n..##",
	"###.\n..#.\n....\n....",
	".###\n...#\n....\n....",
	"....\n###.\n..#.\n....",
	"....\n.###\n...#\n....",
	"....\n....\n###.\n..#.",
	"....\n....\n.###\n...#",
	".#..\n.#..\n##..\n....",
	"..#.\n..#.\n.##.\n....",
	"...#\n...#\n..##\n....",
	"....\n.#..\n.#..\n##..",
	"....\n..#.\n..#.\n.##.",
	"....\n...#\n...#\n..##",
	"#...\n###.\n....\n....",
	".#..\n.###\n....\n....",
	"....\n#...\n###.\n....",
	"....\n.#..\n.###\n....",
	"....\n....\n#...\n###.",
	"....\n....\n.#..\n.###",
	"##..\n#...\n#...\n....",
	".##.\n.#..\n.#..\n....",
	"..##\n..#.\n..#.\n....",
	"....\n##..\n#...\n#...",
	"....\n.##.\n.#..\n.#..",
	"....\n..##\n..#.\n..#.",
	"..#.\n###.\n....\n....",
	"...#\n.###\n....\n....",
	"....\n..#.\n###.\n....",
	"....\n...#\n.###\n....",
	"....\n....\n..#.\n###.",
	"....\n....\n...#\n.###",
	"#...\n#...\n##..\n....",
	".#..\n.#..\n.##.\n....",
	"..#.\n..#.\n..##\n....",
	"....\n#...\n#...\n##..",
	"....\n.#..\n.#..\n.##.",
	"....\n..#.\n..#.\n..##",
	"###.\n#...\n....\n....",
	".###\n.#..\n....\n....",
	"....\n###.\n#...\n....",
	"....\n.###\n.#..\n....",
	"....\n....\n###.\n#...",
	"....\n....\n.###\n.#..",
	"##..\n.#..\n.#..\n....",
	".##.\n..#.\n..#.\n....",
	"..##\n...#\n...#\n....",
	"....\n##..\n.#..\n.#..",
	"....\n.##.\n..#.\n..#.",
	"....\n..##\n...#\n...#",
	"###.\n.#..\n....\n....",
	".###\n..#.\n....\n....",
	"....\n###.\n.#..\n....",
	"....\n.###\n..#.\n....",
	"....\n....\n###.\n.#..",
	"....\n....\n.###\n..#.",
	".#..\n##..\n.#..\n....",
	"..#.\n.##.\n..#.\n....",
	"...#\n..##\n...#\n....",
	"....\n.#..\n##..\n.#..",
	"....\n..#.\n.##.\n..#.",
	"....\n...#\n..##\n...#",
	".#..\n###.\n....\n....",
	"..#.\n.###\n....\n....",
	"....\n.#..\n###.\n....",
	"....\n..#.\n.###\n....",
	"....\n....\n.#..\n###.",
	"....\n....\n..#.\n.###",
	"#...\n##..\n#...\n....",
	".#..\n.##.\n.#..\n....",
	"..#.\n..##\n..#.\n....",
	"....\n#...\n##..\n#...",
	"....\n.#..\n.##.\n.#..",
	"....\n..#.\n..##\n..#."
};

/*
** Sees if a tetromino piece is valid by making sure its absolute value is
** valid from a table defined above.
*/

static int	shape_verify(char *piece)
{
	int		i;
	int		total;

	i = -1;
	total = 113;
	while (++i < total)
		if (!ft_strncmp(piece, g_tetrominos_values[i],\
				ft_strlen(g_tetrominos_values[i]) - 1))
			return (1);
	return (0);
}

/*
** Validates the number and values of the characters found in the map (file).
** If something fails, such as having a larger or smaller tetromino width than
** whatever is defined, or having invalid tetromino sizes, it returns zero.
** Counter inside (tetromino[i++] == '\n') because of fucking norm. :)
*/

static int	valid_characters(char *tetromino)
{
	int		i;
	int		height;
	int		blocks;
	int		characters;

	i = 0;
	blocks = 0;
	characters = 0;
	height = 0;
	while ((tetromino[i] == '.' || tetromino[i] == '#' || \
		tetromino[i] == '\n') && tetromino[i] && (height != SIZE))
	{
		if (tetromino[i] == '.' || tetromino[i] == '#')
		{
			if (tetromino[i] == '#')
				blocks += 1;
			characters += 1;
		}
		if (tetromino[i++] == '\n')
			height += 1;
	}
	if (((characters) == SIZE * SIZE) && (height == SIZE) && \
		(blocks == SIZE) && (tetromino[i] == '\n' || tetromino[i] == '\0'))
		return (1);
	return (0);
}

/*
** Calls both functions to make sure that there are valid characters and
** valid tetromino in the map.
*/

static int	is_valid(char *piece)
{
	return (valid_characters(piece) && shape_verify(piece));
}

static char	*get_piece(int fd)
{
	int		i;
	char	*piece;
	char	*line;

	i = -1;
	piece = ft_strnew(SIZE_TET);
	while (++i < 4 && get_next_line(fd, &line) > 0)
	{
		piece = ft_strcat(piece, line);
		piece[ft_strlen(piece)] = '\n';
		free(line);
	}
	return (piece);
}

/*
** Reads a tetromino piece, one by one, and checks if its characters and
** size are right. TETROMINO_SIZE is the total size of a tetromino, it's defined
** by counting all the characters, including '\n', and '\0'. If a tetromino
** isn't valid, it'll return a NULL. If it doesn't find any problem with the
** pieces, it will return the characters read.
*/

char		**read_file(int fd)
{
	int		i;
	char	*end_line;
	char	**pieces;

	i = 0;
	if (!(pieces = (char **)malloc(sizeof(char *) * 2)))
		return (NULL);
	while (i < MAX_TETS)
	{
		pieces[i] = get_piece(fd);
		if (!(is_valid(pieces[i])))
		{
			free(pieces);
			return (NULL);
		}
		i += 1;
		g_tetrominos_count = i;
		if (get_next_line(fd, &end_line) == 0)
			return (pieces);
		free(end_line);
	}
	return (NULL);
}
