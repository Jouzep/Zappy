/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** nb_player
*/

#include "server.h"

int get_nb_players_on_tile(pos_t pos, node_t *head)
{
    node_t *current = head;
    int count = 0;

    while (current != NULL) {
        if (is_ai_player(current->client) && pos.x == current->client.pos.x
        && pos.y == current->client.pos.y) {
            count++;
        }
        current = current->next;
    }
    return count;
}

int get_nb_players_on_tile_w_lvl(pos_t pos, node_t *head, int lvl)
{
    node_t *current = head;
    int count = 0;

    while (current != NULL) {
        if (is_ai_player(current->client) &&
        is_player_on_pos(current->client, pos)
        && lvl == current->client.level && !current->client.is_elevating) {
            count++;
        }
        current = current->next;
    }
    return count;
}

int do_increase_count(node_t *current, int fd, pos_t pos, int lvl)
{
    if (current->client.fd == fd
        && is_ai_player(current->client)
        && is_player_on_pos(current->client, pos)
        && current->client.level == lvl)
            return 1;
    return 0;
}

int get_nb_players_elev_on_tile(elevation_t elev, pos_t pos, node_t *head)
{
    node_t *current = head;
    int count = 0;

    while (current != NULL) {
        for (int i = 0; i < elev.nb_players; i++) {
            count += do_increase_count(current, elev.player_fds[i], pos,
            elev.level);
        }
        current = current->next;
    }
    return count;
}

int get_nb_team_players_on_tile(pos_t pos, node_t *head, char *team)
{
    node_t *current = head;
    int count = 0;

    while (current != NULL) {
        if (is_ai_player(current->client) && pos.x == current->client.pos.x
        && pos.y == current->client.pos.y
        && strcmp(team, current->client.team->name) == 0) {
            count++;
        }
        current = current->next;
    }
    return count;
}
