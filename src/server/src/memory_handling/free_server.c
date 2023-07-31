/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** free_server
*/

#include "server.h"

void free_server(server_t server)
{
    for (int i = 0; server.info.teams_name[i] != NULL; i++)
        free(server.info.teams_name[i]);
    free(server.info.teams_name);
    free_node(server.data.clients);
}
