/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** read_client
*/

#include "server.h"
#include "game_macro.h"
#include "macro.h"

void disconnect_player(data_t *data, node_t *client)
{
    printf("client %i has disconnected\n", client->client.fd);
    if (client->client.team != NULL) {
        client->client.team->clients_nbr++;
        client->client.team = NULL;
    }
    if (client->client.is_conn && !client->client.is_graphic
    && data->graphic_fd != UNDEFINED)
        fmt_player_death(data->graphic_fd, client->client);
    if (client->client.is_graphic)
        data->graphic_fd = UNDEFINED;
    close(client->client.fd);
    remove_client_node(&data->clients, client->client.fd);
}

void match_behavior(char *buffer, node_t *client, server_t *server)
{
    if (check_buffer_format(buffer)) {
        if (buffer == NULL) {
            dprintf(client->client.fd, "ko\n");
            return;
        }
        if (do_graphic_communication(buffer, client, server) == SUCCESS)
            return;
        if (do_ai_communication(buffer, client, server) == SUCCESS)
            return;
        dprintf(client->client.fd, "ko\n");
    }
}

void read_from_client(server_t *server, node_t *client)
{
    char buffer[1024];
    size_t bytes = 0;

    bytes = read(client->client.fd, buffer, 1024);
    if (bytes > 0) {
        buffer[bytes] = '\0';
        match_behavior(buffer, client, server);
        memset(buffer, 0, sizeof(buffer));
    } else {
        disconnect_player(&server->data, client);
    }
}
