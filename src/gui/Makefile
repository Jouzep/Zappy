##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-vincent.shao
## File description:
## Makefile
##

PATH_TO_ROOT	=	../..

MV	=	mv

MAP =	$(addprefix src/Map/,			\
			$(addprefix Ressource/,		\
				ARessource.cpp				\
				RessourceFactory.cpp		\
				Deraumere.cpp				\
				Linemate.cpp				\
				Mendiane.cpp				\
				Phiras.cpp					\
				Sibur.cpp					\
				Thystame.cpp				\
				Food.cpp					)\
			Player.cpp					\
			BroadCast.cpp					\
			Incantation.cpp					\
			Egg.cpp					\
			Team.cpp					\
			TimeUnit.cpp 				\
			Tile.cpp					\
			)

GRAPHIC =	$(addprefix src/Graphic/,		\
				Cube.cpp			\
				Shaders.cpp			\
				Raylib.cpp			\
				DrawMap.cpp			\
				DrawItems.cpp		\
				DrawEggs.cpp 		\
				DrawPlayer.cpp 		\
				DrawBroadCast.cpp 	\
				MyModel.cpp 		\
				Gameplay.cpp		\
				Menu.cpp		\
				Rectangle.cpp		\
				DrawText3d.cpp	\
				DrawScoreboard.cpp)

SRC	=	$(addprefix src/,				\
			Parser.cpp					\
			Error.cpp					\
			Gui.cpp						\
			$(addprefix Encapsulation/,	\
				Socket.cpp					\
				Select.cpp					)\
			$(addprefix Communication/,	\
				Data.cpp					\
				GameData.cpp			))

SRC += $(MAP)
SRC += $(GRAPHIC)

MAIN_SRC	=	src/main.cpp

MAIN_OBJ	=	$(MAIN_SRC:.cpp=.o)

OBJ	=	$(SRC:.cpp=.o)

NAME	=	zappy_gui

TEST_NAME	=	unit_tests

TEST_FILE	=	tests/test_gui.cpp

CPPFLAGS	+=	-I./include
CPPFLAGS	+=	-I./include/libs
CPPFLAGS	+=	-I./src
CPPFLAGS	+=	-I./src/Graphic
CPPFLAGS	+=	-I./src/Encapsulation
CPPFLAGS	+=	-I./src/Communication
CPPFLAGS	+=	-I./src/Map
CPPFLAGS	+=	-I./src/Map/Ressource

LDFLAGS	=	-lraylib -lpthread -ldl

all: raylib $(NAME)

$(NAME): $(OBJ) $(MAIN_OBJ)
	$(CXX) $(OBJ) $(MAIN_OBJ) $(CFLAGS) $(LDFLAGS) -o $(PATH_TO_ROOT)/$(NAME)

tests_run: LDFLAGS += -lcriterion --coverage
tests_run:
	$(CXX) $(SRC) $(TEST_FILE) $(CFLAGS) $(LDFLAGS) -o $(TEST_NAME)
	./${TEST_NAME}
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

submodules:
	git submodule update --remote --init

raylib: submodules
	cp include/libs/raylib-4.5/src/raylib.h include/libs/
	cp include/libs/raylib-4.5/src/raymath.h include/libs/
	cp include/libs/raylib-4.5/src/rlgl.h include/libs/
	cp include/libs/raylib-cpp/include/*.hpp include/libs/
	cd include/libs/raylib-4.5/src && $(MAKE) PLATFORM=PLATFORM_DESKTOP
	cp include/libs/raylib-4.5/src/libraylib.a include/libs/

clean:
	$(RM) -f $(MAIN_OBJ)
	$(RM) -f $(OBJ)
	$(RM) *.gcda
	$(RM) *.gcno

fclean: clean
	$(RM) $(PATH_TO_ROOT)/$(NAME)
	$(RM) $(TEST_NAME)
	$(RM) include/libs/*.hpp
	$(RM) include/libs/*.h
	$(RM) include/libs/*.a

re: fclean all

debug: CPPFLAGS += -g3
debug: re

.PHONY: all tests_run clean fclean re debug
