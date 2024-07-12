#include "../cube.h"

void	invalid_map(char *filename, t_data *game)
{
	int		fd;
	char	*extension;

	extension = ft_strrchr(filename, '.');
	if (!(extension && ft_strcmp(extension + 1, "cub") == 0))
	{
		error("Error: Invalid file extension is not .cub.\n", game);
	}
	fd = open(filename, O_DIRECTORY);
	if (fd != -1)
	{
		error("Failed to open, this is a directory\n", game);
		exit(1);
	}
	close (fd);
}

void parse_texture(t_data *game, char *line)
{
    if (line[0] == 'N' && line[1] == 'O')
        game->config.north_texture = ft_strdup(line);
    else if (line[0] == 'S' && line[1] == 'O')
        game->config.south_texture = ft_strdup(line);
    else if (line[0] == 'W' && line[1] == 'E')
        game->config.west_texture = ft_strdup(line);
    else if (line[0] == 'E' && line[1] == 'A')
        game->config.east_texture = ft_strdup(line);
}

void trim_newline(char *str)
{
    char *newline;
    newline = strchr(str, '\n');
    if (newline)
        *newline = '\0';
}

// void parse_rgb(t_data *game, char *line) {
//     char **split_space;
//     char **split_comma;
//     int i;

//     // Split line by spaces
//     split_space = ft_split(line + 2, ' ');
//     if (!split_space || !split_space[0] || !split_space[1] || split_space[2]) {
//         ft_putstr("Error: Invalid input format\n");
//         exit(1);
//     }

//     // Split the second part by commas
//     split_comma = ft_split(split_space[1], ',');
//     if (!split_comma || !split_comma[0] || !split_comma[1] || !split_comma[2] || split_comma[3]) {
//         ft_putstr("Error: Invalid input format\n");
//         exit(1);
//     }

//     // Store strings in the config arrays using while loops
//     i = 0;
//     while (i < 3) {
//         trim_newline(split_comma[i]); // Trim newline characters
//         if (line[0] == 'F') {
//             strncpy(game->config.floor_colors[i], split_comma[i], 10);
//         } else if (line[0] == 'C') {
//             strncpy(game->config.ceiling_colors[i], split_comma[i], 10);
//         }
//         free(split_comma[i]);
//         i++;
//     }
//     free(split_comma);

//     // Free split_space memory
//     free(split_space[0]);
//     free(split_space[1]);
//     free(split_space);
// }


void parse_colors(t_data *game, char *line)
{
    char **split;
    int i;
    char floor_colors[3];
    char ceiling_colors[3];
    if (line[0] == 'F' || line[0] == 'C')
    {
        split = ft_split(line + 2, ',');
        i = 0;
        while (i < 3)
        {
            // if (line[0] == 'F')
            //     floor_colors[i] = split[i];
            // else if (line[0] == 'C')
            //     ceiling_colors[i] = split[i];
            // colors[i] = ft_atoi(split[i]);
            if (line[0] == 'F')
                game->config.floor_color[i] = ft_atoi(split[i]);
            if (line[0] == 'C')
                game->config.ceiling_color[i] = ft_atoi(split[i]);
            // ft_putchar('\n');
            // ft_putnbr(game->config.floor_color[i]);
            free(split[i]);
            i++;
        }
        free(split);
        // for(int x = 0; x < 3; x++)
        // {
        //     ft_putstr(floor_colors[x]);
        //     ft_putchar('\n');
        //     ft_putstr(ceiling_colors[x]);
        // }
    }
}

void read_file(t_data *game, char *filename)
{
    int fd;
    char *line;
    
    fd = open(filename, O_RDONLY);
    invalid_map(filename, game);
    if (fd < 0)
        error("Error: Failed to open file", game);
    line = get_next_line(fd); 
    int numoflines = 0;
    while(line != NULL)
    {
        numoflines++;
        parse_texture(game, line);
        parse_colors(game, line);
        // parse_rbg(line);
        // if (line[0] == 'F' || line[0] == 'C')
        //     parse_rgb(game, line);
        free(line);
        line = get_next_line(fd); 
    }
    close (fd);
}