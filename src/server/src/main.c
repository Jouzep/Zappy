/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** main
*/

#include "server.h"
#include "macro.h"

void show_usage(const char *binary, int fd)
{
    dprintf(fd, "USAGE:\t%s -p port -x width -y height -n name1 ", binary);
    dprintf(fd, "name2 ... -c clientsNb -f freq\n");
    dprintf(fd, "\tport\t\tis the port number\n");
    dprintf(fd, "\twidth\t\tis the width of the world\n");
    dprintf(fd, "\theight\t\tis the height of the world\n");
    dprintf(fd, "\tnameX\t\tis the name of the team X\n");
    dprintf(fd, "\tclientsNb\tis the number of authorized clients per team\n");
    dprintf(fd, "\tfreq\t\tis the reciprocal of time unit for ");
    dprintf(fd, "execution of actions\n");
}

int main(const int ac, char *const *av)
{
    server_t server;

    srand(time(NULL));
    if (ac == 2 && strcmp(av[1], "-help") == 0) {
        show_usage(av[0], STDOUT_FILENO);
        return MY_EXIT_SUCCESS;
    }
    if (get_options(ac, av, &server.info) == FAILURE)
        return MY_EXIT_FAILURE;
    if (global_init(&server, server.info.port) == FAILURE)
        return MY_EXIT_FAILURE;
    if (run_server(server) == FAILURE)
        return MY_EXIT_FAILURE;
    return MY_EXIT_SUCCESS;
}
