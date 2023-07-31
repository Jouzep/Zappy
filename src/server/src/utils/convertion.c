/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** convertion
*/

#include <stdint.h>

uint64_t sec_to_nanosec(double seconds)
{
    return (uint64_t) (seconds * 1000000000.0);
}
