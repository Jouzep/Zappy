/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Gameplay
*/

#include "Gameplay.hpp"

Zappy::Gameplay::Gameplay()
{
    setCamera();
}

Zappy::Gameplay::~Gameplay()
{
    std::cout << "Gameplay Destroyed" << std::endl;
}

void Zappy::Gameplay::setData(std::shared_ptr<Data> data)
{
    std::shared_ptr<Data> tmp(data, data.get());
    _data = tmp;
    _worldMap.setData(tmp);
    _broadCast.setData(tmp);
    _scoreBoard.setData(tmp);
}

void Zappy::Gameplay::setCamera()
{
    _camera.position = (Vector3){0.0f, 150.0f, 150.0f};    // Camera position
    _camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    _camera.up = (Vector3){ 0.0f, 10.0f, 0.0f };          // Camera up vector (rotation towards target)
    _camera.fovy = 45.0f;                                // Camera field-of-view Y
    _camera.projection = CAMERA_PERSPECTIVE;
    _cameraMove = false;
    _cameraMode = CAMERA_ORBITAL;
}

void Zappy::Gameplay::run()
{
    event();
    draw();
}

void Zappy::Gameplay::event()
{
    if (IsKeyPressed(KEY_ESCAPE))
        _data->_gameData._end = true;
    if (IsKeyPressed(KEY_TAB))
        _scoreboardView = !_scoreboardView;
    playerSelectionEvent();
    if (_playerView == false)
        cameraEvent();
}

static bool isEqual(float a, float b)
{
    return std::abs(a - b) < 0.01;
}

void Zappy::Gameplay::playerViewCamera()
{
    std::size_t id = _data->_gameData._playerIdSelect;
    Vector3 position = _data->_gameData._player[id]->_actualPosition;
    position.y += _data->_gameData._tileSize * 1.5;
    Vector3 actualTarget = _camera.target;
    float tmpx = actualTarget.x - (_data->_gameData._player[id]->_actualPosition.x * 0.01);
    float tmpy = actualTarget.y - (_data->_gameData._player[id]->_actualPosition.y * 0.01);
    float tmpz = actualTarget.z - (_data->_gameData._player[id]->_actualPosition.z * 0.01);
    _camera.position = position;
    _camera.target = (Vector3){tmpx, tmpy, tmpz};
    _camera.Update(CAMERA_CUSTOM);
}

void Zappy::Gameplay::playerSelectionEvent()
{
    if (_data->_gameData._playerIdSelect != 0)
    {
        if (IsKeyPressed(KEY_P) && _playerView == false) {
            _playerView = true;
            _camera.fovy = 90.0f;                                // Camera field-of-view Y
            _camera.Update(CAMERA_CUSTOM);
        }
        else if (IsKeyPressed(KEY_P) && _playerView == true) {
            _playerView = false;
            _camera.position =(Vector3){0.0f, 150.0f, 150.0f};    // Camera position
            _camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
            _camera.fovy = 45.0f;                                // Camera field-of-view Y
        }
        if (_playerView == true) {
            playerViewCamera();
        }
    }
    else {
                            _playerView = false;
        // _camera.position =(Vector3){0.0f, 100.0f, 50.0f};    // Camera position
            // _camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
            // _camera.fovy = 45.0f;   
    }

}

void Zappy::Gameplay::cameraEvent()
{
    if (IsKeyPressed(KEY_L)) {
        _cameraMove = !_cameraMove;
    }
    if (IsKeyPressed(KEY_R)) {
        _camera.position =(Vector3){0.0f, 100.0f, 50.0f};    // Camera position
        _camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    }
    if (_cameraMove == true) {
        _camera.Update(CAMERA_ORBITAL);
        _camera.target = (Vector3){0.0f, 0.0f, 0.0f}; // Camera looking at point
        return;
    }
    Vector3 position = {0.0, 0.0, 0.0};
    if (IsKeyDown(KEY_LEFT)) {
        position.y = -0.5f;
        _camera.target = (Vector3){0.0f, 0.0f, 0.0f}; // Camera looking at point
        }
    if (IsKeyDown(KEY_RIGHT)) {
        position.y = 0.5f;
        _camera.target = (Vector3){0.0f, 0.0f, 0.0f}; // Camera looking at point
        }
    if (IsKeyDown(KEY_UP)) {
        position.z = 0.5f;
        _camera.target = (Vector3){0.0f, 0.0f, 0.0f}; // Camera looking at point
    }
    if (IsKeyDown(KEY_DOWN)) {
        position.z = -0.5f;
        _camera.target = (Vector3){0.0f, 0.0f, 0.0f}; // Camera looking at point
    }
    if (IsKeyDown(KEY_C))
        position.z = -0.5f;
    if (IsKeyDown(KEY_SPACE))
        position.z = 0.5f;
    
    if (IsKeyDown(KEY_W))
        position.x = 0.5f;
    if (IsKeyDown(KEY_S))
        position.x = -0.5f;
    if (IsKeyDown(KEY_A))
        position.y = -0.5f;
    if (IsKeyDown(KEY_D))
        position.y = 0.5f;
    _camera.Update(position, Vector3{0.0f, 0.0000f, 0.0f}, 0.0);
}

void Zappy::Gameplay::draw()
{
    _worldMap.draw(_camera);
    _broadCast.draw(_camera);
    if (_scoreboardView == true)
        _scoreBoard.drawScoreboard();
    // DrawGrid(10, 1);
}