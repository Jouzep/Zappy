/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** ai_action
*/

#include "server.h"

void ai_cmd_team_unused_slot(node_t *client,
data_t *data __attribute__((unused)),
char **params __attribute__((unused)))
{
    dprintf(client->client.fd, "%i\n", client->client.team->clients_nbr);
}

void ai_cmd_fork_player(node_t *client, data_t *data,
char **params __attribute__((unused)))
{
    node_t *node = add_egg_node(&data->egg);
    int id = get_linked_list_length(data->egg) - 1;

    node->egg.id = id;
    node->egg.pos = client->client.pos;
    node->egg.team = client->client.team;
    node->egg.team->clients_nbr++;
    dprintf(client->client.fd, "ok\n");
    fmt_egg_laid(data->graphic_fd, node->egg.id, client->client,
    node->egg.pos);
}

static void move_player(node_t *player, int orient, int width, int height)
{
    switch (orient) {
        case NORTH:
                player->client.pos.y++;
            break;
        case EAST:
                player->client.pos.x++;
            break;
        case SOUTH:
                player->client.pos.y--;
            break;
        case WEST:
                player->client.pos.x--;
            break;
    }
    cross_map_border(&player->client.pos.x, &player->client.pos.y, width,
    height);
    dprintf(player->client.fd, "eject: %i\n", get_opposite_direction(orient));
}

void eject_eggs(pos_t pos, data_t *data)
{
    node_t *current = data->egg;
    node_t *next = NULL;

    while (current != NULL) {
        if (current->egg.pos.x == pos.x && current->egg.pos.y == pos.y) {
            next = current->next;
            fmt_egg_death(data->graphic_fd, current->egg.id);
            remove_egg_node(&data->egg, current->egg.id);
            current = next;
        } else {
            current = current->next;
        }
    }
}

void ai_cmd_eject(node_t *client, data_t *data,
char **params __attribute__((unused)))
{
    node_t *current = NULL;

    if (get_nb_players_on_tile(client->client.pos, data->clients) <= 1) {
        dprintf(client->client.fd, "ko\n");
        return;
    }
    current = data->clients;
    fmt_player_expulsion(data->graphic_fd, client->client);
    eject_eggs(client->client.pos, data);
    while (current != NULL) {
        if (is_ai_player(current->client)
        && current->client.fd != client->client.fd) {
            move_player(current, client->client.orientation, data->width,
            data->height);
            fmt_player_pos(data->graphic_fd, current->client);
        }
        current = current->next;
    }
    dprintf(client->client.fd, "ok\n");
}
