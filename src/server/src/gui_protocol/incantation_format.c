/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** incantation_format
*/

#include "server.h"
#include "macro.h"

void fmt_player_start_incantation(int fd, client_t player)
{
    if (fd != UNDEFINED)
        dprintf(fd, "pic %i %i %i %i\n", player.pos.x, player.pos.y,
        player.level, player.fd);
}

void fmt_player_end_incantation(int fd, pos_t pos, bool incante_res)
{
    if (fd != UNDEFINED)
        dprintf(fd, "pie %i %i %i\n", pos.x, pos.y, incante_res);
}
