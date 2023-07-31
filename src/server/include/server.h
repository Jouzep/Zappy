/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** server
*/

#ifndef SERVER_H_
    #define SERVER_H_
    #define MAX_CONNECTIONS 100
    #include "game_macro.h"
    #include <stdio.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <sys/select.h>
    #include <signal.h>
    #include <sys/signalfd.h>
    #include <uuid/uuid.h>
    #include <time.h>
    #include <stdint.h>
    #include <sys/timerfd.h>
    #include "server_structs.h"

/**
 * @brief Gui commands library for his array of pointer on function
 *
 * @return const char*[]
 */
static const char *GUI_CMD_LIB[] __attribute__((unused)) = {
    "msz", "bct", "mct", "tna", "ppo", "plv", "pin", "sgt", "sst", NULL
};


/**
 * @brief Ai commands library for his array of pointer on function
 *
 * @return const char*[]
 */
static const char *AI_CMD_LIB[] __attribute__((unused)) = {
    "Forward", "Right", "Left", "Look", "Inventory", "Broadcast",
    "Connect_nbr", "Fork", "Eject", "Take", "Set", "Incantation", NULL
};

static const int AI_ACTION_CD[] __attribute__((unused)) = {
    COOLDOWN_FORWARD, COOLDOWN_RIGHT, COOLDOWN_LEFT, COOLDOWN_LOOK,
    COOLDOWN_INVENTORY, COOLDOWN_BROADCAST, 0, COOLDOWN_FORK, COOLDOWN_EJECT,
    COOLDOWN_TAKE, COOLDOWN_SET, 0
};

static const char *RESOURCES_LIB[] __attribute__((unused)) = {
    FOOD_NAME, LINEMATE_NAME, DERAUMERE_NAME, SIBUR_NAME, MENDIANE_NAME,
    PHIRAS_NAME, THYSTAME_NAME, NULL
};

static const int broadcast_base[] __attribute__((unused)) = {
    2, 1, 8,
    3, 0, 7,
    4, 5, 6
};

typedef struct elevation_ritual_s {
    int req_player;
    int req_linemate;
    int req_deraumere;
    int req_sibur;
    int req_mendiane;
    int req_phiras;
    int req_thystame;
} elevation_ritual_t;

static const elevation_ritual_t elev_requir[] __attribute__((unused)) = {
    {1, 1, 0, 0, 0, 0, 0}, /* Level 1*/
    {2, 1, 1, 1, 0, 0, 0}, /* Level 2*/
    {2, 2, 0, 1, 0, 2, 0}, /* Level 3*/
    {4, 1, 1, 2, 0, 1, 0}, /* Level 4*/
    {4, 1, 2, 1, 3, 0, 0}, /* Level 5*/
    {6, 1, 2, 3, 0, 1, 0}, /* Level 6*/
    {6, 2, 2, 2, 2, 2, 1}  /* Level 7*/
};

/**
 * @brief Enumeration for the gui commands
 *
 */
enum gui_cmd_e {
    CMD_MSZ,
    CMD_BCT,
    CMD_MCT,
    CMD_TNA,
    CMD_PPO,
    CMD_PLV,
    CMD_PIN,
    CMD_SGT,
    CMD_SST
};

/**
 * @brief Enumeration for the ai commands
 *
 */
enum ai_cmd_e {
    CMD_FORWARD,
    CMD_RIGHT,
    CMD_LEFT,
    CMD_LOOK,
    CMD_INV,
    CMD_BROAD,
    CMD_CONN_NBR,
    CMD_FORK,
    CMD_EJECT,
    CMD_TAKE,
    CMD_SET,
    CMD_INC
};

/**
 * @brief Display the usage with the fd specification
 *
 * @param binary
 * @param fd
 */
void show_usage(const char *binary, int fd);

/**
 * @brief Fill the info_t struct with all the parameters
 *
 * @param ac
 * @param av
 * @param info
 * @return FAILURE(-1) if there are missing parameters, SUCCESS(0) instead
 */
int get_options(const int ac, char *const *av, info_t *info);

//** Buffer management *//

/**
 * @brief Check if the buffer is correctly formated, if so then return true and
 * reformate the buffer, else return false
 *
 * @param buffer
 * @return true
 * @return false
 */
