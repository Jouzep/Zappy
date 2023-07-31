/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Cube
*/

#include "Cube.hpp"

Zappy::Cube::Cube(unsigned int top, unsigned int side, unsigned int bot)
{
    _top = top;
    _side = side;
    _bot = bot;
    _shader = nullptr;
}

Zappy::Cube::Cube(unsigned int top, unsigned int side, unsigned int bot, Shader shader)
{
    _top = top;
    _side = side;
    _bot = bot;
    _shader = std::make_shared<Shaders>(shader);
}

Zappy::Cube::Cube(unsigned int item)
{
    _item = item;
}

void Zappy::Cube::setTexture()
{
}

void Zappy::Cube::setPosition()
{
}

void Zappy::Cube::setScale()
{
}

Zappy::Cube::~Cube()
{
}

void Zappy::Cube::drawBlockTexture(Vector3 position, Vector3 size, Color color)
{
    float x = position.x;
    float y = position.y;
    float z = position.z;

    float width = size.x;
    float height = size.y;
    float length = size.z;

    rlSetTexture(_side);
        rlBegin(RL_QUADS);
            rlColor4ub(color.r, color.g, color.b, color.a);

            // rlNormal3f(0.0f, 0.0f, 1.0f);
            rlTexCoord2f(0.0f, 0.0f); rlVertex3f(x + width/2, y + height/2, z + length/2);
            rlTexCoord2f(1.0f, 0.0f); rlVertex3f(x - width/2, y + height/2, z + length/2);
            rlTexCoord2f(1.0f, 1.0f); rlVertex3f(x - width/2, y - height/2, z + length/2);
            rlTexCoord2f(0.0f, 1.0f); rlVertex3f(x + width/2, y - height/2, z + length/2);
            
            // rlNormal3f(0.0f, 0.0f, - 1.0f);
            rlTexCoord2f(1.0f, 0.0f); rlVertex3f(x + width/2, y + height/2, z - length/2);
            rlTexCoord2f(1.0f, 1.0f); rlVertex3f(x + width/2, y - height/2, z - length/2);
            rlTexCoord2f(0.0f, 1.0f); rlVertex3f(x - width/2, y - height/2, z - length/2);
            rlTexCoord2f(0.0f, 0.0f); rlVertex3f(x - width/2, y + height/2, z - length/2);

            // rlNormal3f(1.0f, 0.0f, 0.0f);
            rlTexCoord2f(1.0f, 0.0f); rlVertex3f(x - width/2, y + height/2, z - length/2);
            rlTexCoord2f(1.0f, 1.0f); rlVertex3f(x - width/2, y - height/2, z - length/2);
            rlTexCoord2f(0.0f, 1.0f); rlVertex3f(x - width/2, y - height/2, z + length/2);
            rlTexCoord2f(0.0f, 0.0f); rlVertex3f(x - width/2, y + height/2, z + length/2);

            // rlNormal3f( - 1.0f, 0.0f, 0.0f);
            rlTexCoord2f(0.0f, 0.0f); rlVertex3f(x + width/2, y + height/2, z - length/2);
            rlTexCoord2f(1.0f, 0.0f); rlVertex3f(x + width/2, y + height/2, z + length/2);
            rlTexCoord2f(1.0f, 1.0f); rlVertex3f(x + width/2, y - height/2, z + length/2);
            rlTexCoord2f(0.0f, 1.0f); rlVertex3f(x + width/2, y - height/2, z - length/2);
        rlEnd();

    rlSetTexture(_top);
        rlBegin(RL_QUADS);
            rlColor4ub(color.r, color.g, color.b, color.a);
                rlTexCoord2f(0.0f, 1.0f); rlVertex3f(x - width/2, y + height/2, z - length/2);
                rlTexCoord2f(0.0f, 0.0f); rlVertex3f(x - width/2, y + height/2, z + length/2);
                rlTexCoord2f(1.0f, 0.0f); rlVertex3f(x + width/2, y + height/2, z + length/2);
                rlTexCoord2f(1.0f, 1.0f); rlVertex3f(x + width/2, y + height/2, z - length/2);


    rlSetTexture(_bot);
        rlTexCoord2f(1.0f, 1.0f); rlVertex3f(x - width/2, y - height/2, z - length/2);
        rlTexCoord2f(0.0f, 1.0f); rlVertex3f(x + width/2, y - height/2, z - length/2);
        rlTexCoord2f(0.0f, 0.0f); rlVertex3f(x + width/2, y - height/2, z + length/2);
        rlTexCoord2f(1.0f, 0.0f); rlVertex3f(x - width/2, y - height/2, z + length/2);
    rlEnd();

    rlSetTexture(0);
}

void Zappy::Cube::drawWaterTexture(Vector3 position, Vector3 size, Color color)
{
    float x = position.x;
    float y = position.y;
    float z = position.z;
    float width = size.x;
    float height = size.y;
    float length = size.z;
    
    if (_shader != nullptr) {
        seconds += GetFrameTime();
        SetShaderValue(_shader->_shader, _shader->getSecondLock(), &seconds, RL_SHADER_UNIFORM_FLOAT);
        BeginShaderMode(_shader->_shader);
    }
    rlSetTexture(_top);
        rlBegin(RL_QUADS);
            rlColor4ub(color.r, color.g, color.b, color.a);
                rlTexCoord2f(0.0f, 1.0f); rlVertex3f(x - width/2, y + height/2, z - length/2);
                rlTexCoord2f(0.0f, 0.0f); rlVertex3f(x - width/2, y + height/2, z + length/2);
                rlTexCoord2f(1.0f, 0.0f); rlVertex3f(x + width/2, y + height/2, z + length/2);
                rlTexCoord2f(1.0f, 1.0f); rlVertex3f(x + width/2, y + height/2, z - length/2);
        rlEnd();
    if (_shader != nullptr)
        EndShaderMode();
    rlSetTexture(_bot);
        rlTexCoord2f(1.0f, 1.0f); rlVertex3f(x - width/2, y - height/2, z - length/2);
        rlTexCoord2f(0.0f, 1.0f); rlVertex3f(x + width/2, y - height/2, z - length/2);
        rlTexCoord2f(0.0f, 0.0f); rlVertex3f(x + width/2, y - height/2, z + length/2);
        rlTexCoord2f(1.0f, 0.0f); rlVertex3f(x - width/2, y - height/2, z + length/2);
    rlEnd();
    rlSetTexture(0);
}