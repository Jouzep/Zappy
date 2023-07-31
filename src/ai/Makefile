##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-vincent.shao
## File description:
## Makefile
##

PATH_TO_ROOT	=	../..

CP	=	cp

NAME	=	zappy_ai

TEST_FILE	=	test/test_ia.py

all:
	$(CP) src/main.py $(PATH_TO_ROOT)/$(NAME)
	chmod +x $(PATH_TO_ROOT)/$(NAME)

tests_run: # Epitech docker dont have coverage program
# coverage run $(TEST_FILE)
# coverage report

clean:
	$(RM) *.pyc

fclean: clean
	$(RM) $(PATH_TO_ROOT)/$(NAME)
	$(RM) .coverage

re: fclean all

debug: re

.PHONY: all tests_run clean fclean re debug
