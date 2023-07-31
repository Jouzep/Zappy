/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** DrawPlayer
*/

#include "DrawPlayer.hpp"

Zappy::DrawPlayer::DrawPlayer()
{
    setModel();
}

Zappy::DrawPlayer::~DrawPlayer()
{
}

void Zappy::DrawPlayer::setData(std::shared_ptr<Data> data)
{
    std::shared_ptr<Data> tmp(data, data.get());
    _data = tmp;
}

static float getRotationAngle(Zappy::Orientation orientation, float actualRotation)
{
    if (orientation == 3 && actualRotation <= -270)
        return -360;
    if (orientation == 1)
        return -180;
    if (orientation == 2)
        return -270;
    if (orientation == 3)
        return 0;
    if (orientation == 4)
        return -90;
    return 0;
}

void Zappy::DrawPlayer::setModel()
{
    // _model.insert({1, std::make_shared<MyModel>("src/gui/assets/skin/player_model.glb", 3, "src/gui/assets/skin/nezuko.png")});
    // _model.insert({2, std::make_shared<MyModel>("src/gui/assets/skin/player_model.glb", 3, "src/gui/assets/skin/nweak.png")});
    // _model.insert({3, std::make_shared<MyModel>("src/gui/assets/skin/player_model.glb", 3, "src/gui/assets/skin/kdd.png")});
    // _model.insert({4, std::make_shared<MyModel>("src/gui/assets/skin/player_model.glb", 3, "src/gui/assets/skin/babyking.png")});
    // _model.insert({5, std::make_shared<MyModel>("src/gui/assets/skin/player_model.glb", 3, "src/gui/assets/skin/brennsou.png")});
    // _model.insert({6, std::make_shared<MyModel>("src/gui/assets/skin/player_model.glb", 3, "src/gui/assets/skin/spiderman.png")});    
    // _model.insert({7, std::make_shared<MyModel>("src/gui/assets/skin/player_model.glb", 3, "src/gui/assets/skin/steve.png")});    
    // _model.insert({8, std::make_shared<MyModel>("src/gui/assets/skin/player_model.glb", 3, "src/gui/assets/skin/zirnox.png")});    
}

void Zappy::DrawPlayer::checkPlayerModel(std::shared_ptr<Player> player)
{
    std::map<std::size_t, std::string> skinLevel = {
        {1, "src/gui/assets/skin/nezuko.png"},
        {2, "src/gui/assets/skin/nweak.png"},
        {3, "src/gui/assets/skin/kdd.png"},
        {4, "src/gui/assets/skin/babyking.png"},
        {5, "src/gui/assets/skin/brennsou.png"},
        {6, "src/gui/assets/skin/spiderman.png"},
        {7, "src/gui/assets/skin/steve.png"},
        {8, "src/gui/assets/skin/zirnox.png"},
    };
    std::size_t id = player->getId();
    std::size_t actualLevel = player->getLevel();
    if (_model.count(id) == 0)
    {
        _model.insert({id, std::make_shared<MyModel>("src/gui/assets/skin/player_model.glb", 3, skinLevel[actualLevel])});
    }
    else
    {
        if (_model[id]->level != actualLevel)
            _model[id]->changeSkin(skinLevel[actualLevel]);
    }
        _model[id]->level = actualLevel;
}

void Zappy::DrawPlayer::draw(raylib::Camera &camera)
{
    _camera = camera;
    auto players = _data->_gameData._player;
    auto size = _data->_gameData._tileSize;
    // auto map = _data->_gameData._mapSize;
    for (const auto &element : players)
    {
        auto player = element.second; // player class
        std::size_t id = player->getId();
        allAction(player);
        drawTeamText(player->_actualPosition, player, size, player->getTeam()->getName());
        playerSelection(player, size);
        _model[id]->draw(player->_actualPosition, player->_rotation, size, player->_selected);
    }
}

