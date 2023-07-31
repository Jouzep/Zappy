/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** ai_broadcast_traj
*/

#include "server.h"
#include <math.h>

double calc_distance(pos_t src, pos_t dest)
{
    return sqrt(pow(dest.x - src.x, 2) + pow(dest.y - src.y, 2));
}

int get_min_at_index(double *list, int size)
{
    double save = list[0];
    int index = 0;

    for (int i = 1; i < size; i++) {
        if (list[i] == -1.0)
            continue;
        if (list[i] < save) {
            save = list[i];
            index = i;
        }
    }
    return index;
}

double get_distance(pos_t src, pos_t dest_ori, pos_t dest_side, pos_t delim)
{
    cross_map_border(&dest_side.x, &dest_side.y, delim.x, delim.y);
    if (dest_ori.x == dest_side.x && dest_ori.y == dest_side.y)
        return -1.0;
    return calc_distance(src, dest_side);
}

int change_with_orien(int index, int orien)
{
    int res = broadcast_base[index];

    for (int i = 0; i < orien - 1; i++) {
        if (res + 2 >= 8)
            res = 0;
        res += 2;
    }
    return res;
}

int get_sound_trajectory(pos_t src, pos_t dest, int orien, pos_t delim)
{
    double res[9];
    int count = 0;

    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            res[count] = get_distance(src, dest,
            (pos_t) {(dest.x - 1 + x), (dest.y - 1 + y)}, delim);
            count++;
        }
    }
    return change_with_orien(get_min_at_index(res, 9), orien);
}
