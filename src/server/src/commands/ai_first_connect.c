/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** ai_first_connect
*/

#include "server.h"
#include "macro.h"
#include "game_macro.h"

static void connect_player(node_t *client, data_t data)
{
    client->client.is_conn = true;
    client->client.pos.x = rand_nbr(0, data.width - 1);
    client->client.pos.y = rand_nbr(0, data.height - 1);
    client->client.inventory.food.quantity = 10;
    client->client.orientation = rand_nbr(1, NUMBER_OF_ORIENTATION);
    client->client.level = 1;
}

static void connect_player_to_egg(node_t *client, pos_t egg_pos)
{
    client->client.is_conn = true;
    client->client.pos = egg_pos;
    client->client.inventory.food.quantity = 10;
    client->client.orientation = rand_nbr(1, NUMBER_OF_ORIENTATION);
    client->client.level = 1;
}

static void check_availability(char *buffer, node_t *client, data_t *data)
{
    node_t *current = data->egg;

    while (current != NULL) {
        if (strcmp(current->egg.team->name, buffer) == 0) {
            connect_player_to_egg(client, current->egg.pos);
            client->client.team->clients_nbr--;
            fmt_egg_conn(data->graphic_fd, current->egg.id);
            remove_egg_node(&data->egg, current->egg.id);
            return;
        }
        current = current->next;
    }
    connect_player(client, *data);
}

static team_t *add_player_to_team(char *name, int fd, data_t *data)
{
    char buffer[1024];
    int bytes = 0;

    for (int i = 0; i < data->nb_teams; i++) {
        if (strcmp(name, data->teams[i].name) == 0
        && data->teams[i].clients_nbr > 0) {
            data->teams[i].clients_nbr--;
            bytes = sprintf(buffer, "%i\n%i %i", data->teams[i].clients_nbr,
            data->width, data->height);
            buffer[bytes] = '\0';
            dprintf(fd, "%s\n", buffer);
            return &data->teams[i];
        }
    }
    return NULL;
}

int do_ai_first_connect(char *buffer, node_t *client, data_t *data)
{
    team_t *team = add_player_to_team(buffer, client->client.fd, data);
    if (team != NULL) {
        client->client.team = team;
        check_availability(buffer, client, data);
        fmt_conn_new_player(data->graphic_fd, client->client);
        return SUCCESS;
    }
    return FAILURE;
}