void Zappy::DrawPlayer::allAction(std::shared_ptr<Player> player)
{
    checkPlayerModel(player);
    if (movePlayerRotation(player->getOrientation(), player->_rotation) != 10) {
        drawRotatePlayer(player);
        return;
    }
    if (player->_pick != -1) {
        pickAnimationPlayer(player);
        return;
    }
    if (player->_drop != -1) {
        dropAnimationPlayer(player);
        return;
    }
    if (player->_incantation != -1) {
        incantationAnimationPlayer(player);
        return;
    }
    if (player->_eject != -1) {
        ejectAnimationPlayer(player);
        return;
    }
    if (player->_egglaying != -1) {
        eggLayingAnimationPlayer(player);
        return;
    }
    drawMovementPlayer(player);
}

void Zappy::DrawPlayer::incantationAnimationPlayer(std::shared_ptr<Player> player)
{
    float nbrframe = _data->_gameData._timeUnit.getActionTime(300) / _data->_gameData._timeUnit.getSecondPerFrame();
    float AnimationFrame = _model[player->getId()]->getAnimCount(Animation::incancation) / (nbrframe);
    
    int AnimationFrameRounded = ceil(AnimationFrame);
    if (AnimationFrame < 1)
        AnimationFrameRounded = 1;
    player->_incantation += AnimationFrameRounded;
    _model[player->getId()]->moveAnimation(Animation::incancation, AnimationFrameRounded);
    if (player->_incantation >= _model[player->getId()]->getAnimCount(Animation::incancation)) {
        _model[player->getId()]->moveAnimationToStart(Animation::incancation);
        player->_incantation = -1;
    }
}

void Zappy::DrawPlayer::eggLayingAnimationPlayer(std::shared_ptr<Player> player)
{
    float nbrframe = _data->_gameData._timeUnit.getActionTime(47) / _data->_gameData._timeUnit.getSecondPerFrame();
    float AnimationFrame = _model[player->getId()]->getAnimCount(Animation::laying_egg) / (nbrframe);
    
    int AnimationFrameRounded = ceil(AnimationFrame);
    if (AnimationFrame < 1)
        AnimationFrameRounded = 1;
    player->_egglaying += AnimationFrameRounded;
    _model[player->getId()]->moveAnimation(Animation::laying_egg, AnimationFrameRounded);
    if (player->_egglaying >= _model[player->getId()]->getAnimCount(Animation::laying_egg))
    {
        _model[player->getId()]->moveAnimationToStart(Animation::laying_egg);
        player->_egglaying = -1;
    }
}

void Zappy::DrawPlayer::ejectAnimationPlayer(std::shared_ptr<Player> player)
{
    float nbrframe = _data->_gameData._timeUnit.getActionTime(7) / _data->_gameData._timeUnit.getSecondPerFrame();
    float AnimationFrame = _model[player->getId()]->getAnimCount(Animation::eject) * 2 / (nbrframe);
    
    int AnimationFrameRounded = ceil(AnimationFrame);
    if (AnimationFrame < 1)
        AnimationFrameRounded = 1;
    player->_eject += AnimationFrameRounded;
    _model[player->getId()]->moveAnimation(Animation::eject, AnimationFrameRounded);
    if (player->_eject >= _model[player->getId()]->getAnimCount(Animation::eject)) {
        _model[player->getId()]->moveAnimationToStart(Animation::eject);
        player->_eject = -1;
    }
}

void Zappy::DrawPlayer::pickAnimationPlayer(std::shared_ptr<Player>player)
{
    float nbrframe = _data->_gameData._timeUnit.getActionTime(7) / _data->_gameData._timeUnit.getSecondPerFrame();
    float AnimationFrame = _model[player->getId()]->getAnimCount(Animation::ramassage) / (nbrframe);
    
    int AnimationFrameRounded = ceil(AnimationFrame);
    if (AnimationFrame < 1)
        AnimationFrameRounded = 1;
    player->_pick += AnimationFrameRounded;
    _model[player->getId()]->moveAnimation(Animation::ramassage, AnimationFrameRounded);
    if (player->_pick >= _model[player->getId()]->getAnimCount(Animation::ramassage)) {
        _model[player->getId()]->moveAnimationToStart(Animation::ramassage);
        player->_pick = -1;
    }
}

