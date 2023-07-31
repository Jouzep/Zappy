/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** DrawMap
*/

#include "DrawMap.hpp"

Zappy::DrawMap::DrawMap() : _camera()
{
    setTexture();
    setCube();
    std::cout << "----------------" << GetCurrentMonitor() << std::endl;
    _windowSize = {GetMonitorWidth(0), GetMonitorHeight(0)};
}

Zappy::DrawMap::~DrawMap()
{
    UnloadShader(_shader["waterWave"]);
}

void Zappy::DrawMap::setData(std::shared_ptr<Data> data)
{
    std::shared_ptr<Data> tmp(data, data.get());
    _data = tmp;
    _egg.setData(tmp);
    _items.setData(tmp);
    _player.setData(tmp);
}

void Zappy::DrawMap::setTexture()
{
    _texture.insert({"grassSide", raylib::Texture("src/gui/assets/grass_block_side.png")});
    _texture.insert({"grassTop", raylib::Texture("src/gui/assets/grass_block_top.png")});
    _texture.insert({"water", raylib::Texture("src/gui/assets/water_flow.png")});
    _texture.insert({"dirt", raylib::Texture("src/gui/assets/dirt.png")});
    _texture.insert({"clearbackground", raylib::Texture("src/gui/assets/clearbackground.png")});
    _shader.insert({"waterWave", LoadShader(0, TextFormat("src/gui/assets/shaders/wave.fs"))});

    _texture.insert({"Thystame", raylib::Texture("src/gui/assets/items/texture/nether_star.png")});
    _texture.insert({"Phiras", raylib::Texture("src/gui/assets/items/texture/emerald.png")});
    _texture.insert({"Mendiane", raylib::Texture("src/gui/assets/items/texture/diamond.png")});
    _texture.insert({"Sibur", raylib::Texture("src/gui/assets/items/texture/gold.png")});
    _texture.insert({"Deraumere", raylib::Texture("src/gui/assets/items/texture/iron.png")});
    _texture.insert({"Linemate", raylib::Texture("src/gui/assets/items/texture/coal.png")});
    _texture.insert({"Food", raylib::Texture("src/gui/assets/items/texture/carrot.png")});

    _texture.insert({"sky", raylib::Texture("src/gui/assets/InGameSkybox/sky.png")});
    _texture.insert({"est", raylib::Texture("src/gui/assets/InGameSkybox/est.png")});
    _texture.insert({"nord", raylib::Texture("src/gui/assets/InGameSkybox/nord.png")});
    _texture.insert({"ouest", raylib::Texture("src/gui/assets/InGameSkybox/ouest.png")});
    _texture.insert({"bot", raylib::Texture("src/gui/assets/InGameSkybox/bot.png")});
    _texture.insert({"sud", raylib::Texture("src/gui/assets/InGameSkybox/sud.png")});
}

void Zappy::DrawMap::setCube()
{
    _cube.insert({"water", Cube(_texture["water"].GetId(), _texture["clearbackground"].GetId(), _texture["water"].GetId(), _shader["waterWave"])});
    _cube.insert({"grass", Cube(_texture["grassTop"].GetId(), _texture["grassSide"].GetId(), _texture["dirt"].GetId())});

    _cube.insert({"sky", Cube(_texture["sky"].GetId(), _texture["sky"].GetId(), _texture["sky"].GetId())});
    _cube.insert({"est", Cube(_texture["est"].GetId(), _texture["est"].GetId(), _texture["est"].GetId())});
    _cube.insert({"nord", Cube(_texture["nord"].GetId(), _texture["nord"].GetId(), _texture["nord"].GetId())});
    _cube.insert({"ouest", Cube(_texture["ouest"].GetId(), _texture["ouest"].GetId(), _texture["ouest"].GetId())});
    _cube.insert({"bot", Cube(_texture["bot"].GetId(), _texture["bot"].GetId(), _texture["bot"].GetId())});
    _cube.insert({"sud", Cube(_texture["sud"].GetId(), _texture["sud"].GetId(), _texture["sud"].GetId())});

}

