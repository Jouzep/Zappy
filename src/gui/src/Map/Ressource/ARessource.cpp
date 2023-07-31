/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** ARessource
*/

#include "ARessource.hpp"

Zappy::ARessource::ARessource(int quantity)
{
   std::cout << "ARessource Build" << std::endl;
   this->_quantity = quantity;
}

Zappy::ARessource::~ARessource()
{
}

void Zappy::ARessource::setQuantity(int quantity)
{
   _quantity = quantity;
}

int Zappy::ARessource::getQuantity() const
{
   return _quantity;
}