/*
** EPITECH PROJECT, 2023
** gui
** File description:
** Error
*/

#include "Error.hpp"

Error::Error(const std::string message)
{
    _message = message;
}

Error::Error(const std::string message, const std::string label)
{
    _message = label;
    _message += ": ";
    _message += message;
}

const char* Error::what() const noexcept
{
    return _message.c_str();
}