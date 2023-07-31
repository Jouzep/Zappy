/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** set_options
*/

#include "macro.h"
#include "server.h"

void set_non_set_info(info_t *info)
{
    info->port = -1;
    info->width = -1;
    info->height = -1;
    info->clients_nb = -1;
    info->freq = -1;
    info->teams_name = NULL;
}

int check_all_info_set(info_t info)
{
    if (info.port == -1 || info.width == -1 || info.height == -1
        || info.clients_nb == -1 || info.freq == -1 || info.teams_name == NULL)
        return write_error("All the option needs to be set : -help to display \
help message", ARG_ERROR_LABEL, FAILURE);
    if (info.port < 1 || info.port > 65535)
        return write_error("-p option only accepts integer values between 0 \
and 65535", ARG_ERROR_LABEL, FAILURE);
    if (info.width < 10 || info.width > 30)
        return write_error("-x option only accepts integer values between 10 \
and 30", ARG_ERROR_LABEL, FAILURE);
    if (info.height < 10 || info.height > 30)
        return write_error("-y option only accepts integer values between 10 \
and 30", ARG_ERROR_LABEL, FAILURE);
    if (info.clients_nb < 1)
        return write_error("-c option only accepts integer values greater or \
equal to 1", ARG_ERROR_LABEL, FAILURE);
    if (info.freq < 2 || info.freq > 10000)
        return write_error("-f option only accepts integer values between 2 \
and 10000", ARG_ERROR_LABEL, FAILURE);
    return SUCCESS;
}

int set_number_arg(int *opt)
{
    if (*opt != -1)
        return write_error("Cannot set the same option", ARG_ERROR_LABEL,
        FAILURE);
    if (!can_convert_to_int(optarg))
        return write_error("Cannot convert port to number", ARG_ERROR_LABEL,
        FAILURE);
    *opt = atoi(optarg);
    return SUCCESS;
}

int set_teams_name(const int ac, char *const *av, info_t *info)
{
    int count = ac - optind + 1;
    int sub = 0;

    for (int i = 0; i < count; i++) {
        sub++;
        if (av[optind + i] == NULL || av[optind + i][0] == '-')
            break;
    }
    info->teams_name = malloc(sizeof(char*) * (sub + 1));
    if (info->teams_name == NULL)
        return FAILURE;
    for (int i = 0; i < count; i++) {
        info->teams_name[i] = strdup(av[optind + i - 1]);
        if (av[optind + i] == NULL || av[optind + i][0] == '-')
            break;
    }
    info->teams_name[sub] = NULL;
    info->nb_teams = sub;
    return SUCCESS;
}
