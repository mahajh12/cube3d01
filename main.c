#include "cube.h"

void init(t_data *game)
{
    int i;
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, 800, 600, "Cube3d");
    game->config.north_texture = NULL;
    game->config.south_texture = NULL;
    game->config.west_texture = NULL;
    game->config.east_texture = NULL;
}

int main(int ac, char *av[])
{
    t_data game;
    t_rbg rbg;
    void *mlx;
    void *win;

    init(&game);
    read_file(game.mlx, av[1]);
    mlx_loop(game.mlx);
    return (0);
}