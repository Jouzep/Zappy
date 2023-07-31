/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** init_commands
*/

#include "server.h"

static void init_ai_commands(server_t *server)
{
    server->ai_cmd[CMD_FORWARD] = ai_cmd_forward;
    server->ai_cmd[CMD_RIGHT] = ai_cmd_right;
    server->ai_cmd[CMD_LEFT] = ai_cmd_left;
    server->ai_cmd[CMD_LOOK] = ai_cmd_look;
    server->ai_cmd[CMD_INV] = ai_cmd_inventory;
    server->ai_cmd[CMD_BROAD] = ai_cmd_broadcast;
    server->ai_cmd[CMD_CONN_NBR] = ai_cmd_team_unused_slot;
    server->ai_cmd[CMD_FORK] = ai_cmd_fork_player;
    server->ai_cmd[CMD_EJECT] = ai_cmd_eject;
    server->ai_cmd[CMD_TAKE] = ai_cmd_take_object;
    server->ai_cmd[CMD_SET] = ai_cmd_set_object;
    server->ai_cmd[CMD_INC] = ai_cmd_incantation;
}

void init_commands(server_t *server)
{
    server->gui_cmd[CMD_MSZ] = send_map_size;
    server->gui_cmd[CMD_BCT] = send_content_tile;
    server->gui_cmd[CMD_MCT] = send_content_map;
    server->gui_cmd[CMD_TNA] = send_teams_name;
    server->gui_cmd[CMD_PPO] = send_player_position;
    server->gui_cmd[CMD_PLV] = send_player_level;
    server->gui_cmd[CMD_PIN] = send_player_inventory;
    server->gui_cmd[CMD_SGT] = send_time_unit_request;
    server->gui_cmd[CMD_SST] = send_time_unit_modif;
    init_ai_commands(server);
}
