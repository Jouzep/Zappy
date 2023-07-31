/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** ai_movement
*/

#include "server.h"
#include "game_macro.h"
#include "macro.h"

static void move_player(int *pos, bool cross, int cross_value, int ampl)
{
    if (cross) {
        (*pos) = cross_value;
    } else {
        (*pos) += ampl;
    }
}

static void update_graphic(int graph_fd, client_t player)
{
    if (graph_fd != UNDEFINED)
        fmt_player_pos(graph_fd, player);
}

void ai_cmd_forward(node_t *client, data_t *data,
char **params __attribute__((unused)))
{
    switch (client->client.orientation) {
        case NORTH:
            move_player(&client->client.pos.y,
            client->client.pos.y + 1 > data->height - 1, 0, 1);
            break;
        case EAST:
            move_player(&client->client.pos.x,
            client->client.pos.x + 1 > data->width - 1, 0, 1);
            break;
        case SOUTH:
            move_player(&client->client.pos.y,
            client->client.pos.y - 1 < 0, data->height - 1, -1);
            break;
        case WEST:
            move_player(&client->client.pos.x,
            client->client.pos.x - 1 < 0, data->width - 1, -1);
            break;
    }
    dprintf(client->client.fd, "ok\n");
    update_graphic(data->graphic_fd, client->client);
}

void ai_cmd_right(node_t *client, data_t *data,
char **params __attribute__((unused)))
{
    if (client->client.orientation + 1 > NUMBER_OF_ORIENTATION) {
        client->client.orientation = NORTH;
    } else {
        client->client.orientation++;
    }
    dprintf(client->client.fd, "ok\n");
    update_graphic(data->graphic_fd, client->client);
}

void ai_cmd_left(node_t *client, data_t *data,
char **params __attribute__((unused)))
{
    if (client->client.orientation - 1 < 1) {
        client->client.orientation = WEST;
    } else {
        client->client.orientation--;
    }
    dprintf(client->client.fd, "ok\n");
    update_graphic(data->graphic_fd, client->client);
}
