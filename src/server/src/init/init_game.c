/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** init_game
*/

#include "server.h"
#include "macro.h"
#include "game_macro.h"

int init_world_clock(data_t *data, int freq)
{
    data->w_clock.tfd = timerfd_create(CLOCK_REALTIME, 0);
    if (data->w_clock.tfd == -1)
        return FAILURE;
    data->w_clock.timer_spec.it_value.tv_sec = 1;
    data->w_clock.timer_spec.it_value.tv_nsec = 0;
    data->w_clock.timer_spec.it_interval.tv_sec = 0;
    data->w_clock.timer_spec.it_interval.tv_nsec =
    sec_to_nanosec(1.0f / (double) freq);
    if (timerfd_settime(data->w_clock.tfd, 0, &data->w_clock.timer_spec,
    NULL) == -1)
        return FAILURE;
    return SUCCESS;
}

int init_game(data_t *data, info_t info)
{
    data->freq = info.freq;
    data->width = info.width;
    data->height = info.height;
    data->graphic_fd = UNDEFINED;
    data->egg = NULL;
    data->elevation = NULL;
    data->nb_elevation = 0;
    data->food_eat_tick = 0;
    data->food_refill_res = 0;
    data->is_game_running = true;
    if (init_map(info.width, info.height, data) == FAILURE)
        return FAILURE;
    if (init_world_clock(data, data->freq) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
