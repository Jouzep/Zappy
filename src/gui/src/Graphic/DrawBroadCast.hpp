/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** DrawBroadCast
*/

#ifndef DRAWBROADCAST_HPP_
#define DRAWBROADCAST_HPP_
    #include <memory>

    #include "Data.hpp"
    #include "raylib-cpp.hpp"
    #include "MyModel.hpp"

namespace Zappy {
    class DrawBroadCast {
        public:
            DrawBroadCast();
            ~DrawBroadCast();

            void setData(std::shared_ptr<Data>);

            void draw(raylib::Camera&);

            void drawChatBox();

            void drawAnimation();

            void event();

            void boxHover();

            void addModel(std::size_t );

        protected:
        private:
            std::shared_ptr<Data> _data;
            bool _drawChatBox = true;
            std::pair<int, int> _windowSize;
            std::size_t _scrollIndex = 0;
            std::map<std::size_t, std::shared_ptr<MyModel>> _model;
            raylib::Camera _camera;
    };
}

#endif /* !DRAWBROADCAST_HPP_ */
