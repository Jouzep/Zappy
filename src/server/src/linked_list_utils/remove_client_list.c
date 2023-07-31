/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** remove_client_list
*/

#include "server.h"

static void free_params(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++)
        free(arr[i]);
    free(arr);
}

static void free_client_commands(node_t *client)
{
    while (client->client.nb_await_cmd > 0) {
        client->client.nb_await_cmd--;
        if (client->client.commands[0].params != NULL)
            free_params(client->client.commands[0].params);
        memmove(&client->client.commands[0], &client->client.commands[1],
        sizeof(commands_t) * client->client.nb_await_cmd);
    }
}

static void set_next_node(node_t **head, node_t *current, node_t *previous)
{
    if (previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }
}

void remove_client_node(node_t **head, int fd)
{
    node_t *current = *head;
    node_t *previous = NULL;

    while (current != NULL) {
        if (current->client.fd == fd) {
            set_next_node(head, current, previous);
            free_client_commands(current);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}
