##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-vincent.shao
## File description:
## Makefile
##

PATH_TO_ROOT	=	../..

MV	=	mv

SRC	=	$(addprefix src/, \
		tools.c									\
		server.c								\
		shutdown.c								\
		client_management.c						\
		read_client.c							\
		buffer_management.c						\
		exec_cmd.c								\
\
		$(addprefix option/,    				\
		get_options.c							\
		set_options.c							)\
\
		$(addprefix world/,    					\
		refill_resources.c						\
		eat_food.c								\
		winning.c								\
		world_clock.c							)\
\
		$(addprefix linked_list_utils/,    		\
		client_linked_list.c					\
		add_client_list.c						\
		remove_client_list.c					\
		add_elevation_list.c					\
		remove_elevation_list.c					\
		egg_linked_list.c						)\
\
		$(addprefix init/,    					\
		init_server.c							\
		init_game.c								\
		init.c									\
		init_map.c								\
		init_commands.c							)\
\
		$(addprefix memory_handling/,    		\
		global_free.c							\
		free_server.c							\
		free_game.c								)\
\
		$(addprefix utils/,    					\
		map_utils.c								\
		my_strcat.c								\
		convertion.c							\
		nb_player.c								\
		player_utils.c							)\
\
		$(addprefix gui_protocol/,    			\
		map_format.c							\
		egg_format.c							\
		incantation_format.c					\
		misc_format.c							\
		team_format.c							\
		player_ext_format.c						\
		time_format.c							\
		player_format.c							)\
\
		$(addprefix commands/,    				\
		ai_first_connect.c						\
		ai_communication.c						\
		graphic_first_connect.c					\
		graphic_communication.c					\
		map_recv.c								\
		player_recv.c							\
		time_recv.c								\
		command_tools.c							\
		ai_action.c								\
		ai_info.c								\
		ai_interact.c							\
		ai_incantation.c						\
		ai_incantation_status.c					\
		ai_look.c								\
		ai_look_orien.c							\
		ai_broadcast_traj.c						\
		ai_movement.c							))

MAIN_SRC	=	src/main.c

MAIN_OBJ	=	$(MAIN_SRC:.c=.o)

OBJ	=	$(SRC:.c=.o)

NAME	=	zappy_server

TEST_NAME	=	unit_tests

TEST_FILE	=	tests/test_server.c

CPPFLAGS	=	-I./include

CFLAGS	=	-Wall -Wextra

LDFLAGS	=	-luuid -lm

all: $(NAME)

# Add main to obj for real compilation
$(NAME): $(OBJ) $(MAIN_OBJ)
	$(CC) $(OBJ) $(MAIN_OBJ) -o $(PATH_TO_ROOT)/$(NAME) $(LDFLAGS)

tests_run: LDFLAGS += -lcriterion --coverage
tests_run:
	$(CC) $(SRC) $(TEST_FILE) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $(TEST_NAME)
	./${TEST_NAME}
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

clean:
	$(RM) -f $(MAIN_OBJ)
	$(RM) -f $(OBJ)
	$(RM) *.gcda
	$(RM) *.gcno

fclean: clean
	$(RM) $(PATH_TO_ROOT)/$(NAME)
	$(RM) $(TEST_NAME)

re: fclean all

debug: CPPFLAGS += -g3
debug: re

.PHONY: all tests_run clean fclean re debug
