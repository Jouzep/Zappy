/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** add_elevation_list
*/

#include "server.h"
#include "macro.h"

static void init_data(node_t **node)
{
    (*node)->elevation.pos = (pos_t) {UNDEFINED, UNDEFINED};
    (*node)->elevation.level = UNDEFINED;
    (*node)->elevation.timer = 0;
    (*node)->elevation.nb_players = 0;
    uuid_generate((*node)->elevation.uuid);
    (*node)->next = NULL;
}

node_t *add_elevation_node(node_t **head)
{
    node_t *new_node = malloc(sizeof(node_t));
    node_t *current = NULL;

    init_data(&new_node);
    if (*head == NULL) {
        *head = new_node;
    } else {
        current = *head;
        while (current->next != NULL)
            current = current->next;
        current->next = new_node;
    }
    return new_node;
}
