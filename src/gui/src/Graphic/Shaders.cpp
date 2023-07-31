/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Shaders
*/

#include "Shaders.hpp"

Zappy::Shaders::Shaders(Shader shader): _shader(shader)
{
    int freqXLoc = GetShaderLocation(_shader, "freqX");
    int freqYLoc = GetShaderLocation(_shader, "freqY");
    int ampXLoc = GetShaderLocation(_shader, "ampX");
    int ampYLoc = GetShaderLocation(_shader, "ampY");
    int speedXLoc = GetShaderLocation(_shader, "speedX");
    int speedYLoc = GetShaderLocation(_shader, "speedY");

    // Shader uniform values that can be updated at any time
    float freqX = 1.0f;
    float freqY = 11.0f;
    float ampX = 50.0f;
    float ampY = 50.0f;
    float speedX = 5.0f;
    float speedY = 5.0f;

    float screenSize[2] = { (float)GetScreenWidth(), (float)GetScreenHeight() };
    SetShaderValue(_shader, GetShaderLocation(_shader, "size"), &screenSize, SHADER_UNIFORM_VEC2);
    SetShaderValue(_shader, freqXLoc, &freqX, SHADER_UNIFORM_FLOAT);
    SetShaderValue(_shader, freqYLoc, &freqY, SHADER_UNIFORM_FLOAT);
    SetShaderValue(_shader, ampXLoc, &ampX, SHADER_UNIFORM_FLOAT);
    SetShaderValue(_shader, ampYLoc, &ampY, SHADER_UNIFORM_FLOAT);
    SetShaderValue(_shader, speedXLoc, &speedX, SHADER_UNIFORM_FLOAT);
    SetShaderValue(_shader, speedYLoc, &speedY, SHADER_UNIFORM_FLOAT);
}

int Zappy::Shaders::getSecondLock()
{
    int secondsLoc = GetShaderLocation(_shader, "secondes");
    return secondsLoc;
}

Zappy::Shaders::~Shaders()
{
}
