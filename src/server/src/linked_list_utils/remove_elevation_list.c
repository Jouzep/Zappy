/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** remove_elevation_list
*/

#include "server.h"

static void set_next_node(node_t **head, node_t *current, node_t *previous)
{
    if (previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }
}

void remove_elevation_node(node_t **head, uuid_t uuid)
{
    node_t *current = *head;
    node_t *previous = NULL;

    while (current != NULL) {
        if (uuid_compare(current->elevation.uuid, uuid) == 0) {
            set_next_node(head, current, previous);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}
