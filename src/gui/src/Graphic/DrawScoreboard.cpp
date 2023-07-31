/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** DrawScoreboard
*/

#include "DrawScoreboard.hpp"

Zappy::DrawScoreboard::DrawScoreboard()
{
    // getPlayer();
}

Zappy::DrawScoreboard::~DrawScoreboard()
{
}

void Zappy::DrawScoreboard::getTeam()
{
    _teamSize = _data->_gameData._teams.size();
    for (const auto &pair : _data->_gameData._teams) {
        _teamNameString = pair.first;
        _teamName.push_back(_teamNameString);
    }
}

void Zappy::DrawScoreboard::getPlayer()
{
    _playerSize = _data->_gameData._player.size();
    for (const auto &pair : _data->_gameData._player) {
        _playerIdSize = pair.first;
        _playerId.push_back(_playerIdSize);
    }
}

void Zappy::DrawScoreboard::setData(std::shared_ptr<Data> data)
{
    std::shared_ptr<Data> tmp(data, data.get());
    _data = tmp;
}

void Zappy::DrawScoreboard::drawScoreboard()
{
    getTeam();
    getPlayer();

    float scoreboardWidth = _teamSize * 150 + 100;
    float scoreboardX = (GetScreenWidth() - scoreboardWidth) / 2.0f;

    _scoreboardRec.x = scoreboardX;
    _scoreboardRec.width = scoreboardWidth;

    DrawRectangleRec(_scoreboardRec, Fade(SKYBLUE, 0.5f));
    DrawRectangleLinesEx(_scoreboardRec, 1, BLACK);

    for (size_t i = 0; i < _teamSize; i++) {
        DrawText(_teamName[i].c_str(), (_scoreboardRec.x + 100) + (i * 150), 50, 20, RED);
    }
}