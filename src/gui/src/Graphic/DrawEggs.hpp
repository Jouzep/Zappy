/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** DrawEggs
*/

#ifndef DRAWEGGS_HPP_
    #define DRAWEGGS_HPP_

    #include <memory>
    #include <map>

    #include "Data.hpp"
    #include "raylib-cpp.hpp"

namespace Zappy {
    class DrawEggs {
        public:
            DrawEggs();
            ~DrawEggs();

            void setData(std::shared_ptr<Data>);

            void setTexture();

            void setModel();

            void draw();

        protected:
        private:
            std::shared_ptr<Data> _data;

            raylib::Texture2D _texture;
            raylib::Model _model;
    };

} // namespace Zappy


#endif /* !DRAWEGGS_HPP_ */
