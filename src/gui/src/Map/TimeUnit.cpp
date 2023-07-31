/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** TimeUnit
*/

#include "TimeUnit.hpp"

Zappy::TimeUnit::TimeUnit()
{
    _timeUnit = 15;
    _fps = 60;
    _secondPerFrame = 1 / _fps;
    
}

Zappy::TimeUnit::~TimeUnit()
{
}

int Zappy::TimeUnit::getTimeUnit() const
{
    return _timeUnit;
}

void Zappy::TimeUnit::setTimeUnit(int time)
{
    std::cout << "TimeUnit set to " << time << std::endl;
    _timeUnit = time;
}

void Zappy::TimeUnit::setFps(float fps)
{
    _fps = fps;
    _secondPerFrame = 1 / _fps;
    std::cout << "fps" <<_fps << std::endl;
    std::cout << "secondPerFrame" <<_secondPerFrame << std::endl;
}

float Zappy::TimeUnit::getFps() const
{
    return _fps;
}

float Zappy::TimeUnit::getSecondPerFrame() const
{
    return _secondPerFrame;
}

float Zappy::TimeUnit::getActionTime(float action)
{
    return action / _timeUnit;
}