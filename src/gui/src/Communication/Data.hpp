/*
** EPITECH PROJECT, 2023
** gui
** File description:
** Data
*/

#ifndef DATA_HPP_
#define DATA_HPP_
    #include <sys/socket.h>
    #include <unistd.h>
    #include <sstream>
    #include <cstring>
    #include <string>
    #include <map>
    #include <functional>

    #include "GameData.hpp"
    #include "Socket.hpp"
    #include "Select.hpp"
    // #include "macro.hpp"

namespace Zappy {
    class Data {
        public:
            Data(std::string, int);
            ~Data();

            /**
             * @brief Set the Update Function map that will update the game data according to the server response
             * 
             */
            void setUpdateFunction();



            /**
             * @brief reading data from the server
             * 
             */
            void readFromServer();

            /**
             * @brief writing data to the server
             * 
             */
            void writeToServer(char *);



            /**
             * @brief Updating the Data game
             * 
             */
            void updateGame();

            /**
             * @brief Buffering the server response and update game when there is a complete reponse
             * 
             */
            void validResponse();

            /**
             * @brief Parsing the server response and check if there is an error
             * 
             */
            void parseResponse(std::string &);

            /**
             * @brief update the data and check if the server response is good
             * 
             */
            void updateData(std::string);

            void sendPinProtocol(std::size_t id);

            GameData _gameData;

        protected:
        private:
            Socket _socket;
            std::string _machine;
            Select _select;
            std::string buffer;

            std::map<std::string, std::function<void(std::vector<std::string> &)>> _gameUpdater;
    };
}

#endif /* !DATA_HPP_ */
