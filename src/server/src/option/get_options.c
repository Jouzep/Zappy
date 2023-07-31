/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** get_options
*/

#include "macro.h"
#include <stdio.h>
#include <unistd.h>
#include "server.h"

static void free_team(char **teams_name)
{
    if (teams_name == NULL)
        return;
    for (int i = 0; teams_name[i] != NULL; i++) {
        free(teams_name[i]);
    }
    free(teams_name);
}

static int get_option_result(int status, info_t info)
{
    if (status == FAILURE) {
        free_team(info.teams_name);
        return FAILURE;
    }
    if (check_all_info_set(info) == FAILURE) {
        free_team(info.teams_name);
        return FAILURE;
    }
    return SUCCESS;
}

static void process_option(int opt, int *status, info_t *info)
{
    switch (opt) {
        case 'p':
            if (set_number_arg(&info->port) == FAILURE)
                (*status) = FAILURE;
            break;
        case 'x':
            if (set_number_arg(&info->width) == FAILURE)
                (*status) = FAILURE;
            break;
        case 'y':
            if (set_number_arg(&info->height) == FAILURE)
                (*status) = FAILURE;
            break;
    }
}

static void process_option_extended(pos_t tuple, int *status, info_t *info,
char *const *av)
{
    switch (tuple.x) {
        case 'n':
            if (info->teams_name != NULL) {
                write_error("Cannot set the same option",
                ARG_ERROR_LABEL, FAILURE);
                (*status) = FAILURE;
            }
            if (set_teams_name(tuple.y, av, info) == FAILURE)
                (*status) = FAILURE;
            break;
        case 'c':
            if (set_number_arg(&info->clients_nb) == FAILURE)
                (*status) = FAILURE;
            break;
        case 'f':
            if (set_number_arg(&info->freq) == FAILURE)
                (*status) = FAILURE;
            break;
    }
}

int get_options(const int ac, char *const *av, info_t *info)
{
    int opt = 0;
    int status = SUCCESS;

    set_non_set_info(info);
    while (opt != -1 && status == SUCCESS) {
        opt = getopt(ac, av, "p:x:y:n:c:f:");
        if (opt == '?') {
            status = FAILURE;
            break;
        }
        process_option(opt, &status, info);
        process_option_extended((pos_t) {opt, ac}, &status, info, av);
    }
    return get_option_result(status, *info);
}
