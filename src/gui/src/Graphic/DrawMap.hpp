/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** DrawMap
*/

#ifndef DRAWMAP_HPP_
#define DRAWMAP_HPP_
    #include <memory>
    #include <map>

    #include "Data.hpp"
    #include "raylib-cpp.hpp"
    #include "Cube.hpp"
    #include "DrawItems.hpp"
    #include "DrawPlayer.hpp"
    #include "DrawEggs.hpp"

namespace Zappy {
    class DrawMap {
        public:
            DrawMap();
            ~DrawMap();

            void setData(std::shared_ptr<Data>);


            void setTexture();

            void setCube();

            void draw(raylib::Camera3D &);

            void drawMap();

            void drawTile(std::size_t x, std::size_t y, std::pair<std::size_t, std::size_t> map);

            int tilehover(float posX, float posY, float posZ, float size);

            void drawSelectedTile();

            void drawBlockInformation();

            void drawPlayerInventory();

            void tileSelection(std::size_t, std::size_t, int ret);

            void drawSkybox();

        protected:
        private:
            raylib::Camera3D _camera;
            std::shared_ptr<Data> _data;
            std::map<std::string, raylib::Texture2D> _texture;
            std::map<std::string, Shader> _shader;
            std::map<std::string, Cube> _cube;

            DrawItems _items;
            DrawPlayer _player;
            DrawEggs _egg;

            std::pair<int, int> _windowSize;
            std::pair<std::size_t, std::size_t> _lastTile = {2000, 2000};
    };
}
#endif /* !DRAWMAP_HPP_ */
