/*
** EPITECH PROJECT, 2023
** gui
** File description:
** Gui
*/

#ifndef GUI_HPP_
    #define GUI_HPP_
    #include <string>
    #include <iostream>
    #include <thread>

    #include "Raylib.hpp"

namespace Zappy {
    class Gui {
        public:
            Gui(int port, std::string machine);
            ~Gui();

            /**
             * @brief Run the Gui
             * 
             */
            void run();

            /**
             * @brief Thread function that receive data from the server
             * 
             */
            void receiveServerData();

        protected:
        private:
            Zappy::Raylib _graphic;

            std::thread _dataReceiver;
            bool _isRunning;
            std::shared_ptr<Data> _data;
    };
}

#endif /* !GUI_HPP_ */
