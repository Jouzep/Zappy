/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Gameplay
*/

#ifndef GAMEPLAY_HPP_
#define GAMEPLAY_HPP_
    #include <map>
    #include <memory>

    #include "raylib-cpp.hpp"
    #include "Data.hpp"
    #include "Cube.hpp"
    #include "DrawMap.hpp"
    #include "DrawBroadCast.hpp"
    #include "DrawScoreboard.hpp"

namespace Zappy {
    class Gameplay {
        public:
            Gameplay();
            ~Gameplay();

            void setData(std::shared_ptr<Data>);

            void setCamera();

            void run();

            void event();

            void cameraEvent();

            void playerSelectionEvent();

            void playerViewCamera();

            void draw();

        protected:
        private:
            raylib::Camera3D _camera;

            std::map<std::string, raylib::Texture2D> _texture;
            std::map<std::string, Cube> _cube;
            std::map<std::string, Shader> _shader;
            std::map<std::string, raylib::Model> _model;

            std::shared_ptr<Data> _data;

            DrawMap _worldMap;
            DrawBroadCast _broadCast;
            DrawScoreboard _scoreBoard;
            bool _cameraMove;
            int _cameraMode;
            bool _playerView = false;
            bool _scoreboardView = false;
    };
}

#endif /* !GAMEPLAY_HPP_ */
