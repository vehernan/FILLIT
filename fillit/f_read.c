/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vehernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 00:24:48 by vehernan          #+#    #+#             */
/*   Updated: 2019/11/06 01:57:54 by vehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Possible tetriminos values just using binary as the representation.
** Might be also useful in the future for other modes such as special chars,
** or emojis or whatever...
*/

char		*g_tetriminos_values[] =
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
		if (!ft_strncmp(piece, g_tetriminos_values[i],\
					ft_strlen(g_tetriminos_values[i]) - 1))
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

/*
** Returns a tetromino piece, but we don't know if it is a valid one so
** please shut the fuck up about this weird design pattern, but this is
** 42 anyways and people do like weird shit in this school because they copy
** each other for some reason? sorry for the rant, but I like this school
** because it also allows me to do creative shit like this without reprecusion
** because your boss in real life expects you to do clean, short, design
** oriented shit code, but it feels good when you can do that because your
** level of abstraction increase and you level up dude...
** Yep, I'm high as shit. :)
**
** ~~ hits blunt ~~
**
** But for real. It is better to follow guide-lines, be around smart people,
** and complete tickets... you feel that you are on a track, and you just have
** to complete this tasks. It is not like you are in limbo and have to guess
** how to design a project from scratch?
**
**                   dM
**                   MMr
**                  4MMML                  .
**                  MMMMM.                xf
**  .              "M6MMM               .MM-
**   Mh..          +MM5MMM            .MMMM
**   .MMM.         .MMMMML.          MMMMMh
**    )MMMh.        MM5MMM         MMMMMMM
**     3MMMMx.     'MMM3MMf      xnMMMMMM"
**     '*MMMMM      MMMMMM.     nMMMMMMP"
**       *MMMMMx    "MMM5M\    .MMMMMMM=
**        *MMMMMh   "MMMMM"   JMMMMMMP
**          MMMMMM   GMMMM.  dMMMMMM            .
**           MMMMMM  "MMMM  .MMMMM(        .nnMP"
**..          *MMMMx  MMM"  dMMMM"    .nnMMMMM*
** "MMn...     'MMMMr 'MM   MMM"   .nMMMMMMM*"
**  "4MMMMnn..   *MMM  MM  MMP"  .dMMMMMMM""
**    ^MMMMMMMMx.  *ML "M .M*  .MMMMMM**"
**       *PMMMMMMhn. *x > M  .MMMM**""
**          ""**MMMMhx/.h/ .=*"
**                   .3P"%....
**                 nP"     "*MMnx
*/

static char	*get_piece(int fd)
{
	int		i;
	char	*piece;
	char	*line;

	i = -1;
	piece = ft_strnew(TETROMINO_SIZE);
	while (++i < 4 && get_next_line(fd, &line) > 0)
	{
		piece = ft_strcat(piece, line);
		piece[ft_strlen(piece)] = '\n';
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

char		**f_read(int fd)
{
	int		i;
	char	*end_line;
	char	**pieces;

	i = 0;
	if (!(pieces = (char **)malloc(sizeof(char *) * BUFFER_SIZE)))
		return (NULL);
	while (i < TETROMINO_MAX_TOTAL)
	{
		pieces[i] = get_piece(fd);
		if (!(is_valid(pieces[i])))
			return (NULL);
		i += 1;
		g_tetriminos_count = i;
		if (get_next_line(fd, &end_line) == 0)
		{
			return (pieces);
		}
	}
	return (NULL);
}
