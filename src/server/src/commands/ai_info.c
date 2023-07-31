/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** ai_info
*/

#include "server.h"
#include "macro.h"
#include "game_macro.h"

void ai_cmd_inventory(node_t *client, data_t *data __attribute__((unused)),
char **params __attribute__((unused)))
{
    inventory_t inv = client->client.inventory;

    dprintf(client->client.fd, "[ food %i, linemate %i, deraumere %i, \
sibur %i, mendiane %i, phiras %i, thystame %i ]\n", inv.food.quantity,
    inv.linemate.quantity, inv.deraumere.quantity, inv.sibur.quantity,
    inv.mendiane.quantity, inv.phiras.quantity, inv.thystame.quantity);
}

static void send_all_client(data_t *data, pos_t pos_src, int current_fd,
char *msg)
{
    node_t *current = data->clients;

    while (current != NULL) {
        if (current->client.is_conn && !current->client.is_graphic
        && current->client.fd != current_fd) {
            dprintf(current->client.fd, "message %i, %s\n",
            get_sound_trajectory(pos_src, current->client.pos,
            current->client.orientation, (pos_t) {data->width, data->height}),
            msg);
        }
        current = current->next;
    }
}

void ai_cmd_broadcast(node_t *client, data_t *data, char **params)
{
    char msg[BUFFER_SIZE] = "";

    if (params[0] == NULL) {
        fmt_cmd_parameter(client->client.fd);
    } else {
        strcat(msg, params[0]);
        for (int i = 1; params[i] != NULL; i++) {
            strcat(msg, " ");
            strcat(msg, params[i]);
        }
        msg[strlen(msg)] = '\0';
        fmt_player_broadcast(data->graphic_fd, client->client, msg);
        send_all_client(data, client->client.pos, client->client.fd, msg);
        dprintf(client->client.fd, "ok\n");
    }
}
