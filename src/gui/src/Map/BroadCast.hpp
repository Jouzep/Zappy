/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** BroadCast
*/

#ifndef BROADCAST_HPP_
#define BROADCAST_HPP_

#include <iostream>
#include <vector>
#include "Error.hpp"

namespace Zappy {

    struct broadcast_t {
        std::size_t _playerId;
        std::pair<std::size_t, std::size_t> _position;
        std::string _message;
        int _animation;
    };

    class BroadCast
    {
    public:
        BroadCast();
        ~BroadCast();

        void addBroadCast(broadcast_t);

        broadcast_t getFirstBroacCast(void);
        void endBroadCast(std::size_t index);
        std::vector<broadcast_t> _broadCastList;
        std::vector<broadcast_t> _archive;
        std::vector<broadcast_t> _All;

    protected:
    private:
        
    };
}

#endif /* !BROADCAST_HPP_ */
