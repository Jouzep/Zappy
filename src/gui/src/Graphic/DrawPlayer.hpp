/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** DrawPlayer
*/

#ifndef DRAWPLAYER_HPP_
    #define DRAWPLAYER_HPP_

    #include <memory>
    #include <map>
    #include <cmath>

    #include "Data.hpp"
    #include "raylib-cpp.hpp"
    #include "MyModel.hpp"
    #include "DrawText3d.hpp"

namespace Zappy {
    class DrawPlayer {
        public:
            DrawPlayer();
            ~DrawPlayer();

            void setData(std::shared_ptr<Data>);

            void setModel();

            void draw(raylib::Camera &camera);

            void drawTeamText(Vector3 pos, std::shared_ptr<Player> player, float size, std::string team);

            float movePlayerRotation(Zappy::Orientation, float);

            Vector3 movePlayerPosition(std::shared_ptr<Player>);

            void movePlayerPositionX(std::shared_ptr<Player>, Vector3);
            void movePlayerPositionY(std::shared_ptr<Player>, Vector3);

            void drawRotatePlayer(std::shared_ptr<Player>);
            void drawMovementPlayer(std::shared_ptr<Player>);

            void pickAnimationPlayer(std::shared_ptr<Player>);
            void ejectAnimationPlayer(std::shared_ptr<Player>);
            void incantationAnimationPlayer(std::shared_ptr<Player>);
            void eggLayingAnimationPlayer(std::shared_ptr<Player>);
            void dropAnimationPlayer(std::shared_ptr<Player>);
            void checkPlayerModel(std::shared_ptr<Player>);

            void playerSelection(std::shared_ptr<Player>, std::size_t);

            void allAction(std::shared_ptr<Player>);

        protected:
        private:
            raylib::Camera3D _camera;
            std::shared_ptr<Data> _data;
            std::map<std::size_t, std::shared_ptr<MyModel>> _model;
            DrawText3d _drawText3d;
            bool _playerSelected = false;
    };

} // namespace Zappy


#endif /* !DRAWPLAYER_HPP_ */
