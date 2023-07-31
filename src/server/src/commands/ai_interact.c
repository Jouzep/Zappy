/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** ai_interact
*/

#include "server.h"

static void take_response(pos_t pos, node_t *client, data_t *data,
resource_t tile)
{
    fmt_player_collecting(data->graphic_fd, client->client, tile);
    fmt_player_inv(data->graphic_fd, client->client);
    fmt_content_of_tile(data->graphic_fd, data->map[pos.y][pos.x]);
    dprintf(client->client.fd, "ok\n");
}

void ai_cmd_take_object(node_t *client, data_t *data, char **params)
{
    resource_t *tile_res = NULL;
    resource_t *inv_res = NULL;
    pos_t pos;

    if (params[0] == NULL) {
        dprintf(client->client.fd, "ko\n");
    } else {
        pos = client->client.pos;
        tile_res = get_resource_by_name_on_tile(params[0],
        &data->map[pos.y][pos.x]);
        inv_res = get_resource_by_name_in_inventory(params[0],
        &client->client.inventory);
        if ((tile_res != NULL && inv_res != NULL) && tile_res->quantity > 0) {
            fmt_content_of_tile(data->graphic_fd, data->map[pos.y][pos.x]);
            tile_res->quantity--;
            inv_res->quantity++;
            take_response(pos, client, data, *tile_res);
        } else
            dprintf(client->client.fd, "ko\n");
    }
}

static void set_response(pos_t pos, node_t *client, data_t *data,
resource_t resource)
{
    fmt_player_dropping(data->graphic_fd, client->client, resource);
    fmt_player_inv(data->graphic_fd, client->client);
    fmt_content_of_tile(data->graphic_fd, data->map[pos.y][pos.x]);
    dprintf(client->client.fd, "ok\n");
}

void ai_cmd_set_object(node_t *client, data_t *data, char **params)
{
    resource_t *tile_res = NULL;
    resource_t *inv_res = NULL;
    pos_t pos;

    if (params[0] == NULL) {
        dprintf(client->client.fd, "ko\n");
    } else {
        pos = client->client.pos;
        tile_res = get_resource_by_name_on_tile(params[0],
        &data->map[pos.y][pos.x]);
        inv_res = get_resource_by_name_in_inventory(params[0],
        &client->client.inventory);
        if (tile_res != NULL && inv_res != NULL && inv_res->quantity > 0) {
            inv_res->quantity--;
            tile_res->quantity++;
            set_response(pos, client, data, *inv_res);
        } else {
            dprintf(client->client.fd, "ko\n");
        }
    }
}

void ai_cmd_incantation(node_t *client, data_t *data,
char **params __attribute__((unused)))
{
    if (can_elevate(client, data->clients, data->map)
    && client->client.level < MAX_LEVEL) {
        elevate_met_prereq_players(data, client->client.pos,
        client->client.level);
        fmt_player_start_incantation(data->graphic_fd, client->client);
    } else {
        dprintf(client->client.fd, "ko\n");
    }
}
