/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** map_recv
*/

#include "server.h"
#include "macro.h"

void send_map_size(int fd, data_t *data, char *params __attribute__((unused)))
{
    fmt_map_size(fd, data->width, data->height);
}

static int set_params(int *x, int *y, char *params)
{
    char *str_token = str_token = strtok(params, " ");
    if (str_token != NULL && can_convert_to_int(str_token)) {
        (*x) = atoi(str_token);
    } else {
        return FAILURE;
    }
    str_token = strtok(NULL, " ");
    if (str_token != NULL && can_convert_to_int(str_token)) {
        (*y) = atoi(str_token);
    } else {
        return FAILURE;
    }
    return SUCCESS;
}

void send_content_tile(int fd, data_t *data, char *params)
{
    int x = 0;
    int y = 0;

    if (params == NULL || set_params(&x, &y, params) == FAILURE) {
        fmt_cmd_parameter(fd);
    } else {
        if ((x >= 0 && x <= data->width - 1)
        && (y >= 0 && y <= data->height -1))
            fmt_content_of_tile(fd, data->map[y][x]);
        else
            fmt_cmd_parameter(fd);
    }
}

void send_content_map(int fd, data_t *data,
char *params __attribute__((unused)))
{
    fmt_content_of_map(fd, data->map, data->width, data->height);
}

void send_teams_name(int fd, data_t *data, char *params __attribute__((unused)))
{
    fmt_name_of_teams(fd, data->teams, data->nb_teams);
}
