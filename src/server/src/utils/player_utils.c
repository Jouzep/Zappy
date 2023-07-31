/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** player_utils
*/

#include "server.h"

bool is_ai_player(client_t player)
{
    if (player.is_conn && !player.is_graphic)
        return true;
    return false;
}

bool is_player_on_pos(client_t player, pos_t pos)
{
    if (is_ai_player(player) && player.pos.x == pos.x && player.pos.y == pos.y)
        return true;
    return false;
}

resource_t *get_resource_by_name_in_inventory(char *name,
inventory_t *inventory)
{
    if (strcmp(name, FOOD_NAME) == 0)
        return &inventory->food;
    if (strcmp(name, LINEMATE_NAME) == 0)
        return &inventory->linemate;
    if (strcmp(name, DERAUMERE_NAME) == 0)
        return &inventory->deraumere;
    if (strcmp(name, SIBUR_NAME) == 0)
        return &inventory->sibur;
    if (strcmp(name, MENDIANE_NAME) == 0)
        return &inventory->mendiane;
    if (strcmp(name, PHIRAS_NAME) == 0)
        return &inventory->phiras;
    if (strcmp(name, THYSTAME_NAME) == 0)
        return &inventory->thystame;
    return NULL;
}
