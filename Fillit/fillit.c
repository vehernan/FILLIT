#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 546
#define TETROMINOVAL 20
#define MAXAMOUNT 26

#include "fillit.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"

// utils.c

void    put_error(char *msg, int code) {
    ft_putendl(msg);
    exit(code);
    return ;
}

// validate.c

int		validate_tet(char *str)
{
	int t;
	int i;

	t = 0;
	i = 0;
	while (i < TETROMINOVAL)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				t++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				t++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				t++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				t++;
		}
		i++;
	}
	return (t == 6 || t == 8);
}

static int	verify_line(char *line)
{
	int		i;
	int		height;
	int		blocks;
	int		characters;

	i = 0;
	blocks = 0;
	characters = 0;
	height = 0;
	while ((line[i] == ' ' || line[i] == '#' || \
		line[i] == '\n') && line[i] && (height != 4))
	{
		if (line[i] == ' ' || line[i] == '#')
		{
			if (line[i] == '#')
				blocks += 1;
			characters += 1;
		}
		if (line[i++] == '\n')
			height += 1;
	}
	if (((characters) == 16) && (height == 4) && \
		(blocks == 4) && (line[i] == '\n' || line[i] == '\0'))
		return (1);
	return (0);
}

// int		check_tet(char *str, int d, int h, int n)
// {
// 	int	i;
// 	int	size;

// 	i = 0;
// 	size = ft_strlen(str);
// 	if (size < TETROMINOVAL)
// 		return (-1);
// 	while (size > i)
// 	{
// 		while (i < TETROMINOVAL)
// 		{
// 			if ((str[i] == '\n') && ((i + 1) % 5 == 0))
// 				n++;
// 			else if (str[i] == '.')
// 				d++;
// 			else if (str[i] == '#')
// 				h++;
// 			else
// 				return (0);
// 			i++;
// 		}
// 		if (str[i] != '\n')
// 			return (0);
// 		if (d == 12 && h == 4 && n == 4 && (validate_tet(str)))
// 			return (1);
// 		return (0);
// 	}
// 	return (1);
// }

int     verify_file(int fd) 
{
    // int r;
    int ret;
    // char buff[BUFFER_SIZE];
    char *line;

    ret = 0;
    // while ((r = read(fd, buff, BUFFER_SIZE)))
        // ft_putendl(buff);
    // check_tet()

    while (get_next_line(fd, &line) > 0)
    {
        if (!verify_line(line)) 
        {
            ret = -1;
            ft_putstr("ERROR");
            break ;
        } 
    }
    return (0);
}

// main.c

static void start_fillit(char *file)
{
    int fd;

    if ((fd = open(file, O_RDONLY)) < 0)
        put_error("Error opening file!", fd);
    if (verify_file(fd) < 0)
        put_error("Invalid fillit file!", fd);
    
    return ;
}

static void print_usage(char *name) 
{
    ft_putstr("Usage: ");
    ft_putstr(name);
    ft_putendl(" [fillit_file]");
    return ;
}

int main(int argc, char *argv[]) 
{
    if (argc == 2) 
        start_fillit(argv[1]);
    else 
        print_usage(argv[0]);
    return (0);
}
