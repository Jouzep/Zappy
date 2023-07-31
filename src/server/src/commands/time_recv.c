/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** time_recv
*/

#include "server.h"
#include "macro.h"

void send_time_unit_request(int fd, data_t *data,
char *params __attribute__((unused)))
{
    fmt_tm_request(fd, data->freq);
}

static int get_right_params(char *params, int *nbr)
{
    if (params == NULL || !can_convert_to_int(params)) {
        return FAILURE;
    }
    (*nbr) = atoi(params);
    if ((*nbr) < 2 || (*nbr) > 10000)
        return FAILURE;
    return SUCCESS;
}

void send_time_unit_modif(int fd, data_t *data, char *params)
{
    int nbr = 0;

    if (get_right_params(params, &nbr) == FAILURE) {
        fmt_cmd_parameter(fd);
        return;
    }
    data->freq = nbr;
    data->w_clock.timer_spec.it_interval.tv_nsec =
    sec_to_nanosec(1.0f / (double) data->freq);
    if (timerfd_settime(data->w_clock.tfd, 0, &data->w_clock.timer_spec,
    NULL) == -1)
        return;
    fmt_tm_modification(fd, data->freq);
}
