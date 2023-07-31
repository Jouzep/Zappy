/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** winning
*/

#include "server.h"
#include "game_macro.h"

bool check_each_team(data_t *data, int index, team_t team)
{
    node_t *current = data->clients;
    int count = 0;

    while (current != NULL) {
        if (is_ai_player(current->client)
        && strcmp(current->client.team->name, team.name) == 0
        && current->client.level >= MAX_LEVEL)
            count++;
        current = current->next;
    }
    if (count >= PLAYER_TO_WIN) {
        data->winner_team_index = index;
        data->is_game_running = false;
        return true;
    }
    return false;
}

void check_winning_team(data_t *data)
{
    for (int i = 0; i < data->nb_teams; i++) {
        if (check_each_team(data, i, data->teams[i]))
            break;
    }
}