bool check_buffer_format(char *buffer);

//** Tools **//

/**
 * @brief Write a message on the standart error, if a label is specified
 * (!= NULL) then print the label in front. return the expected return value
 *
 * @param message
 * @param label
 * @param ret_value
 * @return int
 */
int write_error(char *message, char *label, int ret_value);

/**
 * @brief Check if a string can be converted to int
 *
 * @param str
 * @return true
 * @return false
 */
bool can_convert_to_int(const char* str);

/**
 * @brief Get the index of an element in the lib with the str
 *
 * @param str
 * @param lib
 * @return int
 */
int get_cmd_pos(char *str, const char **lib);

/**
 * @brief Get the opposite direction
 *
 * @param direction
 * @return int
 */
int get_opposite_direction(int direction);

/**
 * @brief Elevation successful
 *
 * @param players
 * @param fd
 */
void success_elevate(node_t *players, int fd, int graph_fd);

/**
 * @brief Elevation failure
 *
 * @param players
 * @param fd
 */
void failure_elevate(node_t *players, int fd);

/**
 * @brief Set done elevation data
 *
 * @param players
 * @param fd
 */
void done_elevate(node_t *players, int fd);

/**
 * @brief Convert seconds to nano seconds
 *
 * @param seconds
 * @return uint64_t
 */
uint64_t sec_to_nanosec(double seconds);

/**
 * @brief Handle refill resources
 *
 * @param server
 */
void handle_world_refill_clock(server_t *server);

/**
 * @brief Refill the resources
 *
 * @param data
 */
void refill_resources(data_t *data);

/**
 * @brief Set the rand resource in tiles
 *
 * @param data
 * @param resources
 */
void set_rand_resource_in_tiles(data_t *data, inventory_t resources);

/**
 * @brief Generate random number with a minimum and a maximum
 *
 * @param min
 * @param max
 * @return int
 */
int rand_nbr(int min, int max);

/**
 * @brief Convert a string to an array of string
 *
 * @param buffer
 * @param sep
 * @return char**
 */
char **str_to_word_array(char *buffer, char *sep);

/**
 * @brief Do a strcat without needed to alloc memory before
 *
 * @param dest
 * @param src
 */
void my_strcat(char **dest, char *src);

//** Init **//

/**
 * @brief Init all the data related to the server
 *
 * @param server
 * @param port
 * @return int
 */
int init_server(server_t *server, int port);

/**
 * @brief Init all the data
 *
 * @param server
 * @param port
 * @return int
 */
int global_init(server_t *server, int port);

/**
 * @brief Init all the data related to the game
 *
 * @param data
 * @param info
 * @return int
 */
int init_game(data_t *data, info_t info);


/**
 * @brief Init the map
 *
 * @param width
 * @param height
 * @param data
 * @return int
 */
int init_map(int width, int height, data_t *data);

/**
 * @brief Init array of pointer on functions
 *
 * @param server
 */
void init_commands(server_t *server);

/**
 * @brief Launch the server
 *
 * @param server
 * @return int
 */
int run_server(server_t server);

/**
 * @brief Catch SIGINT signal, then free all the memory
 *
 * @param server
 * @return int
 */
int catch_shutdown(server_t server);

// Client management
void accept_client_to_server(server_t *server);
void read_from_client(server_t *server, node_t *client);

// Linked list utils
node_t *add_client_node(node_t **head);
node_t *add_egg_node(node_t **head);
node_t *add_elevation_node(node_t **head);
void print_client_list(node_t *head);
void remove_client_node(node_t **head, int fd);
void remove_elevation_node(node_t **head, uuid_t uuid);
node_t *get_client_node(node_t **head, int fd);
int get_linked_list_length(node_t *node);
void remove_egg_node(node_t **head, int id);

// Set options
int set_number_arg(int *opt);
int set_teams_name(const int ac, char *const *av, info_t *info);
void set_non_set_info(info_t *info);
int check_all_info_set(info_t info);

// Memory handling
void global_free(server_t server);
void free_server(server_t server);
void free_game(data_t data, int height);
/**
 * @brief Free any nodes
 *
 * @param head
 */
