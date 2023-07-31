/*
** EPITECH PROJECT, 2023
** gui
** File description:
** OptionsParser
*/

#include "OptionsParser.hpp"

int OptionsParser::getopt(int argc, char * const argv[], const char *optstring)
{
    return ::getopt(argc, argv, optstring);
}

char *OptionsParser::getOptarg()
{
    return optarg;
}