void Zappy::DrawPlayer::dropAnimationPlayer(std::shared_ptr<Player>player)
{
    float nbrframe = _data->_gameData._timeUnit.getActionTime(7) / _data->_gameData._timeUnit.getSecondPerFrame();
    float AnimationFrame = _model[player->getId()]->getAnimCount(Animation::drop) / (nbrframe);
    int AnimationFrameRounded = ceil(AnimationFrame);
    player->_drop += AnimationFrameRounded;
        if (AnimationFrame < 1)
        AnimationFrameRounded = 1;
    _model[player->getId()]->moveAnimation(Animation::drop, AnimationFrameRounded);
    if (player->_drop >= _model[player->getId()]->getAnimCount(Animation::drop)) {
        _model[player->getId()]->moveAnimationToStart(Animation::drop);
        player->_drop = -1;
    }
}


void Zappy::DrawPlayer::playerSelection(std::shared_ptr<Player> player, std::size_t size)
{
    std::size_t id = player->getId();
    auto players = _data->_gameData._player;
    bool tmp = _model[id]->getSelectedModel(player->_actualPosition, size);
    _model[id]->setCamera(_camera);
    if (tmp == true && player->_selected == false) {
        for (const auto &element1 : players)
            element1.second->_selected = false;
        player->_selected = true;
        _data->_gameData._playerIdSelect = player->getId();
        _data->sendPinProtocol(player->getId());
    }
    else if (tmp == true && player->_selected == true) {
        player->_selected = false;
        _data->_gameData._playerIdSelect = 0;                             // Camera field-of-view Y
    }
        
}

void Zappy::DrawPlayer::drawTeamText(Vector3 pos, std::shared_ptr<Player> player, float size, std::string team)
{
    unsigned char tmpcolorR = (player->getTeam()->getId()) % 255;
    unsigned char tmpcolorG = tmpcolorR * 4 % 150;
    Color textColor = Color{30, tmpcolorR, 30, 255};
    if (tmpcolorR % 3 == 1)
        textColor = Color{tmpcolorR, 30, tmpcolorG, 255};
    if (tmpcolorR % 3 == 2)
        textColor = Color{30, tmpcolorR, 30, 255};
    if (tmpcolorR % 3 == 3)
        textColor = Color{tmpcolorR, 30, tmpcolorG, 255};
    _drawText3d.DrawText3D(GetFontDefault(), team.c_str(), (Vector3){pos.x - size / 6.0f, pos.y + size * 1.2f, pos.z}, textColor, size);
    _drawText3d.DrawText3D(GetFontDefault(), std::to_string(player->getId()).c_str(), (Vector3){pos.x - size / 6.0f + 1.0f, pos.y + size * 1.1f, pos.z}, textColor, size);
}

float Zappy::DrawPlayer::movePlayerRotation(Zappy::Orientation orientation, float actualRotation)
{
    float nextOrientation = getRotationAngle(orientation, actualRotation);
    if (nextOrientation == actualRotation)
        return 10;
    if (nextOrientation == -270 && actualRotation == 0)
        actualRotation = -360;
    if (nextOrientation == -90 && actualRotation == -360)
        actualRotation = 0;
    if (nextOrientation == -90 && actualRotation == -360)
        actualRotation = 0;
    if (nextOrientation > actualRotation) {
        actualRotation++;
        if (actualRotation > nextOrientation)
            actualRotation = nextOrientation;
        return actualRotation;
    }
    if (nextOrientation < actualRotation) {
        actualRotation--;
        if (actualRotation < nextOrientation)
            actualRotation = nextOrientation;
        return actualRotation;
    }
    return actualRotation;
}