void free_node(node_t *head);

//** COMMANDS **//

// Graphic commands
int do_graphic_first_connect(char *buffer, node_t *client, data_t *data);
int do_graphic_communication(char *buffer, node_t *client, server_t *server);

// Ai commands
int do_ai_first_connect(char *buffer, node_t *client, data_t *data);
int do_ai_communication(char *buffer, node_t *client, server_t *server);

// Gui send commands
void send_map_size(int fd, data_t *data, char *params __attribute__((unused)));
void send_content_tile(int fd, data_t *data, char *params);
void send_content_map(int fd, data_t *data,
char *params __attribute__((unused)));
void send_teams_name(int fd, data_t *data,
char *params __attribute__((unused)));
void send_player_position(int fd, data_t *data, char *params);
void send_player_level(int fd, data_t *data, char *params);
void send_player_inventory(int fd, data_t *data, char *params);
void send_time_unit_request(int fd, data_t *data,
char *params __attribute__((unused)));
void send_time_unit_modif(int fd, data_t *data, char *params);

// Ai commands
void ai_cmd_forward(node_t *client, data_t *data,
char **params __attribute__((unused)));
void ai_cmd_right(node_t *client, data_t *data,
char **params __attribute__((unused)));
void ai_cmd_left(node_t *client, data_t *data,
char **params __attribute__((unused)));
void ai_cmd_look(node_t *client, data_t *data,
char **params __attribute__((unused)));
void ai_cmd_inventory(node_t *client, data_t *data __attribute__((unused)),
char **params __attribute__((unused)));
void ai_cmd_broadcast(node_t *client, data_t *data, char **params);
void ai_cmd_team_unused_slot(node_t *client, data_t *data,
char **params __attribute__((unused)));
void ai_cmd_fork_player(node_t *client, data_t *data,
char **params __attribute__((unused)));
void ai_cmd_eject(node_t *client, data_t *data,
char **params __attribute__((unused)));
void ai_cmd_take_object(node_t *client, data_t *data, char **params);
void ai_cmd_set_object(node_t *client, data_t *data, char **params);
void ai_cmd_incantation(node_t *client, data_t *data,
char **params __attribute__((unused)));

/**
 * @brief Get the sound trajectory for broadcast
 *
 * @param src
 * @param dest
 * @param orien
 * @return int
 */
int get_sound_trajectory(pos_t src, pos_t dest, int orien, pos_t delim);

/**
 * @brief Check prerequis for elevate and elevate all the players
 *
 * @param data
 * @param pos
 * @param lvl
 */
void elevate_met_prereq_players(data_t *data, pos_t pos, int lvl);

/**
 * @brief Check if the position cross the map, then set it back
 *
 * @param x
 * @param y
 * @param width
 * @param height
 */
void cross_map_border(int *x, int *y, int width, int height);

/**
 * @brief Get the correct tile
 *
 * @param map
 * @param x
 * @param y
 * @param data
 * @return tile_t
 */
tile_t get_correct_tile(tile_t **map, int x, int y, data_t data);

/**
 * @brief Disconnect player
 *
 * @param data
 * @param client
 */
void disconnect_player(data_t *data, node_t *client);

/**
 * @brief Handle the game's world clock
 *
 * @param server
 */
void handle_world_clock(server_t *server);

/**
 * @brief Check if the game ends
 *
 * @param data
 */
void check_winning_team(data_t *data);

/**
 * @brief Execute commands that is waiting
 *
 * @param current
 * @param server
 */
void execute_waiting_cmd(node_t *current, server_t *server);

/**
 * @brief Check what is present in tile
 *
 * @param tile
 * @param players
 * @param msg
 */
void check_presence_on_tile(tile_t tile, node_t *players, char **msg);

/**
 * @brief match the direction of the look
 *
 * @param player
 * @param data
 * @param msg
 */
void match_direction(client_t player, data_t *data, char **msg);

/**
 * @brief Check if the player on the tile can elevate
 *
 * @param client
 * @param map
 * @param head
 * @return true
 * @return false
 */
bool can_elevate(node_t *client, node_t *head, tile_t **map);

