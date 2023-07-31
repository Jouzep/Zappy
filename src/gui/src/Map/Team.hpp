/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Team
*/

#ifndef TEAM_HPP_
#define TEAM_HPP_
    #include <string>
    #include <iostream>
    #include <memory>
    #include <vector>
    #include <cstdlib> // for rand and srand functions
    #include <ctime> // for time function

namespace Zappy {
    class Team {
        public:
            Team(std::string);
            ~Team();

            void addPlayer(std::size_t);

            void deletePlayer(std::size_t);

            std::string getName() const;

            int getId() const;

        protected:
        private:
            std::string _name;
            int _id;
            std::vector<std::size_t> _playerList;
    };
}

#endif /* !TEAM_HPP_ */
