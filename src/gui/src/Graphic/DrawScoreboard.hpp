/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** DrawScoreboard
*/

#ifndef DRAWSCOREBOARD_HPP_
    #define DRAWSCOREBOARD_HPP_

    #include <memory>
    #include <map>

    #include "Data.hpp"
    #include "raylib-cpp.hpp"
    #include "Rectangle.hpp"

namespace Zappy {
    class DrawScoreboard {
        public:
            DrawScoreboard();
            ~DrawScoreboard();

            void getTeam();

            void getPlayer();

            void setData(std::shared_ptr<Data>);

            void drawScoreboard();

        protected:
        private:
            std::shared_ptr<Data> _data;
            std::shared_ptr<GameData> _gameData;
            std::map<std::string, raylib::Texture2D> _texture;
            std::map<std::string, std::shared_ptr<Rect>> _rectangle;

            std::vector<std::string> _teamName;
            std::vector<std::size_t> _playerId;
            std::string _teamNameString;
            std::size_t _playerIdSize;

            Rectangle _scoreboardRec = {200, 0, 0, 100};
            size_t _teamSize = 0;
            size_t _playerSize = 0;

    };
}

#endif /* !DRAWSCOREBOARD_HPP_ */