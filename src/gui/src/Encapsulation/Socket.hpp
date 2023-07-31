/*
** EPITECH PROJECT, 2023
** gui
** File description:
** Socket
*/

#ifndef SOCKET_HPP_
#define SOCKET_HPP_
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <iostream>
    #include "Error.hpp"


class Socket {
    public:
        Socket(std::string &machine, int port);
        ~Socket();

        /**
         * @brief Create a Socket object
         * 
         * @return int 
         */
        int createSocket();

        /**
         * @brief Initialise sockaddr struct
         * 
         */
        void initSocket(std::string &machine, int port);

        /**
         * @brief Connect the socket to the machine
         * 
         */
        void connectToServer(std::string &machine);

        int _socket;
        struct sockaddr_in _serverAddr;
    protected:
    private:
};

#endif /* !SOCKET_HPP_ */