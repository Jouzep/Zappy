/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** global_free
*/

#include "server.h"

void free_node(node_t *head)
{
    node_t *current = head;
    node_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

void global_free(server_t server)
{
    free_game(server.data, server.info.height);
    free_server(server);
}
