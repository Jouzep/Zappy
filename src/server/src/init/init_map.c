/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** init_map
*/

#include "server.h"
#include "macro.h"

static resource_t set_resource_quantity(int width, int height, float density)
{
    resource_t resource;

    resource.id = 0;
    resource.density = density;
    resource.quantity = width * height * resource.density;
    return resource;
}

void set_rand_resource_in_tiles(data_t *data, inventory_t resources)
{
    for (int i = 0; i < resources.linemate.quantity; i++)
        data->map[rand_nbr(0, data->height - 1)][rand_nbr(0, data->width - 1)]
        .linemate.quantity++;
    for (int i = 0; i < resources.deraumere.quantity; i++)
        data->map[rand_nbr(0, data->height - 1)][rand_nbr(0, data->width - 1)]
        .deraumere.quantity++;
    for (int i = 0; i < resources.sibur.quantity; i++)
        data->map[rand_nbr(0, data->height - 1)][rand_nbr(0, data->width - 1)]
        .sibur.quantity++;
    for (int i = 0; i < resources.mendiane.quantity; i++)
        data->map[rand_nbr(0, data->height - 1)][rand_nbr(0, data->width - 1)]
        .mendiane.quantity++;
    for (int i = 0; i < resources.phiras.quantity; i++)
        data->map[rand_nbr(0, data->height - 1)][rand_nbr(0, data->width - 1)]
        .phiras.quantity++;
    for (int i = 0; i < resources.thystame.quantity; i++)
        data->map[rand_nbr(0, data->height - 1)][rand_nbr(0, data->width - 1)]
        .thystame.quantity++;
}

void resources_distribution(data_t *data)
{
    data->max_res.food = set_resource_quantity(data->width, data->height,
    FOOD_DENSITY);
    data->max_res.linemate = set_resource_quantity(data->width, data->height,
    LINEMATE_DENSITY);
    data->max_res.deraumere = set_resource_quantity(data->width, data->height,
    DERAUMERE_DENSITY);
    data->max_res.sibur = set_resource_quantity(data->width, data->height,
    SIBUR_DENSITY);
    data->max_res.mendiane = set_resource_quantity(data->width, data->height,
    MENDIANE_DENSITY);
    data->max_res.phiras = set_resource_quantity(data->width, data->height,
    PHIRAS_DENSITY);
    data->max_res.thystame = set_resource_quantity(data->width, data->height,
    THYSTAME_DENSITY);
    for (int i = 0; i < data->max_res.food.quantity; i++)
        data->map[rand_nbr(0, data->height - 1)][rand_nbr(0, data->width - 1)]
        .food.quantity++;
    set_rand_resource_in_tiles(data, data->max_res);
}

static void set_default_resources_on_tile(tile_t *tile, pos_t pos)
{
    tile->pos = pos;
    tile->food = (resource_t) {FOOD_ID, FOOD_DENSITY, 0};
    tile->linemate = (resource_t) {LINEMATE_ID, LINEMATE_DENSITY, 0};
    tile->deraumere = (resource_t) {DERAUMERE_ID, DERAUMERE_DENSITY, 0};
    tile->sibur = (resource_t) {SIBUR_ID, SIBUR_DENSITY, 0};
    tile->mendiane = (resource_t) {MENDIANE_ID, MENDIANE_DENSITY, 0};
    tile->phiras = (resource_t) {PHIRAS_ID, PHIRAS_DENSITY, 0};
    tile->thystame = (resource_t) {THYSTAME_ID, THYSTAME_DENSITY, 0};
}

int init_map(int width, int height, data_t *data)
{
    data->map = malloc(sizeof(tile_t*) * (height + 1));
    if (data->map == NULL)
        return FAILURE;
    for (int i = 0; i < height; i++) {
        data->map[i] = malloc(sizeof(tile_t) * width);
        if (data->map[i] == NULL)
            return FAILURE;
        for (int y = 0; y < width; y++) {
                set_default_resources_on_tile(&data->map[i][y],
                (pos_t) {y, i});
        }
    }
    data->map[height] = NULL;
    resources_distribution(data);
    return SUCCESS;
}
