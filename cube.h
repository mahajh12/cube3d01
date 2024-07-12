#ifndef CUBE_H
# define CUBE_H

# include "mlx/mlx.h"
# include "get_next_line/get_next_line.h"
# include <stdio.h>

typedef struct rbg
{
    int r_floor;
    int b_floor;
    int g_floor;
    int r_ceil;
    int b_ceil;
    int g_ceil;
} t_rbg;

typedef struct config
{
    char *north_texture;
    char *south_texture;
    char *west_texture;
    char *east_texture;
    int  floor_color[3];
    int  ceiling_color[3];  
    // char floor_colors[3][10];
    // char ceiling_colors[3][10];
}t_config;

typedef struct data
{
    // char **map;
    void *mlx;
    void *win;
    t_config config;
    t_rbg rbg;
    // int pos_x;
    // int pos_y;
    // int dx;
    // int dy;
} t_data;

void    read_file(t_data *game, char *filename);
void	ft_putstr(char *s);
void	error(char *error_message, t_data *game);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_putnbr(int n);
void	ft_putchar(char c);
size_t	ft_strlen(const char *s);
int	    ft_strcmp(char *s1, char *s2);
int	    ft_atoi(const char *str);
char	*ft_strrchr(const char *s, int c);
char	**ft_split(char const *s, char c);
#endif