/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** DrawBroadCast
*/

#include "DrawBroadCast.hpp"

Zappy::DrawBroadCast::DrawBroadCast()
{
    _windowSize = {GetMonitorWidth(0), GetMonitorHeight(0)};
}

Zappy::DrawBroadCast::~DrawBroadCast()
{
}

void Zappy::DrawBroadCast::setData(std::shared_ptr<Data> data)
{
    std::shared_ptr<Data> tmp(data, data.get());
    _data = tmp;
}

void Zappy::DrawBroadCast::event()
{
    if (IsKeyPressed(KEY_ENTER))
        _drawChatBox = !_drawChatBox;
    if (_drawChatBox)
        boxHover();
}

void Zappy::DrawBroadCast::boxHover()
{
    int rectWidth = _windowSize.first * 0.2;
    int rectHeight = _windowSize.second * 0.6;
    float x = _windowSize.first - _windowSize.first * 0.005 - rectWidth;
    float y = _windowSize.second * 0.2;
    raylib::Rectangle rect(x, y, x + rectWidth, y +rectHeight);
    if (CheckCollisionPointRec(GetMousePosition(), rect)) {
        DrawRectangle(x, y, rectWidth, rectHeight, Fade(SKYBLUE, 0.5f));
        _scrollIndex -= GetMouseWheelMove();
        // if (_scrollIndex > _data->_gameData._broadCast._All.size())
            // _scrollIndex = _data->_gameData._broadCast._All.size() - 1;
        // if (_scrollIndex < 0)
        //     _scrollIndex = 0;
    }
}

void Zappy::DrawBroadCast::draw(raylib::Camera& camera)
{
    _camera = camera;
    event();
    _camera.BeginMode();
    drawAnimation();
    _camera.EndMode();
    if (_drawChatBox)
        drawChatBox();

}

static Color getTeamColor(std::size_t id)
{
    unsigned char tmpcolorR = (id) % 255;
    unsigned char tmpcolorG = tmpcolorR * 4 % 150;
    Color textColor = Color{30, tmpcolorR, 30, 255};
    if (tmpcolorR % 3 == 1)
        textColor = Color{tmpcolorR, 30, tmpcolorG, 255};
    if (tmpcolorR % 3 == 2)
        textColor = Color{30, tmpcolorR, 30, 255};
    if (tmpcolorR % 3 == 3)
        textColor = Color{tmpcolorR, 30, tmpcolorG, 255};
    return textColor;
}
void Zappy::DrawBroadCast::drawChatBox()
{
    int rectWidth = _windowSize.first * 0.2;
    int rectHeight = _windowSize.second * 0.6;
    float x = _windowSize.first - _windowSize.first * 0.005 - rectWidth;
    float y = _windowSize.second * 0.2;
    DrawRectangle(x, y, rectWidth, rectHeight, Fade(SKYBLUE, 0.5f));
    DrawRectangleLines( x, y, rectWidth, rectHeight, BLACK);
    auto players = _data->_gameData._player;
    std::vector<broadcast_t> message = _data->_gameData._broadCast._All;
    for (std::size_t i = 0; i != message.size(); i++)
    {
        std::size_t index = message.size() - i - 1;
        std::size_t id = message[index]._playerId;
        std::string player = "[" + std::to_string(index) +  "]" + "Player " + std::to_string(id) + ":";
        if (y + rectHeight * 0.90 - _windowSize.second * 0.05 * i <= y)
                break;
        if (players.count(id) != 0) {
            std::size_t teamid = players[id]->getTeam()->getId();
            Color color = getTeamColor(teamid);
            DrawText(player.c_str(), x + rectWidth * 0.05, y + rectHeight * 0.90 - _windowSize.second * 0.05 * i, 20, color);
            DrawText(message[index]._message.c_str(), x + rectWidth * 0.05, y + rectHeight * 0.90 - _windowSize.second * 0.05 * i + 20, 20, BLACK);
        }
        else {
            player.append(" (Dead)");
            DrawText(player.c_str(), x + rectWidth * 0.05, y + rectHeight * 0.90 - _windowSize.second * 0.05 * i, 20, DARKGRAY);
            DrawText(message[index]._message.c_str(), x + rectWidth * 0.05, y + rectHeight * 0.90 - _windowSize.second * 0.05 * i + 20 , 20, BLACK);
        }
    }
}

void Zappy::DrawBroadCast::drawAnimation()
{
    auto &animation = _data->_gameData._broadCast;
    float nbrframe = _data->_gameData._timeUnit.getActionTime(7) / _data->_gameData._timeUnit.getSecondPerFrame();
    int i = 0;
    float size = _data->_gameData._tileSize;
    auto map = _data->_gameData._mapSize;
    
    for (auto &element : animation._broadCastList)
    {
        std::size_t id = element._playerId;
        float posX = size * element._position.first - (map.first / 2 * size);
        float posY = -(size * element._position.second - (map.second / 2 * size));
        float posZ = size + 0.15;
        Vector3 position = {posX,posZ,posY};
        addModel(id);
        float AnimationFrame = _model[id]->getAnimCount(0) / (nbrframe);
        int AnimationFrameRounded = ceil(AnimationFrame);
        element._animation += AnimationFrameRounded;
        _model[id]->moveAnimation(0, AnimationFrameRounded);
        if (element._animation >= _model[id]->getAnimCount(0)) {
            _model[id]->moveAnimationToStart(0);
            _data->_gameData._broadCast.endBroadCast(i);
        }
        if (_data->_gameData._player.count(id) == 0)
            return;
        Color color = getTeamColor(_data->_gameData._player[id]->getTeam()->getId());
        _model[id]->draw(position, size, _data->_gameData._mapSize, color);
        i++;
    }
}

void Zappy::DrawBroadCast::addModel(std::size_t playerId)
{
    if (_model.count(playerId) == 0) {
        _model.insert({playerId, std::make_shared<MyModel>("src/gui/assets/items/obj/broadCastEffect.glb", 3)});
    }
}