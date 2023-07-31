/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Player
*/

#include "Player.hpp"

static float getRotationAngle(Zappy::Orientation orientation)
{
    if (orientation == 1)
        return -180;
    if (orientation == 2)
        return -270;
    if (orientation == 3)
        return 0;
    if (orientation == 4)
        return -90;
    return 0;
}

Zappy::Player::Player(std::vector<std::string> &content, std::shared_ptr<Team> team)
{
    _id = std::stoi(content[0]);
    _level = std::stoi(content[4]);
    _orientation = static_cast<Orientation>(std::stoi(content[3]));
    std::cout << "player orientation:" <<content[3] << std::endl;
    _rotation = getRotationAngle(_orientation);
    _position = {std::stoi(content[1]), std::stoi(content[2])};
    _team = team;
}

void Zappy::Player::setCurrentPosition(float size, std::pair<std::size_t, std::size_t> map)
{
    float posX = size * _position.first - (map.first / 2 * size);
    float posY = -(size * _position.second - (map.second / 2 * size));
    float posZ = size;
    _actualPosition = (Vector3){posX, posZ, posY};
    _LastPosition = (Vector3){posX, posZ, posY};
}

Zappy::Player::~Player()
{
}

std::size_t Zappy::Player::getId() const
{
    return _id;
}

std::pair<std::size_t, std::size_t> Zappy::Player::getPosition() const
{
    return _position;
}

std::unordered_map<std::string, std::size_t> Zappy::Player::getInventory() const
{
    return _inventory;
}

Zappy::Orientation Zappy::Player::getOrientation() const
{
    return _orientation;
}

std::shared_ptr<Zappy::Team> Zappy::Player::getTeam() const
{
    return _team;
}

std::size_t Zappy::Player::getLevel() const
{
    return _level;
}

void Zappy::Player::setPosition(std::pair<std::size_t, std::size_t> newPosition)
{
    
    _position = newPosition;
}

void Zappy::Player::setInventory(std::vector<std::string> newInventory)
{
    std::vector<std::string> ressource = {"Food", "Linemate", "Deraumere", "Sibur", "Mendiane", "Phiras", "Thystame"};
    for (std::size_t i = 0; i != newInventory.size(); i++) {
        std::cout << ressource[i] << ":" << newInventory[i] << std::endl;
        _inventory[ressource[i]] = std::stoul(newInventory[i]);
    }
}

void Zappy::Player::setOrientation(Orientation newOrientation)
{
    std::cout << "orientation :" << _orientation << " -> " << newOrientation << std::endl;

    _orientation = newOrientation;
}

void Zappy::Player::setLevel(std::size_t newLevel)
{
    _level = newLevel;
}

void Zappy::Player::setIncantation(int state)
{
    _incantation = state;
}


void Zappy::Player::setDropAnimation(int state)
{
    _drop = state;
}
void Zappy::Player::setPickAnimation(int state)
{
    _pick = state;
}

void Zappy::Player::setEjectAnimation(int state)
{
    _eject = state;
}

void Zappy::Player::setEggLayingAnimation(int state)
{
    _egglaying = state;
}