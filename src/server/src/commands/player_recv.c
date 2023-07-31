/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** player_recv
*/

#include "server.h"
#include "macro.h"

static int get_right_params(data_t data, char *params, node_t **player)
{
    if (params == NULL || !can_convert_to_int(params)) {
        return FAILURE;
    }
    (*player) = get_client_node(&data.clients, atoi(params));
    if ((*player) == NULL) {
        return FAILURE;
    }
    if ((*player)->client.is_graphic)
        return FAILURE;
    return SUCCESS;
}

void send_player_position(int fd, data_t *data, char *params)
{
    node_t *player = NULL;

    if (get_right_params(*data, params, &player) == FAILURE) {
        fmt_cmd_parameter(fd);
        return;
    }
    fmt_player_pos(fd, player->client);
}

void send_player_level(int fd, data_t *data, char *params)
{
    node_t *player = NULL;

    if (get_right_params(*data, params, &player) == FAILURE) {
        fmt_cmd_parameter(fd);
        return;
    }
    fmt_player_lvl(fd, player->client);
}

void send_player_inventory(int fd, data_t *data, char *params)
{
    node_t *player = NULL;

    if (get_right_params(*data, params, &player) == FAILURE) {
        fmt_cmd_parameter(fd);
        return;
    }
    fmt_player_inv(fd, player->client);
}
