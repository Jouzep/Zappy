/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** RessourceFactory
*/

#include "RessourceFactory.hpp"

Zappy::RessourceFactory::RessourceFactory()
{
    _builder.insert({"Sibur", [&](int quantity)
    { return std::make_shared<Sibur>(quantity); }});
    _builder.insert({"Thystame", [&](int quantity)
    { return std::make_shared<Thystame>(quantity); }});
    _builder.insert({"Phiras", [&](int quantity)
    { return std::make_shared<Phiras>(quantity); }});
    _builder.insert({"Mendiane", [&](int quantity)
    { return std::make_shared<Mendiane>(quantity); }});
    _builder.insert({"Linemate", [&](int quantity)
    { return std::make_shared<Linemate>(quantity); }});
    _builder.insert({"Deraumere", [&](int quantity)
    { return std::make_shared<Deraumere>(quantity); }});
    _builder.insert({"Food", [&](int quantity)
    { return std::make_shared<Food>(quantity); }});
}

Zappy::RessourceFactory::~RessourceFactory()
{
}

std::shared_ptr<Zappy::IRessource> Zappy::RessourceFactory::createRessource(std::string &ressourceType, int quantity)
{
    if (_builder.count(ressourceType) > 0) {
        return _builder[ressourceType](quantity);
    }
    throw Error("Undefined Ressource", ressourceType);
}