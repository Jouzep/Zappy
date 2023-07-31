/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Egg
*/

#ifndef EGG_HPP_
#define EGG_HPP_
    #include <iostream>
    #include <map>
    #include <vector>

namespace Zappy {
    struct egg_t {
        std::size_t _id;
        std::pair<std::size_t, std::size_t> _position;
        int _timeLeft;
        std::string _team;
        std::size_t _playerId;
        bool state;
    };
    class Egg
    {
    public:
        Egg();
        ~Egg();

        void addEgg(std::size_t, std::pair<std::size_t, std::size_t>, std::string, std::size_t);

        void failedEgg(std::size_t);

        void connexionEgg(std::size_t);

        std::map<std::size_t, egg_t> _eggList;
        std::vector<egg_t> _eggArchive;
    };
}

#endif /* !EGG_HPP_ */
