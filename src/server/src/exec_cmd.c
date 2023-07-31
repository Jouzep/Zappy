/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** exec_cmd
*/

#include "server.h"

static void free_params(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++)
        free(arr[i]);
    free(arr);
}

void execute_waiting_cmd(node_t *current, server_t *server)
{
    char **param_cpy = NULL;

    if (current->client.is_elevating)
        return;
    if (current->client.nb_await_cmd > 0
    && current->client.timer >= current->client.commands[0].timer) {
        current->client.nb_await_cmd--;
        if (current->client.commands[0].params != NULL) {
            param_cpy = current->client.commands[0].params;
            param_cpy++;
        }
        server->ai_cmd[current->client.commands[0].id](current,
        &server->data, param_cpy);
        if (current->client.commands[0].params != NULL)
            free_params(current->client.commands[0].params);
        memmove(&current->client.commands[0], &current->client.commands[1],
        sizeof(commands_t) * current->client.nb_await_cmd);
        current->client.timer = 0;
    }
}
