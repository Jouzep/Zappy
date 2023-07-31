/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** client_linked_list
*/

#include "server.h"

void print_client_list(node_t *head)
{
    node_t *current = head;

    while (current != NULL) {
        printf("Client fd: %i\n", current->client.fd);
        printf("Client is con: %i\n", current->client.is_conn);
        printf("Client is graph: %i\n\n", current->client.is_graphic);
        current = current->next;
    }
}

node_t *get_client_node(node_t **head, int fd)
{
    node_t *current = *head;

    while (current != NULL) {
        if (current->client.fd == fd) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}
