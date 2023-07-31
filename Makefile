##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-vincent.shao
## File description:
## Makefile
##

SERVER_PATH	=	src/server

GUI_PATH	=	src/gui

AI_PATH		=	src/ai

all: zappy_server zappy_gui zappy_ai

zappy_server:
	$(MAKE) -C $(SERVER_PATH)

zappy_gui:
	$(MAKE) -C $(GUI_PATH)

zappy_ai:
	$(MAKE) -C $(AI_PATH)

doc:
	sphinx-build -b html $(AI_PATH)/src Doc/Zappy_ai/
	doxygen Doxyfile

tests_run:
	$(MAKE) tests_run -C $(SERVER_PATH)
	$(MAKE) tests_run -C $(GUI_PATH)
	$(MAKE) tests_run -C $(AI_PATH)

clean:
	$(MAKE) clean -C $(SERVER_PATH)
	$(MAKE) clean -C $(GUI_PATH)
	$(MAKE) clean -C $(AI_PATH)

fclean:
	$(MAKE) fclean -C $(SERVER_PATH)
	$(MAKE) fclean -C $(GUI_PATH)
	$(MAKE) fclean -C $(AI_PATH)

re:
	$(MAKE) re -C $(SERVER_PATH)
	$(MAKE) re -C $(GUI_PATH)
	$(MAKE) re -C $(AI_PATH)

debug:
	$(MAKE) debug -C $(SERVER_PATH)
	$(MAKE) debug -C $(GUI_PATH)
	$(MAKE) debug -C $(AI_PATH)

.PHONY: all zappy_server zappy_gui zappy_ai tests_run clean fclean re debug doc
