/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** graphic_communication
*/

#include "server.h"
#include "macro.h"
#include "game_macro.h"

static void choose_cmd(char *buffer, node_t *client, server_t *server)
{
    char *cmd = strtok(buffer, " ");
    char *params = NULL;
    int pos = 0;

    pos = get_cmd_pos(cmd, GUI_CMD_LIB);
    if (pos != -1) {
        params = strtok(NULL, "");
        server->gui_cmd[pos](client->client.fd, &server->data,
        params);
    } else {
        fmt_unknown_cmd(client->client.fd);
    }
}

int do_graphic_communication(char *buffer, node_t *client, server_t *server)
{
    if (!client->client.is_conn)
        if (do_graphic_first_connect(buffer, client, &server->data) == SUCCESS)
            return SUCCESS;
    if (client->client.is_graphic) {
        choose_cmd(buffer, client, server);
        return SUCCESS;
    }
    return FAILURE;
}
