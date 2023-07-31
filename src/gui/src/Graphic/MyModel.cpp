/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** MyModel
*/

#include "MyModel.hpp"

Zappy::MyModel::MyModel(std::string path, unsigned int animsCount) : _animation(LoadModelAnimations(path.c_str(), &animsCount)), _model(path.c_str())
{
}

Zappy::MyModel::MyModel(std::string path, unsigned int animsCount, std::string texture): _animation(LoadModelAnimations(path.c_str(), &animsCount)), _model(path.c_str()), _texture(texture.c_str())
{
    SetMaterialTexture(&_model.materials[0], MATERIAL_MAP_DIFFUSE, _texture);
}

Zappy::MyModel::~MyModel()
{
}

void Zappy::MyModel::setCamera(raylib::Camera3D camera)
{
    _camera = camera;
}

bool Zappy::MyModel::getSelectedModel(Vector3 position, float size)
{
    _boundingBox = {(Vector3){ (position.x - size * 0.235f), position.y, (position.z - size * 0.235f)},
                        (Vector3){ (position.x + size * 0.235f), position.y + size, (position.z + size * 0.235f)}};

    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        if (GetRayCollisionBox(GetMouseRay(GetMousePosition(), _camera), _boundingBox).hit)
            return true;
    return false;
}

void Zappy::MyModel::draw(Vector3 pose, std::size_t size, std::pair<std::size_t, std::size_t> map, Color team)
{
    float higher = map.first;
    if (map.first < map.second)
        higher = map.second;
    higher *= 0.2;
    Vector3 scale = {size * higher, size * higher, size * higher};
    _model.Draw(pose, (Vector3){0, 1, 0}, 0, scale, team);
}

void Zappy::MyModel::draw(Vector3 pose, float orientation, std::size_t size, bool selected)
{
    if (selected)
        DrawBoundingBox(_boundingBox, RED);
    
    Vector3 scale = {0.3f * size, 0.3f * size, 0.3f * size};
    _model.Draw(pose, (Vector3){0, 1, 0}, orientation, scale, WHITE);
    return;
}

void Zappy::MyModel::moveAnimation(int i, int frame)
{
    UpdateModelAnimation(_model, _animation[i], _animFrameCounter);
    _animFrameCounter += frame;

    if (_animFrameCounter >= _animation[i].frameCount) {
        UpdateModelAnimation(_model, _animation[i], _animation[i].frameCount);
        _animFrameCounter = 0;
    }
}

int Zappy::MyModel::getAnimCount(int i)
{
    return _animation[i].frameCount;
}

void Zappy::MyModel::moveAnimation(int i)
{
    UpdateModelAnimation(_model, _animation[i], _animFrameCounter);
    _animFrameCounter += 3;
	if (_animFrameCounter >= _animation[i].frameCount)
        _animFrameCounter = 0;
}

void Zappy::MyModel::moveAnimationToStart(int i)
{
    UpdateModelAnimation(_model, _animation[i], 0);
    _animFrameCounter = 0;
}

void Zappy::MyModel::changeSkin(std::string skin)
{
    _texture.Unload();
    _texture.Load(skin);
    SetMaterialTexture(&_model.materials[0], MATERIAL_MAP_DIFFUSE, _texture);
}