/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** ai_communication
*/

#include "server.h"
#include "macro.h"
#include "game_macro.h"

static void instant_exec(int pos, node_t *client, data_t *data)
{
    if (pos == CMD_FORK) {
        fmt_player_egg_laying(data->graphic_fd, client->client);
    }
}

static void add_cmd(node_t *client, int pos, char **params)
{
    client->client.commands[client->client.nb_await_cmd].id = pos;
    client->client.commands[client->client.nb_await_cmd].timer =
    AI_ACTION_CD[pos];
    client->client.commands[client->client.nb_await_cmd].params =
    params;
    client->client.nb_await_cmd++;
}

static void free_params(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++)
        free(arr[i]);
    free(arr);
}

static int choose_cmd(char *buffer, node_t *client, server_t *server)
{
    char **params = str_to_word_array(buffer, " \t");
    char *cmd = NULL;
    int pos = 0;

    if (params == NULL || params[0] == NULL)
        return FAILURE;
    cmd = params[0];
    pos = get_cmd_pos(cmd, AI_CMD_LIB);
    if (pos != -1) {
        if (client->client.nb_await_cmd < 10) {
            instant_exec(pos, client, &server->data);
            add_cmd(client, pos, params);
        } else {
            free_params(params);
        }
    } else {
        free_params(params);
        dprintf(client->client.fd, "ko\n");
    }
    return SUCCESS;
}

int do_ai_communication(char *buffer, node_t *client, server_t *server)
{
    if (!client->client.is_conn) {
        if (do_ai_first_connect(buffer, client, &server->data) == SUCCESS)
            return SUCCESS;
    } else {
        return choose_cmd(buffer, client, server);
    }
    return FAILURE;
}
