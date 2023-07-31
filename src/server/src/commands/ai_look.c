/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** ai_look
*/

#include "server.h"

void cross_map_border(int *x, int *y, int width, int height)
{
    if ((*x) > width - 1)
        (*x) = (*x) - width;
    if ((*y) > height - 1)
        (*y) = (*y) - height;
    if (*x < 0)
        *x = width - abs(*x);
    if ((*y) < 0)
        (*y) = height - abs(*y);
}

tile_t get_correct_tile(tile_t **map, int x, int y, data_t data)
{
    cross_map_border(&x, &y, data.width, data.height);
    return map[y][x];
}

void check_presence_on_tile(tile_t tile, node_t *players, char **msg)
{
    int nb_players = get_nb_players_on_tile(tile.pos, players);
    for (int i = 0; i < nb_players; i++)
        my_strcat(msg, "player ");
    for (int i = 0; i < tile.food.quantity; i++)
        my_strcat(msg, "food ");
    for (int i = 0; i < tile.linemate.quantity; i++)
        my_strcat(msg, "linemate ");
    for (int i = 0; i < tile.deraumere.quantity; i++)
        my_strcat(msg, "deraumere ");
    for (int i = 0; i < tile.sibur.quantity; i++)
        my_strcat(msg, "sibur ");
    for (int i = 0; i < tile.phiras.quantity; i++)
        my_strcat(msg, "phiras ");
    for (int i = 0; i < tile.thystame.quantity; i++)
        my_strcat(msg, "thystame ");
    (*msg)[strlen((*msg)) - 1] = '\0';
    my_strcat(msg, ", ");
}

void ai_cmd_look(node_t *client, data_t *data,
char **params __attribute__((unused)))
{
    char *msg = NULL;

    msg = strdup("[ ");
    match_direction(client->client, data, &msg);
    msg[strlen(msg) - 2] = '\0';
    my_strcat(&msg, " ]");
    dprintf(client->client.fd, "%s\n", msg);
    free(msg);
}
