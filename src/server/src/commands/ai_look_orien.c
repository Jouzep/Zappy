/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** ai_look_orien
*/

#include "server.h"

void look_north(int index, pos_t pos, data_t *data, char **msg)
{
    for (int y = 0; y < index; y++)
        check_presence_on_tile(get_correct_tile(data->map, pos.x - (y + 1),
        pos.y + index, *data), data->clients, msg);
    check_presence_on_tile(get_correct_tile(data->map, pos.x, pos.y + index,
    *data), data->clients, msg);
    for (int y = 0; y < index; y++)
        check_presence_on_tile(get_correct_tile(data->map, pos.x + (y + 1),
        pos.y + index, *data), data->clients, msg);
}

void look_east(int index, pos_t pos, data_t *data, char **msg)
{
    for (int y = 0; y < index; y++)
        check_presence_on_tile(get_correct_tile(data->map, pos.x + index,
        pos.y - (y + 1), *data), data->clients, msg);
    check_presence_on_tile(get_correct_tile(data->map, pos.x + index, pos.y,
    *data), data->clients, msg);
    for (int y = 0; y < index; y++)
        check_presence_on_tile(get_correct_tile(data->map, pos.x + index,
        pos.y + (y + 1), *data), data->clients, msg);
}

void look_south(int index, pos_t pos, data_t *data, char **msg)
{
    for (int y = 0; y < index; y++)
        check_presence_on_tile(get_correct_tile(data->map, pos.x + (y + 1),
        pos.y - index, *data), data->clients, msg);
    check_presence_on_tile(get_correct_tile(data->map, pos.x, pos.y - index,
    *data), data->clients, msg);
    for (int y = 0; y < index; y++)
        check_presence_on_tile(get_correct_tile(data->map, pos.x - (y + 1),
        pos.y - index, *data), data->clients, msg);
}

void look_west(int index, pos_t pos, data_t *data, char **msg)
{
    for (int y = 0; y < index; y++)
        check_presence_on_tile(get_correct_tile(data->map, pos.x - index,
        pos.y - (y + 1), *data), data->clients, msg);
    check_presence_on_tile(get_correct_tile(data->map, pos.x - index, pos.y,
    *data), data->clients, msg);
    for (int y = 0; y < index; y++)
        check_presence_on_tile(get_correct_tile(data->map, pos.x - index,
        pos.y + (y + 1), *data), data->clients, msg);
}

void match_direction(client_t player, data_t *data, char **msg)
{
    pos_t pos = player.pos;

    for (int i = 0; i < player.level + 1; i++) {
        switch (player.orientation) {
            case NORTH:
                look_north(i, pos, data, msg);
                break;
            case EAST:
                look_east(i, pos, data, msg);
                break;
            case SOUTH:
                look_south(i, pos, data, msg);
                break;
            case WEST:
                look_west(i, pos, data, msg);
                break;
        }
    }
}
