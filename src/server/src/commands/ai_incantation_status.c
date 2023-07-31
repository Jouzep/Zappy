/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** ai_incantation_status
*/

#include "server.h"

void success_elevate(node_t *players, int fd, int graph_fd)
{
    node_t *current = players;

    while (current != NULL) {
        if (current->client.fd == fd) {
            current->client.level++;
            fmt_player_lvl(graph_fd, current->client);
            dprintf(current->client.fd, "Current level: %i\n",
            current->client.level);
        }
        current = current->next;
    }
}

void failure_elevate(node_t *players, int fd)
{
    node_t *current = players;

    while (current != NULL) {
        if (current->client.fd == fd) {
            dprintf(current->client.fd, "ko\n");
        }
        current = current->next;
    }
}

void done_elevate(node_t *players, int fd)
{
    node_t *current = players;

    while (current != NULL) {
        if (current->client.fd == fd) {
            current->client.is_elevating = false;
            current->client.timer = 0;
        }
        current = current->next;
    }
}
