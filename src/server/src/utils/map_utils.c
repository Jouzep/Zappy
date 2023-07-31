/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** map_utils
*/

#include "server.h"

resource_t *get_resource_by_name_on_tile(char *name, tile_t *tile)
{
    if (strcmp(name, FOOD_NAME) == 0)
        return &tile->food;
    if (strcmp(name, LINEMATE_NAME) == 0)
        return &tile->linemate;
    if (strcmp(name, DERAUMERE_NAME) == 0)
        return &tile->deraumere;
    if (strcmp(name, SIBUR_NAME) == 0)
        return &tile->sibur;
    if (strcmp(name, MENDIANE_NAME) == 0)
        return &tile->mendiane;
    if (strcmp(name, PHIRAS_NAME) == 0)
        return &tile->phiras;
    if (strcmp(name, THYSTAME_NAME) == 0)
        return &tile->thystame;
    return NULL;
}
