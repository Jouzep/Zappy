/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** DrawItems
*/

#ifndef DRAWITEMS_HPP_
#define DRAWITEMS_HPP_
    #include <memory>
    #include <map>

    #include "Data.hpp"
    #include "raylib-cpp.hpp"
    #include "Cube.hpp"

namespace Zappy {
    class DrawItems {
        public:
            DrawItems();
            ~DrawItems();
            void setData(std::shared_ptr<Data>);

            void setTexture();

            void setModel();

            void draw();

            void drawItems(Vector3 pos, std::size_t size, std::vector<std::shared_ptr<IRessource>> rss);

            void drawSpacedItem(std::size_t qty, Vector3 pos, std::string ressource, std::size_t size, std::size_t i);

        protected:
        private:
            std::shared_ptr<Data> _data;

            std::map<std::string, raylib::Texture2D> _texture;
            std::map<std::string, raylib::Model> _model;

            bool _ret = false;
            float _rotation = 0;
            float _itemBounce = 0;
    };
}

#endif /* !DRAWITEMS_HPP_ */
