/*
** EPITECH PROJECT, 2023
** gui
** File description:
** Gui
*/

#include "Gui.hpp"

Zappy::Gui::Gui(int port, std::string machine) : _graphic("Zappy"), _data(std::make_shared<Data>(machine, port))
{
    _graphic.setData(_data);
    _isRunning = true;
}

Zappy::Gui::~Gui()
{
    if (_dataReceiver.joinable())
        _dataReceiver.join();
}

void Zappy::Gui::run()
{
    _dataReceiver = std::thread(&Zappy::Gui::receiveServerData, std::ref(*this));
    _graphic.run();
}

void Zappy::Gui::receiveServerData()
{
    while (_data->_gameData._end == false)
    {
        _data->updateGame();
    }
}