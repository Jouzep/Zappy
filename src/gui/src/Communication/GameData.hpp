/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** GameData
*/

#ifndef GAMEDATA_HPP_
#define GAMEDATA_HPP_
    #include <map>
    #include <unordered_map>
    #include <vector>
    #include <string>
    #include <iostream>

    #include "Error.hpp"
    #include "Team.hpp"
    #include "Tile.hpp"
    #include "TimeUnit.hpp"
    #include "Player.hpp"
    #include "BroadCast.hpp"
    #include "Incantation.hpp"
    #include "Egg.hpp"

namespace Zappy {
    class GameData {
        public:
            GameData() = default;
            ~GameData();

            void msz(std::vector<std::string> &content);
            void bct(std::vector<std::string> &content);
            void tna(std::vector<std::string> &content);
            void pnw(std::vector<std::string> &content);
            void ppo(std::vector<std::string> &content);
            void plv(std::vector<std::string> &content);
            void pin(std::vector<std::string> &content);
            void pex(std::vector<std::string> &content);
            void pbc(std::vector<std::string> &content);
            void pic(std::vector<std::string> &content);
            void pie(std::vector<std::string> &content);
            void pfk(std::vector<std::string> &content);
            void pdr(std::vector<std::string> &content);
            void pgt(std::vector<std::string> &content);
            void pdi(std::vector<std::string> &content);
            void enw(std::vector<std::string> &content);
            void ebo(std::vector<std::string> &content);
            void edi(std::vector<std::string> &content);
            void sgt(std::vector<std::string> &content);
            void sst(std::vector<std::string> &content);
            void seg(std::vector<std::string> &content);
            void smg(std::vector<std::string> &content);
            void suc(std::vector<std::string> &content);
            void sbp(std::vector<std::string> &content);

            bool _dataSet;
            bool _end = false;
            bool _menu = true;

            std::vector<std::vector<Tile>> _map;
            std::pair<std::size_t, std::size_t> _mapSize;
            std::shared_ptr<RessourceFactory> _factory = std::make_shared<RessourceFactory>();

            std::unordered_map<std::string, std::shared_ptr<Team>> _teams;
            std::unordered_map<std::size_t, std::shared_ptr<Player>> _player;

            BroadCast _broadCast;
            Incantation _incantationList;
            Egg _egg;
            TimeUnit _timeUnit;

            float _tileSize = 10;

            std::size_t _playerIdSelect = 0;

        protected:
        private:
    };
}

#endif /* !GAMEDATA_HPP_ */
