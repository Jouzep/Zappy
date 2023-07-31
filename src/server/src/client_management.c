/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** client_management
*/

#include "server.h"

static void add_client(node_t **clients, int client_fd)
{
    node_t *new = add_client_node(clients);
    new->client.fd = client_fd;
}

void accept_client_to_server(server_t *server)
{
    struct sockaddr_in client;
    socklen_t len = sizeof(client);
    int client_fd = accept(server->addrs.socket_fd,
    (struct sockaddr *) &client, &len);

    if (client_fd >= 0) {
        printf("Connection from %s:%d\n", inet_ntoa(client.sin_addr),
        client.sin_port);
        add_client(&server->data.clients, client_fd);
        dprintf(client_fd, "Welcome\n");
    }
}
