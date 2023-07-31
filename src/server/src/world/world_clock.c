/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** world_clock
*/

#include "server.h"

void inc_players_timer(node_t *head)
{
    node_t *current = head;

    while (current != NULL) {
        if (is_ai_player(current->client) &&
        (current->client.nb_await_cmd > 0) && !current->client.is_elevating)
            current->client.timer++;
        current = current->next;
    }
}

bool check_done_incantation(node_t *players)
{
    node_t *current = players;

    while (current != NULL) {
        if (!current->client.done_elevating)
            return false;
        current = current->next;
    }
    return true;
}

void world_elevate_players(data_t *data)
{
    node_t *current = data->elevation;
    node_t *next = NULL;

    while (current != NULL) {
        current->elevation.timer++;
        if (current->elevation.timer >= COOLDOWN_INCANTATION) {
            next = current->next;
            elevate_player(current, data);
            current->elevation.timer = 0;
            remove_elevation_node(&data->elevation, current->elevation.uuid);
            current = next;
        } else {
            current = current->next;
        }
    }
}

void handle_world_clock(server_t *server)
{
    uint64_t num_exp;
    ssize_t bytes;

    if (FD_ISSET(server->data.w_clock.tfd, &server->addrs.rfds)) {
        bytes = read(server->data.w_clock.tfd, &num_exp, sizeof(uint64_t));
        if (bytes < 0)
            return;
        server->data.food_eat_tick++;
        server->data.food_refill_res++;
        inc_players_timer(server->data.clients);
        world_elevate_players(&server->data);
        eat_food(&server->data);
        refill_resources(&server->data);
        check_winning_team(&server->data);
    }
}
