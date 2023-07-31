/*
** EPITECH PROJECT, 2023
** gui
** File description:
** Socket
*/

#include "Socket.hpp"

Socket::Socket(std::string &machine, int port)
{
    if (machine == "localhost")
        machine = "127.0.0.1";
    _socket = createSocket();
    initSocket(machine, port);
    connectToServer(machine);
}

Socket::~Socket()
{
}

int Socket::createSocket()
{
    _socket = socket(AF_INET, SOCK_STREAM, 0);
    if (_socket < 0)
        throw Error("Socket", "Error Init Socket");
    return _socket;
}

void Socket::initSocket(std::string &machine, int port)
{
    _serverAddr.sin_family = AF_INET;
    _serverAddr.sin_port = htons(port);
    if (inet_pton(AF_INET, machine.c_str(), &_serverAddr.sin_addr) <= 0)
        throw Error(machine, "\nInvalid address/ Address not supported");
}

void Socket::connectToServer(std::string &machine)
{
    if (connect(_socket, (struct sockaddr*)&_serverAddr, sizeof(_serverAddr)) < 0)
        throw Error("Connexion Failed", _socket + " cannot connect to machine");
    std::cout << "Socket succesfully connected to the machine:" << machine.c_str() << std::endl;
}