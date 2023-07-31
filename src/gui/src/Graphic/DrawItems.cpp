/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** DrawItems
*/

#include "DrawItems.hpp"

Zappy::DrawItems::DrawItems()
{
    setTexture();
    setModel();
}

Zappy::DrawItems::~DrawItems()
{
}

void Zappy::DrawItems::setData(std::shared_ptr<Data> data)
{
    std::shared_ptr<Data> tmp(data, data.get());
    _data = tmp;
}

void Zappy::DrawItems::setTexture()
{
    _texture.insert({"Thystame", raylib::Texture("src/gui/assets/items/texture/nether_star.png")});
    _texture.insert({"Phiras", raylib::Texture("src/gui/assets/items/texture/emerald.png")});
    _texture.insert({"Mendiane", raylib::Texture("src/gui/assets/items/texture/diamond.png")});
    _texture.insert({"Sibur", raylib::Texture("src/gui/assets/items/texture/gold.png")});
    _texture.insert({"Deraumere", raylib::Texture("src/gui/assets/items/texture/iron.png")});
    _texture.insert({"Linemate", raylib::Texture("src/gui/assets/items/texture/coal.png")});
    _texture.insert({"Food", raylib::Texture("src/gui/assets/items/texture/carrot.png")});
}

void Zappy::DrawItems::setModel()
{
    std::vector<std::string> ressource = {"Food", "Linemate", "Deraumere", "Sibur", "Mendiane", "Phiras", "Thystame"};
    _model.insert({"Thystame", raylib::Model("src/gui/assets/items/obj/nether_star.obj")});
    _model.insert({"Phiras", raylib::Model("src/gui/assets/items/obj/emerald.obj")});
    _model.insert({"Mendiane", raylib::Model("src/gui/assets/items/obj/diamond.obj")});
    _model.insert({"Sibur", raylib::Model("src/gui/assets/items/obj/gold.obj")});
    _model.insert({"Deraumere", raylib::Model("src/gui/assets/items/obj/iron.obj")});
    _model.insert({"Linemate", raylib::Model("src/gui/assets/items/obj/coal.obj")});
    _model.insert({"Food", raylib::Model("src/gui/assets/items/obj/carrot.obj")});
    for (std::size_t i = 0; ressource.size() != i; ++i)
        SetMaterialTexture(&_model[ressource[i]].materials[0], MATERIAL_MAP_DIFFUSE, _texture[ressource[i]]);
}

void Zappy::DrawItems::drawItems(Vector3 pos, std::size_t size, std::vector<std::shared_ptr<IRessource>> rss)
{
    std::vector<std::string> ressource = {"Food", "Linemate", "Deraumere", "Sibur", "Mendiane", "Phiras", "Thystame"};
    for (std::size_t i = 0; i != rss.size(); i++) {
        auto qty = rss[i]->getQuantity();
        if (qty > 0)
            drawSpacedItem(qty, pos, ressource[i], size, i);
    }
}

void Zappy::DrawItems::drawSpacedItem(std::size_t qty, Vector3 pos, std::string ressource, std::size_t size, std::size_t i)
{
    float x = i;
    float y = 0;

    if (i > 2) {
        x = i - 2;
        y++;
    }
    if (i > 4) {
        x = i - 4;
        y++;
    }
    if (i > 6) {
        x = i - 6;
        y++;
    }
    float fps = _data->_gameData._timeUnit.getFps();
    float increment = (0.001 * 60) / fps;
    float incrementbouncing = (0.00002 * 60) / fps;
    std::cout << increment << std::endl;
    _rotation -= increment;
    if (_ret == false)
        _itemBounce += incrementbouncing;
    if (_ret == true)
        _itemBounce -= incrementbouncing;
    if (_itemBounce > 0.8)
        _ret = true;
    if (_itemBounce < 0)
        _ret = false;
    for (std::size_t a = 0; a < qty;)
    {
        a += 5;
        DrawModelEx(_model[ressource], (Vector3){pos.x - (size / 2) + x * 0.8f + size * 0.3f, ((pos.z + size / 2 + 1.7f) - 0.2f + a * 0.01f) + _itemBounce, pos.y - (size / 2) + a * 0.2f + y * 1}, (Vector3){0, 1, 0}, _rotation, (Vector3){size / 3.0f, size / 3.0f, size / 3.0f}, WHITE);
    }
}