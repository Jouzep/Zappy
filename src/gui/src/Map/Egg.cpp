/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Egg
*/

#include "Egg.hpp"

Zappy::Egg::Egg()
{
}

Zappy::Egg::~Egg()
{
}

void Zappy::Egg::addEgg(std::size_t id, std::pair<std::size_t, std::size_t> position, std::string team, std::size_t playerid)
{
    egg_t tmp;

    tmp._position = position;
    tmp._timeLeft = 100;
    tmp._id = id;
    tmp._playerId = playerid;
    tmp._team = team;
    tmp.state = false;
    _eggList.insert({id, tmp});
    std::cout << "Egg id :" << id << std::endl;
}

void Zappy::Egg::failedEgg(std::size_t id)
{
    auto a = _eggList[id];
    a.state = false;
    _eggArchive.push_back(a);
    _eggList.erase(id);
}

void Zappy::Egg::connexionEgg(std::size_t id)
{
    auto a = _eggList[id];

    a.state = true;
    _eggArchive.push_back(a);
    _eggList.erase(id);
}