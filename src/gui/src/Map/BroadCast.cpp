/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** BroadCast
*/

#include "BroadCast.hpp"

Zappy::BroadCast::BroadCast()
{

}

Zappy::BroadCast::~BroadCast()
{
    _broadCastList.clear();
    _archive.clear();
    _All.clear();
}

void Zappy::BroadCast::addBroadCast(broadcast_t newBroadCast)
{
    _All.push_back((newBroadCast));
    _broadCastList.push_back((newBroadCast));
}

Zappy::broadcast_t Zappy::BroadCast::getFirstBroacCast(void)
{
    if (_broadCastList.size() == 0)
        throw Error("Animation Error", "There is no broadCast in the database");
    auto tmp = _broadCastList[0];
    _broadCastList.erase(_broadCastList.begin());
    _archive.push_back(tmp);
    return tmp;
}

void Zappy::BroadCast::endBroadCast(std::size_t index)
{
    _archive.push_back(_broadCastList[index]);
    _broadCastList.erase(_broadCastList.begin() + index);
}