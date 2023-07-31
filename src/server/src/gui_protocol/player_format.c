/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** player_format
*/

#include "server.h"
#include "macro.h"

void fmt_conn_new_player(int fd, client_t player)
{
    if (fd != UNDEFINED)
        dprintf(fd, "pnw %i %i %i %i %i %s\n", player.fd, player.pos.x,
        player.pos.y, player.orientation, player.level, player.team->name);
}

void fmt_player_pos(int fd, client_t player)
{
    if (fd != UNDEFINED)
        dprintf(fd, "ppo %i %i %i %i\n", player.fd, player.pos.x, player.pos.y,
        player.orientation);
}

void fmt_player_lvl(int fd, client_t player)
{
    if (fd != UNDEFINED)
        dprintf(fd, "plv %i %i\n", player.fd, player.level);
}

void fmt_player_inv(int fd, client_t player)
{
    if (fd != UNDEFINED)
        dprintf(fd, "pin %i %i %i %i %i %i %i %i %i %i\n", player.fd,
        player.pos.x, player.pos.y, player.inventory.food.quantity,
        player.inventory.linemate.quantity,
        player.inventory.deraumere.quantity, player.inventory.sibur.quantity,
        player.inventory.mendiane.quantity, player.inventory.phiras.quantity,
        player.inventory.thystame.quantity);
}

void fmt_player_death(int fd, client_t player)
{
    if (fd != UNDEFINED)
        dprintf(fd, "pdi %i\n", player.fd);
}
