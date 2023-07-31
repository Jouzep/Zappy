/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Tile
*/

#include "Tile.hpp"

Zappy::Tile::Tile()
{
    _selected = false;
}

Zappy::Tile::Tile(std::size_t x, std::size_t y, std::shared_ptr<RessourceFactory> factory)
{
    _position = std::make_pair(x, y);
    _factory = factory;
    _selected = false;
}

Zappy::Tile::~Tile()
{
}

std::pair<std::size_t, std::size_t> Zappy::Tile::getPosition() const
{
    return _position;
}
std::vector<std::shared_ptr<Zappy::IRessource>> Zappy::Tile::getRessources() const
{
    return _ressources;
}

void Zappy::Tile::setRessources(std::vector<std::string> &content)
{
    std::vector<std::string> ressource = {"Food", "Linemate", "Deraumere", "Sibur", "Mendiane", "Phiras", "Thystame"};

    for (std::size_t i = 0; i != content.size(); i++) {
        if (_ressources.size() != ressource.size()) {
            auto tmp = _factory->createRessource(ressource[i], std::stoi(content[i]));
            _ressources.push_back(tmp);
        } else {
            _ressources[i]->setQuantity(std::stoi(content[i]));
        }
    }
}