void Zappy::DrawPlayer::drawRotatePlayer(std::shared_ptr<Player> player)
{
    float nbrframe = _data->_gameData._timeUnit.getActionTime(7) / _data->_gameData._timeUnit.getSecondPerFrame();
    float animationFrame = 90 / nbrframe;
    int animationFrameRounded = ceil(animationFrame);
    for (int i = 0; i != animationFrameRounded; i++)
    {
        float tmp = movePlayerRotation(player->getOrientation(), player->_rotation);
        if (tmp == 10)
            break;
        player->_rotation = tmp;
    }
}

static bool isEqual(float a, float b)
{
    return std::abs(a - b) < 0.001;
}

void Zappy::DrawPlayer::drawMovementPlayer(std::shared_ptr<Player> player)
{
    auto next = player->getPosition();
    auto size = _data->_gameData._tileSize;
    auto map = _data->_gameData._mapSize;
    float posX = size * next.first - (map.first / 2 * size);
    float posY = -(size * next.second - (map.second / 2 * size));
    float posZ = size;

    if (isEqual(std::abs(player->_actualPosition.x), std::abs(posX)) == false) {
        movePlayerPositionX(player, (Vector3){posX, posZ, posY});
    }
    else if (isEqual(std::abs(player->_actualPosition.z), std::abs(posY)) == false) {
        movePlayerPositionY(player,(Vector3){posX, posZ, posY});
    }
    else {
        _model[player->getId()]->moveAnimationToStart(Animation::marche);
    }
}

void Zappy::DrawPlayer::movePlayerPositionX(std::shared_ptr<Player> player, Vector3 target)
{
    float distance = target.x - (player->_LastPosition.x);
    if (isEqual(std::abs(distance), _data->_gameData._tileSize) == false) {
        player->_actualPosition.x = target.x;
        return;
    }
    float nbrframe = _data->_gameData._timeUnit.getActionTime(7) / _data->_gameData._timeUnit.getSecondPerFrame();
    float moveFrame = std::abs(distance) * 10 / nbrframe;
    int moveFramePerLoop = std::abs(ceil(moveFrame));
    float animFrame = _model[player->getId()]->getAnimCount(Animation::marche) / nbrframe / moveFramePerLoop;
    if (std::isinf(animFrame))
        animFrame = 1;
    int animFramePerLoop = std::abs(ceil(animFrame));
    float increment;
    if (distance > 0)
        increment = 0.1;
    else
        increment = -0.1;
    for (int i = 0; i != moveFramePerLoop ; i++)
    {
        if (isEqual(player->_actualPosition.x, target.x)) {
            player->_actualPosition.x = target.x;
            return;
        }
        player->_actualPosition.x = player->_actualPosition.x + increment;
        _model[player->getId()]->moveAnimation(Animation::marche, animFramePerLoop);
    }
}

void Zappy::DrawPlayer::movePlayerPositionY(std::shared_ptr<Player> player, Vector3 target)
{
    float distance = target.z - (player->_LastPosition.z);
    if (isEqual(std::abs(distance), _data->_gameData._tileSize) == false) {
        player->_actualPosition.z = target.z;
        return;
    }
    float nbrframe = _data->_gameData._timeUnit.getActionTime(7) / _data->_gameData._timeUnit.getSecondPerFrame();
    float moveFrame = std::abs(distance) * 10 / nbrframe;
    int moveFramePerLoop = std::abs(ceil(moveFrame));
    float animFrame = _model[player->getId()]->getAnimCount(Animation::marche) / nbrframe / moveFramePerLoop;
    std::cout << animFrame << std::endl;
    if (std::isinf(animFrame))
        animFrame = 1;
    int animFramePerLoop = std::abs(ceil(animFrame));
    std::cout << animFramePerLoop << std::endl;
    float increment;
    if (distance > 0)
        increment = 0.1;
    else
        increment = -0.1;

    for (int i = 0; i != moveFramePerLoop; i++) {
        if (isEqual(player->_actualPosition.z, target.z)) {
            player->_actualPosition.z = target.z;
            return;
        }
        player->_actualPosition.z = player->_actualPosition.z + increment;
        _model[player->getId()]->moveAnimation(Animation::marche, animFramePerLoop);
    }
}