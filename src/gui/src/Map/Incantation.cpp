/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Incantation
*/

#include "Incantation.hpp"

Zappy::Incantation::Incantation()
{
}

Zappy::Incantation::~Incantation()
{
}

void Zappy::Incantation::addIncantation(std::vector<std::string> &content)
{
    std::pair<std::size_t, std::size_t> position = std::make_pair(std::stoul(content[0]), std::stoul(content[1]));
    std::size_t level = std::stoul(content[2]);
    std::vector<std::size_t> playerList;
    for (std::size_t i = 3; i != content.size(); i++)
        playerList.push_back(std::stoul(content[i]));
    Incantation_t tmp = {
        level,
        position,
        0,
        playerList,
    };
    _incantationCurrent.push_back(tmp);
    std::cout << "Incantation started:";
    // for (auto element: playerList)
        // printf("[%d]", element);
    std::cout << std::endl;
}

void Zappy::Incantation::endIncantation(std::vector<std::string> &content)
{
    std::pair<std::pair<std::size_t, std::size_t>, bool> state;

    if (content[2] == "0")
        state = std::make_pair(std::make_pair(std::stoul(content[0]),std::stoul(content[1])), false); // failed
    else
        state = std::make_pair(std::make_pair(std::stoul(content[0]),std::stoul(content[1])), true); // succes
    _done.push_back(state);

    // Incantation  end
}