/**
 * @brief Check it can elevate after the elevation
 *
 * @param pos
 * @param lvl
 * @param head
 * @param map
 * @return true
 * @return false
 */
// bool can_elevate_after(pos_t pos, int lvl, node_t *head, tile_t **map);

/**
 * @brief Elevate the player
 *
 * @param elevation
 * @param data
 */
void elevate_player(node_t *elevation, data_t *data);

/**
 * @brief Eat food in world
 *
 * @param data
 */
void eat_food(data_t *data);

//** Utils **//

/**
 * @brief Get the number of players on tile
 *
 * @param pos
 * @param head
 * @return int
 */
int get_nb_players_on_tile(pos_t pos, node_t *head);

/**
 * @brief Get the number of players on tile with the same level and uuid
 *
 * @param pos
 * @param head
 * @param lvl
 * @param uuid
 * @return int
 */
int get_nb_players_on_tile_w_lvl_uuid(pos_t pos, node_t *head, int lvl,
uuid_t uuid);

/**
 * @brief Get the number of players on tile with the same level
 *
 * @param pos
 * @param head
 * @param lvl
 * @return int
 */
int get_nb_players_on_tile_w_lvl(pos_t pos, node_t *head, int lvl);

/**
 * @brief Get the nb players on tile that done elevating
 *
 * @param pos
 * @param head
 * @return int
 */
int get_nb_players_elev_on_tile(elevation_t elev, pos_t pos, node_t *head);

/**
 * @brief Get the nb of players on a tile that have the same team's name
 *
 * @param pos
 * @param head
 * @param team
 * @return int
 */
int get_nb_team_players_on_tile(pos_t pos, node_t *head, char *team);

/**
 * @brief Check if the concerned client is an ai client and its connected,
 * then its returning true else false
 *
 * @param player
 * @return true
 * @return false
 */
bool is_ai_player(client_t player);

/**
 * @brief Check if the concerned client is an ai client and its connected and is
 * in the corresponding position, then its returning true else false
 *
 * @param player
 * @return true
 * @return false
 */
bool is_player_on_pos(client_t player, pos_t pos);

/**
 * @brief Get a pointer of the resource by name in inventory, return NULL if
 * the resource are not found
 * @param name
 * @param inventory
 * @return resource_t*
 */
resource_t *get_resource_by_name_in_inventory(char *name,
inventory_t *inventory);

/**
 * @brief Get a pointer of the resource by name on a tile, return NULL if
 * the resource are not found
 * @param name
 * @param tile
 * @return resource_t*
 */
resource_t *get_resource_by_name_on_tile(char *name, tile_t *tile);

//** GUI PROTOCOL FORMATS **//

void fmt_player_egg_laying(int fd, client_t player);

void fmt_egg_laid(int fd, int egg_nb, client_t player, pos_t pos);

void fmt_egg_conn(int fd, int egg_nb);

void fmt_egg_death(int fd, int egg_nb);

void fmt_player_start_incantation(int fd, client_t player);

void fmt_player_end_incantation(int fd, pos_t pos, bool incante_res);

void fmt_map_size(int fd, int width, int height);

void fmt_content_of_tile(int fd, tile_t tile);

void fmt_content_of_map(int fd, tile_t **map, int width, int height);

void fmt_end_of_game(int fd, char *team_name);

void fmt_msg_from_server(int fd, char *msg);

void fmt_unknown_cmd(int fd);

void fmt_cmd_parameter(int fd);

void fmt_player_expulsion(int fd, client_t player);

void fmt_player_broadcast(int fd, client_t player, char *msg);

void fmt_player_dropping(int fd, client_t player, resource_t resource);

void fmt_player_collecting(int fd, client_t player, resource_t resource);

void fmt_conn_new_player(int fd, client_t player);

void fmt_player_pos(int fd, client_t player);

void fmt_player_lvl(int fd, client_t player);

void fmt_player_inv(int fd, client_t player);

void fmt_player_death(int fd, client_t player);

void fmt_name_of_teams(int fd, team_t *teams, int nb_teams);

void fmt_tm_request(int fd, int time);

void fmt_tm_modification(int fd, int time);

#endif /* !SERVER_H_ */
