/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** test_server
*/

#include <criterion/criterion.h>
#include "server.h"

Test(tools, test_can_convert_to_int)
{
    cr_assert_eq(can_convert_to_int("1"), 1);
}

Test(tools, test_rand_nbr)
{
    cr_assert_eq(rand_nbr(1, 1), 1);
}

Test(Look, test_look_cmd_cross_border)
{
    info_t info;
    data_t data;

    info.freq = 2;
    info.width = 10;
    info.height = 10;
    init_game(&data, info);

    int x = 10;
    int y = 11;

    cross_map_border(&x, &y, data.width, data.height);
    cr_assert_eq(x, 0);
    cr_assert_eq(y, 1);

    x = -1;
    y = -2;
    cross_map_border(&x, &y, data.width, data.height);
    cr_assert_eq(x, 9);
    cr_expect_eq(y, 8);
}

Test(Orientation, test_opposite_direction)
{
    cr_assert_eq(get_opposite_direction(NORTH), SOUTH);
    cr_assert_eq(get_opposite_direction(SOUTH), NORTH);
    cr_assert_eq(get_opposite_direction(EAST), WEST);
    cr_assert_eq(get_opposite_direction(WEST), EAST);
}