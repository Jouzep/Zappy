/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** ai_incantation
*/

#include "server.h"
#include "macro.h"

void remove_item_from_tile(int lvl, tile_t *tile)
{
    elevation_ritual_t requir = elev_requir[lvl - 1];

    tile->linemate.quantity -= requir.req_linemate;
    tile->deraumere.quantity -= requir.req_deraumere;
    tile->sibur.quantity -= requir.req_sibur;
    tile->mendiane.quantity -= requir.req_mendiane;
    tile->phiras.quantity -= requir.req_phiras;
    tile->thystame.quantity -= requir.req_thystame;
}

bool can_elevate(node_t *client, node_t *head, tile_t **map)
{
    client_t player = client->client;
    elevation_ritual_t requir = elev_requir[player.level - 1];

    int linemate = map[player.pos.y][player.pos.x].linemate.quantity;
    int deraumere = map[player.pos.y][player.pos.x].deraumere.quantity;
    int sibur = map[player.pos.y][player.pos.x].sibur.quantity;
    int mendiane = map[player.pos.y][player.pos.x].mendiane.quantity;
    int phiras = map[player.pos.y][player.pos.x].phiras.quantity;
    int thystame = map[player.pos.y][player.pos.x].thystame.quantity;
    int nb_player = get_nb_players_on_tile_w_lvl(player.pos, head,
    client->client.level);

    if (nb_player >= requir.req_player && linemate >= requir.req_linemate
    && deraumere >= requir.req_deraumere && sibur >= requir.req_sibur
    && mendiane >= requir.req_mendiane && phiras >= requir.req_phiras
    && thystame >= requir.req_thystame)
        return true;
    return false;
}

bool can_elevate_after(node_t *elev, tile_t **map, node_t *head)
{
    elevation_ritual_t requir = elev_requir[elev->elevation.level - 1];
    pos_t pos = elev->elevation.pos;

    int linemate = map[pos.y][pos.x].linemate.quantity;
    int deraumere = map[pos.y][pos.x].deraumere.quantity;
    int sibur = map[pos.y][pos.x].sibur.quantity;
    int mendiane = map[pos.y][pos.x].mendiane.quantity;
    int phiras = map[pos.y][pos.x].phiras.quantity;
    int thystame = map[pos.y][pos.x].thystame.quantity;
    int nb_player = get_nb_players_elev_on_tile(elev->elevation,
    elev->elevation.pos, head);

    if (nb_player >= requir.req_player && linemate >= requir.req_linemate
    && deraumere >= requir.req_deraumere && sibur >= requir.req_sibur
    && mendiane >= requir.req_mendiane && phiras >= requir.req_phiras
    && thystame >= requir.req_thystame)
        return true;
    return false;
}

void elevate_player(node_t *elevation, data_t *data)
{
    if (can_elevate_after(elevation, data->map, data->clients)) {
        remove_item_from_tile(elevation->elevation.level,
        &data->map[elevation->elevation.pos.y][elevation->elevation.pos.x]);
        for (int i = 0; i < elevation->elevation.nb_players; i++)
            success_elevate(data->clients, elevation->elevation.player_fds[i],
            data->graphic_fd);
        fmt_player_end_incantation(data->graphic_fd, elevation->elevation.pos,
        true);
    } else {
        for (int i = 0; i < elevation->elevation.nb_players; i++)
            failure_elevate(data->clients, elevation->elevation.player_fds[i]);
        fmt_player_end_incantation(data->graphic_fd, elevation->elevation.pos,
        false);
    }
    for (int i = 0; i < elevation->elevation.nb_players; i++)
        done_elevate(data->clients, elevation->elevation.player_fds[i]);
}

void elevate_met_prereq_players(data_t *data, pos_t pos, int lvl)
{
    node_t *current = data->clients;
    node_t *new = add_elevation_node(&data->elevation);

    while (current != NULL) {
        if (is_ai_player(current->client)
        && is_player_on_pos(current->client, pos)
        && lvl == current->client.level && !current->client.is_elevating) {
            dprintf(current->client.fd, "Elevation underway\n");
            new->elevation.pos = pos;
            new->elevation.level = lvl;
            current->client.is_elevating = true;
            new->elevation.player_fds[new->elevation.nb_players] =
            current->client.fd;
            new->elevation.nb_players++;
            current->client.timer = 0;
        }
        current = current->next;
    }
}
