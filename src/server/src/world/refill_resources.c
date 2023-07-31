/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** world_refill_clock
*/

#include "server.h"
#include "game_macro.h"

void check_resources_on_tiles(data_t *data, inventory_t *inv)
{
    for (int y = 0; y < data->height; y++) {
        for (int x = 0; x < data->width; x++) {
            inv->linemate.quantity -= data->map[y][x].linemate.quantity;
            inv->deraumere.quantity -= data->map[y][x].deraumere.quantity;
            inv->sibur.quantity -= data->map[y][x].sibur.quantity;
            inv->mendiane.quantity -= data->map[y][x].mendiane.quantity;
            inv->phiras.quantity -= data->map[y][x].phiras.quantity;
            inv->thystame.quantity -= data->map[y][x].thystame.quantity;
        }
    }
}

static int nb_ai_player(node_t *head)
{
    node_t *current = head;
    int res = 0;

    while (current != NULL) {
        if (is_ai_player(current->client))
            res++;
        current = current->next;
    }
    return res;
}

static void refill_foods_evenly(data_t *data, int max_quantity)
{
    int rand_x = 0;
    int rand_y = 0;

    for (int i = 0; i < max_quantity; i++) {
        rand_x = rand_nbr(0, data->width - 1);
        rand_y = rand_nbr(0, data->height - 1);
        if (data->map[rand_y][rand_x].food.quantity < 20)
            data->map[rand_y][rand_x]
            .food.quantity++;
    }
}

void get_resources_on_map(data_t *data)
{
    inventory_t resources;
    int nb = nb_ai_player(data->clients);

    resources = data->max_res;
    refill_foods_evenly(data, FOOD_REFILL_TICK_AMPL + (FOOD_REFILL_TICK * nb));
    check_resources_on_tiles(data, &resources);
    set_rand_resource_in_tiles(data, resources);
}

void refill_resources(data_t *data)
{
    if (data->food_refill_res >= COOLDOWN_REFILL) {
        get_resources_on_map(data);
        data->food_refill_res = 0;
    }
}
