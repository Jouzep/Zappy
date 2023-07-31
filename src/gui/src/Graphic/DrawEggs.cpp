/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** DrawEggs
*/

#include "DrawEggs.hpp"

Zappy::DrawEggs::DrawEggs()
{
    setTexture();
    setModel();
}

Zappy::DrawEggs::~DrawEggs()
{
}

void Zappy::DrawEggs::setData(std::shared_ptr<Data> data)
{
    std::shared_ptr<Data> tmp(data, data.get());
    _data = tmp;
}

void Zappy::DrawEggs::setTexture()
{
    _texture = raylib::Texture("src/gui/assets/items/texture/turtle_egg.png");
}

void Zappy::DrawEggs::setModel()
{
    _model = LoadModel("src/gui/assets/items/obj/turtle_eggs.obj");
    SetMaterialTexture(&_model.materials[0], MATERIAL_MAP_DIFFUSE, _texture);
}

void Zappy::DrawEggs::draw()
{
    auto egg = _data->_gameData._egg._eggList;
    auto mapSize = _data->_gameData._mapSize;
    auto tileSize = _data->_gameData._tileSize;
    
    float posZ = tileSize;

    for (auto &element: egg) {
        float posX = tileSize * element.second._position.first - (mapSize.first / 2 * tileSize);
        float posY = -(tileSize * element.second._position.second- (mapSize.second / 2 * tileSize));
        _model.Draw((Vector3) { posX, posZ, posY}, tileSize / 2, WHITE);
    }
}
