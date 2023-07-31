/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** add_client_list
*/

#include "server.h"
#include "macro.h"
#include "game_macro.h"

static void init_inventory(inventory_t *inventory)
{
    inventory->food = (resource_t) {FOOD_ID, FOOD_DENSITY, 0};
    inventory->linemate = (resource_t) {LINEMATE_ID, LINEMATE_DENSITY, 0};
    inventory->deraumere = (resource_t) {DERAUMERE_ID, DERAUMERE_DENSITY, 0};
    inventory->sibur = (resource_t) {SIBUR_ID, SIBUR_DENSITY, 0};
    inventory->mendiane = (resource_t) {MENDIANE_ID, MENDIANE_DENSITY, 0};
    inventory->phiras = (resource_t) {PHIRAS_ID, PHIRAS_DENSITY, 0};
    inventory->thystame = (resource_t) {THYSTAME_ID, THYSTAME_DENSITY, 0};
}

static void init_client_data(node_t **node)
{
    (*node)->client.fd = UNDEFINED;
    (*node)->client.is_conn = false;
    (*node)->client.is_graphic = false;
    (*node)->client.pos = (pos_t) {UNDEFINED, UNDEFINED};
    (*node)->client.orientation = UNDEFINED;
    (*node)->client.level = UNDEFINED;
    (*node)->client.timer = 0;
    init_inventory(&(*node)->client.inventory);
    (*node)->client.team = NULL;
    (*node)->client.is_ready = true;
    (*node)->client.is_elevating = false;
    (*node)->client.done_elevating = false;
    uuid_clear((*node)->client.elevation_uuid);
    (*node)->client.nb_await_cmd = 0;
    (*node)->next = NULL;
}

node_t *add_client_node(node_t **head)
{
    node_t *new_node = malloc(sizeof(node_t));
    node_t *current = NULL;

    init_client_data(&new_node);
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
