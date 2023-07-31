/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Rectangle
*/

#include "Rectangle.hpp"

Zappy::Rect::Rect(Texture2D text)
{
    _text = text;

    _dest.x = 0;
    _dest.y = 0;
    _dest.width = 0;
    _dest.height = 0;
}

void Zappy::Rect::setTexture(Texture2D text)
{
    _text = text;
}

Rectangle Zappy::Rect::getRect()
{
    return _dest;
}

void Zappy::Rect::drawRect(float width, float height, Vector2 position)
{
    Rectangle src;
    src.x = 0;
    src.y = 0;
    src.width = _text.width;
    src.height = _text.height;

    _dest.x = position.x;
    _dest.y = position.y;
    _dest.width = width;
    _dest.height = height;

    DrawTexturePro(_text, src, _dest,  Vector2{0, 0}, 0, WHITE);
}

Zappy::Rect::~Rect()
{
}
