/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** egg_linked_list
*/

#include "server.h"
#include "macro.h"

static void init_egg_data(node_t **node)
{
    (*node)->egg.id = UNDEFINED;
    (*node)->egg.team = NULL;
    (*node)->egg.pos.x = UNDEFINED;
    (*node)->egg.pos.y = UNDEFINED;
    (*node)->next = NULL;
}

int get_linked_list_length(node_t *node)
{
    int i = 0;
    node_t *current = node;

    while (current != NULL) {
        i++;
        current = current->next;
    }
    return i;
}

static void set_next_node(node_t **head, node_t *current, node_t *previous)
{
    if (previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }
}

void remove_egg_node(node_t **head, int id)
{
    node_t *current = *head;
    node_t *previous = NULL;

    while (current != NULL) {
        if (current->egg.id == id) {
            set_next_node(head, current, previous);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

node_t *add_egg_node(node_t **head)
{
    node_t *new_node = malloc(sizeof(node_t));
    node_t *current = NULL;

    init_egg_data(&new_node);
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
