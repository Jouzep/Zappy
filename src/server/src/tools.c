/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** tools
*/

#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int write_error(char *message, char *label, int ret_value)
{
    if (label == NULL) {
        dprintf(STDERR_FILENO, "%s\n", message);
    } else {
        dprintf(STDERR_FILENO, "%s: %s\n", label, message);
    }
    return ret_value;
}

bool can_convert_to_int(const char* str)
{
    char* end;
    strtol(str, &end, 10);
    return *end == '\0';
}

int rand_nbr(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

static int get_nb_elem(char *buffer, char *sep)
{
    int count = 0;
    char *tmp = strdup(buffer);
    char *str_token = strtok(tmp, sep);
    while (str_token != NULL) {
        count++;
        str_token = strtok(NULL, sep);
    }
    free(tmp);
    return count;
}

char **str_to_word_array(char *buffer, char *sep)
{
    int nb_elem = get_nb_elem(buffer, sep);
    char **new = malloc(sizeof(char*) * (nb_elem + 1));
    char *str_token = NULL;

    if (new == NULL)
        return NULL;
    str_token = strtok(buffer, sep);
    for (int i = 0; str_token != NULL; i++) {
        new[i] = strdup(str_token);
        str_token = strtok(NULL, sep);
    }
    new[nb_elem] = NULL;

    return new;
}
