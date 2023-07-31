/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Raylib
*/

#include "Raylib.hpp"

Zappy::Raylib::Raylib(std::string title) : _window(GetMonitorWidth(0), GetMonitorHeight(0), title.c_str())
{
    _window.SetTargetFPS(30);
}

static void handleMapTiles(float *size)
{
    if (*size <= 3)
        *size = 3;
    if (*size >= 20)
        *size = 20;
}

void Zappy::Raylib::setData(std::shared_ptr<Data> data)
{
    std::shared_ptr<Data> tmp(data, data.get());
    _data = tmp;
    _data->_gameData._timeUnit.setFps(30);
    _gameplay.setData(tmp);
    _menu.setData(tmp);

}

void Zappy::Raylib::run()
{
    while (_data->_gameData._end == false) {
        event();
        draw();
    }
    _data->_gameData._end = true;
}

void Zappy::Raylib::event()
{
    if(IsKeyPressed(KEY_T))
        _data->_gameData._menu = !_data->_gameData._menu;
    if (IsKeyPressed(KEY_ESCAPE) && _menu.getPrincipaleMenu() == true)
        _data->_gameData._end = true;
    if (IsKeyPressed(KEY_G))
        _data->_gameData._tileSize++;
    if (IsKeyPressed(KEY_H))
        _data->_gameData._tileSize--;
    handleMapTiles(&_data->_gameData._tileSize);
}

void Zappy::Raylib::draw()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    if (_data->_gameData._menu == true)
        _menu.run();
    else {
        if (_data->_gameData._dataSet == true) {
            _gameplay.run();
        }
    }
    _window.DrawFPS(20, 30);
    EndDrawing();
}

Zappy::Raylib::~Raylib()
{
    std::cout << "Raylib Destroyed" << std::endl;
}
