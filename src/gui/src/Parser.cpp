/*
** EPITECH PROJECT, 2023
** gui
** File description:
** Parser
*/

#include "Parser.hpp"
#include <iostream>
#include <cstring>

Zappy::Parser::Parser(const int ac, char *const *av)
{
    if (ac > 5)
        throw Error("Error on argument length", "Parser");

    for (int i = 1; i < ac; i++) {
        if (std::strcmp(av[i], "-p") == 0) {
            try {
                _port = std::stoi(av[i + 1]);
            } catch (const std::exception &) {
                throw Error("Invalid port", "Parser");
            }
            i++;
            continue;
        }
        if (std::strcmp(av[i], "-h") == 0) {
            if (av[i + 1] == NULL) {
                throw Error("Provide a machine name", "Parser");
            } else {
                _machine = av[i + 1];
            }
            i++;
            continue;
        }
        throw Error("Unknown option", "Parser");
    }

    // Last check if values are set
    if (_port < 0) {
        throw Error("Please provide a valid port", "Parser");
    }
}

Zappy::Parser::~Parser()
{
}

int Zappy::Parser::getPort()
{
    return _port;
}

std::string Zappy::Parser::getMachine()
{
    return _machine;
}