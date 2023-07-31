/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** my_strcat
*/

#include <stdlib.h>
#include <string.h>

void my_strcat(char **dest, char *src)
{
    (*dest) = realloc((*dest),
    sizeof(char) * (strlen((*dest)) * strlen(src) + 1));
    strcat((*dest), src);
}
