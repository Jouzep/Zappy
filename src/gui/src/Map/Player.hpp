/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Player
*/


#ifndef PLAYER_HPP_
#define PLAYER_HPP_
    #include <string>
    #include <unordered_map>
    #include <memory>
    #include <vector>

    #include "IRessource.hpp"
    #include "Team.hpp"
    #include "raylib.h"

namespace Zappy {
    enum Orientation
    {
        N = 1,
        E,
        S,
        W
    };
    // struct eggLaying_t {
        // bool state;
        // int loading;
    // };
    class Player
    {
    public:
        Player(std::vector<std::string> &content, std::shared_ptr<Zappy::Team>);
        ~Player();

        /**
         * @brief Get the Id of the player
         * 
         * @return std::size_t 
         */
        std::size_t getId() const;

        /**
         * @brief Get the Position of the player
         * 
         * @return std::pair<std::size_t, std::size_t> 
         */
        std::pair<std::size_t, std::size_t> getPosition() const;

        /**
         * @brief Get the Ressources of the player
         * 
         * @return std::unordered_map<std::string, std::shared_ptr<IRessource>> 
         */
        std::unordered_map<std::string, std::size_t> getInventory() const;

        /**
         * @brief Get the Orientation of the player
         * 
         * @return Orientation 
         */
        Orientation getOrientation() const;

        /**
         * @brief Get the Team of the player
         * 
         * @return std::shared_ptr<Team> 
         */
        std::shared_ptr<Team> getTeam() const;

        /**
         * @brief Get the Level of the player
         * 
         * @return std::size_t 
         */
        std::size_t getLevel() const;


        /**
         * @brief Set the Position of the player
         * 
         */
        void setPosition(std::pair<std::size_t, std::size_t>);

        /**
         * @brief Set the Inventory of the player
         * 
         */
        void setInventory(std::vector<std::string>);

        /**
         * @brief Set the Orientation of the player
         * 
         */
        void setOrientation(Orientation);

        /**
         * @brief Set the Level of the player
         * 
         * @param level 
         */
        void setLevel(std::size_t level);

        /**
         * @brief Set the Incantation state of the player
         * 
         */
        void setIncantation(int);

        void setDropAnimation(int);

        void setPickAnimation(int);

        void setEjectAnimation(int);

        void setEggLayingAnimation(int);

        void setCurrentPosition(float tileSize, std::pair<std::size_t, std::size_t> map);

        float _rotation;
        std::pair<std::size_t, std::size_t> _position;
        // std::pair<std::size_t, std::size_t> _actualPosition;
        Vector3 _actualPosition;
        Vector3 _nextPosition;
        Vector3 _LastPosition;
        bool _selected = false;
        int _incantation = -1;
        int _drop = -1;
        int _pick = -1;
        int _eject = -1;
        int _egglaying = -1;

    protected:
    private:
        std::unordered_map<std::string, std::size_t> _inventory;
        Orientation _orientation;
        std::shared_ptr<Team> _team;
        std::size_t _level;
        std::size_t _id;
        // std::vector<std::string> ressource = {"Food", "Linemate", "Deraumere", "Sibur", "Mendiane", "Phiras", "Thystame"};
        // eggLaying_t _egglaying = {false, 0};
    };
}

#endif /* !PLAYER_HPP_ */
