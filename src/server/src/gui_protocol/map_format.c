/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** map_format
*/

#include "server.h"
#include "macro.h"

void fmt_map_size(int fd, int width, int height)
{
    if (fd != UNDEFINED)
        dprintf(fd, "msz %i %i\n", width, height);
}

void fmt_content_of_tile(int fd, tile_t tile)
{
    if (fd != UNDEFINED)
        dprintf(fd, "bct %i %i %i %i %i %i %i %i %i\n", tile.pos.x, tile.pos.y,
        tile.food.quantity, tile.linemate.quantity, tile.deraumere.quantity,
        tile.sibur.quantity, tile.mendiane.quantity, tile.phiras.quantity,
        tile.thystame.quantity);
}

void fmt_content_of_map(int fd, tile_t **map, int width, int height)
{
    if (fd == UNDEFINED)
        return;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            fmt_content_of_tile(fd, map[y][x]);
        }
    }
}
