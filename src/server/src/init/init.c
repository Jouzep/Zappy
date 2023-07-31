/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** init
*/

#include "server.h"
#include "macro.h"

int global_init(server_t *server, int port)
{
    if (init_server(server, port) == FAILURE)
        return FAILURE;
    if (init_game(&server->data, server->info) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