void Zappy::DrawMap::drawSkybox()
{
    _cube["est"].drawBlockTexture(Vector3{1.0f, 1.0f, 1.0f - _data->_gameData._tileSize * 40}, Vector3{_data->_gameData._tileSize * 40, _data->_gameData._tileSize * 40, _data->_gameData._tileSize * 40}, WHITE);
    _cube["sud"].drawBlockTexture(Vector3{1.0f - _data->_gameData._tileSize * 40, 1.0f, 1.0f}, Vector3 {_data->_gameData._tileSize * 40, _data->_gameData._tileSize * 40, _data->_gameData._tileSize * 40}, WHITE);
    _cube["ouest"].drawBlockTexture(Vector3{1.0f, 1.0f, 1.0f + _data->_gameData._tileSize * 40}, Vector3{_data->_gameData._tileSize * 40, _data->_gameData._tileSize * 40, _data->_gameData._tileSize * 40}, WHITE);
    _cube["nord"].drawBlockTexture(Vector3{1.0f + _data->_gameData._tileSize * 40, 1.0f, 1.0f}, Vector3 {_data->_gameData._tileSize * 40, _data->_gameData._tileSize * 40, _data->_gameData._tileSize * 40}, WHITE);
    _cube["sky"].drawBlockTexture(Vector3{1.0f, 1.0f + _data->_gameData._tileSize * 40, 1.0f}, Vector3 {_data->_gameData._tileSize * 40, _data->_gameData._tileSize * 40, _data->_gameData._tileSize * 40}, WHITE);
    _cube["bot"].drawBlockTexture(Vector3{1.0f, 1.0f - _data->_gameData._tileSize * 40, 1.0f}, Vector3 {_data->_gameData._tileSize * 40, _data->_gameData._tileSize * 40, _data->_gameData._tileSize * 40}, WHITE);
}

void Zappy::DrawMap::draw(raylib::Camera3D &camera)
{
    _camera = camera;
    _camera.BeginMode();
    drawSkybox();
    drawMap();
    drawSelectedTile();
    _egg.draw();
    _player.draw(_camera);
    _camera.EndMode();
    drawBlockInformation();
    drawPlayerInventory();
}

void Zappy::DrawMap::drawPlayerInventory()
{
    std::size_t id = _data->_gameData._playerIdSelect;
    if (id != 0)
    {
        if (_data->_gameData._player.count(id) == 0)
            return;
        std::vector<std::string> ressource = {"Food", "Linemate", "Deraumere", "Sibur", "Mendiane", "Phiras", "Thystame"};
        auto player = _data->_gameData._player[id];
        float rectWidth = _windowSize.first * 0.2;
        float rectHeight = _windowSize.second * 0.15;
        float x = _windowSize.first * 0.005;
        float y = _windowSize.second * 0.05;
        std::string teamName = player->getTeam()->getName();
        std::string playerId = std::to_string(player->getId());
        std::string Name = teamName;
        std::string Level = "Level : " + std::to_string(player->getLevel());
        Name.append(" : ID ");
        Name.append(playerId);
        DrawText(Name.c_str(), x + rectWidth * 0.1 , y + rectHeight * 0.1, 20, RED);
        DrawText(Level.c_str(), x + rectWidth * 0.1 , y + rectHeight * 0.3, 20, MAROON);
        DrawRectangle(x, y, rectWidth, rectHeight, Fade(SKYBLUE, 0.5f));
        DrawRectangleLines( x, y, rectWidth, rectHeight, BLACK);
        auto rss = player->getInventory();
        for (std::size_t i = 0; i != ressource.size(); i++)
        {
            float tmp = i;
            DrawTextureEx(_texture[ressource[i]], (Vector2){static_cast<float>(x + rectWidth * 0.1 * (tmp + 1), y + rectHeight * 0.5)}, 0.0, 2, WHITE);
            DrawText(std::to_string(rss[ressource[i]]).c_str(), x + rectWidth * 0.105 * (tmp + 1), y + rectHeight * 0.8, 20, WHITE);
        }
    }
}

void Zappy::DrawMap::drawMap()
{
    auto size = _data->_gameData._tileSize;
    auto mapSize = _data->_gameData._mapSize;

    for (std::size_t x = 0; x != mapSize.first; x++)
        for (std::size_t y = 0; y != mapSize.second; y++) {
            drawTile(x, y, mapSize);
        }
    _cube["water"].drawWaterTexture((Vector3){0, 0.9, 0}, (Vector3){size * 40, size / 0.9f, size * 40}, GRAY);
}

