/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** buffer_management
*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void format_buffer(char *buffer)
{
    char *tmp = strdup(buffer);
    char *str_token = strtok(tmp, " ");

    memset(buffer, 0, 1024);
    while (str_token != NULL) {
        strcat(buffer, str_token);
        strcat(buffer, " ");
        str_token = strtok(NULL, " ");
    }
    buffer[strlen(buffer) - 1] = '\0';
    free(tmp);
}

bool check_buffer_format(char *buffer)
{
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n') {
            buffer[i] = '\0';
            format_buffer(buffer);
            return true;
        }
    }
    return false;
}
