/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** shutdown
*/

#include "server.h"

int catch_shutdown(server_t server)
{
    if (FD_ISSET(server.sfd, &server.addrs.rfds)) {
        read(server.sfd, &server.fdsi, sizeof(struct signalfd_siginfo));
        if (server.fdsi.ssi_signo == SIGINT) {
            global_free(server);
            printf("Shutdown catched !\n");
            return 1;
        }
    }
    return 0;
}