void Zappy::DrawMap::drawTile(std::size_t x, std::size_t y, std::pair<std::size_t, std::size_t> map)
{
    float size = _data->_gameData._tileSize;
    int midX = map.first / 2;
    int midY = map.second / 2;
    float posX = (size * x - (midX * size));
    float posY = -(size * y - (midY * size));

    float posZ = size / 2;

    int ret = tilehover(posX, posY, posZ, size);
    tileSelection(x, y, ret);
    _cube["grass"].drawBlockTexture((Vector3){posX, posZ, posY}, (Vector3){size, size, size}, WHITE);
    _items.drawItems((Vector3){posX, posY, posZ}, size, _data->_gameData._map[x][y].getRessources());

}

void Zappy::DrawMap::drawSelectedTile()
{
    if (_lastTile.first == 2000)
        return;
    auto map = _data->_gameData._mapSize;
    float size = _data->_gameData._tileSize;
    int midX = map.first / 2;
    int midY = map.second / 2;
    float posX = size * _lastTile.first - (midX * size);
    float posY = -(size * _lastTile.second - (midY * size));
    float posZ = size / 2;
    if (_data->_gameData._map[_lastTile.first][_lastTile.second]._selected == true)
        DrawCubeWiresV((Vector3){posX, posZ + size / 2 + 1, posY}, (Vector3){size,  2, size}, GREEN);
}

void Zappy::DrawMap::drawBlockInformation()
{
    if (_lastTile.first == 2000)
        return;
    int rectWidth = 350;
    int rectHeight = 113;
    float x = _windowSize.first / 2 - rectWidth / 2;
    float y = _windowSize.second  - rectHeight - 113;
    
    DrawRectangle(x, y, rectWidth, rectHeight, Fade(SKYBLUE, 0.5f));
    DrawRectangleLines( x, y, rectWidth, rectHeight, BLACK);
    std::vector<std::string> ressource = {"Food", "Linemate", "Deraumere", "Sibur", "Mendiane", "Phiras", "Thystame"};
    x += 20;
    y += 20;
    auto rss = _data->_gameData._map[_lastTile.first][_lastTile.second].getRessources();
    rss[0]->getQuantity();
    for (std::size_t i = 0; ressource.size() != i; i++)
    {
        DrawText(std::to_string(rss[i]->getQuantity()).c_str(), x + 12, y + 40, 30, WHITE);
        DrawTextureEx(_texture[ressource[i]], (Vector2){x, y}, 0.0, 2.5, WHITE);
        x += 45;
    }
    std::string lol;
    lol.append(std::to_string(_lastTile.first).c_str());
    lol.append(":");
    lol.append(std::to_string(_lastTile.second).c_str());
    DrawText(lol.c_str(), x + 12 + 10, y + 40, 30, WHITE);
}

void Zappy::DrawMap::tileSelection(std::size_t x, std::size_t y, int ret)
{
    if (ret == 1)
    {
        if (_data->_gameData._map[x][y]._selected == true) {
            _data->_gameData._map[x][y]._selected = false;
            _lastTile = {2000, 2000};
        } else {
            _data->_gameData._map[x][y]._selected = true;
            if (_lastTile.first != 2000)
                _data->_gameData._map[_lastTile.first][_lastTile.second]._selected = false;
            _lastTile = {x, y};
        }
    }
}

int Zappy::DrawMap::tilehover(float posX, float posY, float posZ, float size)
{
    RayCollision collision;
    Ray ray;
    ray = GetMouseRay(GetMousePosition(), _camera);
    collision = GetRayCollisionBox(ray, (BoundingBox){(Vector3){ posX - size/2, posZ + size/2, posY - size/2 },
                                                      (Vector3){ posX + size/2, posZ + size/2, posY + size/2 }});
    if (collision.hit)
        DrawCubeWiresV((Vector3){posX, posZ + size / 2, posY}, (Vector3){size,  0.5, size}, RED);
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && collision.hit)
        return 1;
    return 0;
}