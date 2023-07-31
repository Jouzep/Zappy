/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Raylib
*/

#ifndef RAYLIB_HPP_
    #define RAYLIB_HPP_
    #define SCREEN_WIDTH 1920
    #define SCREEN_HEIGHT 1080

    #include <raylib.h>
    #include <raylib-cpp.hpp>
    #include <string>
    #include <iostream>
    #include <memory>

    #include "Cube.hpp"
    #include "Rectangle.hpp"
    #include "Error.hpp"
    #include "Data.hpp"
    #include "Gameplay.hpp"
    #include "Menu.hpp"

namespace Zappy {
    class Raylib {
        public:
            Raylib(std::string title);
            ~Raylib();

            /**
             * @brief Set the Data object
             * 
             * @param data 
             */
            void setData(std::shared_ptr<Data> data);

            /**
             * @brief Launch loop game and set isRunning to false if end
             *
             * @param isRunning
             */
            void run();

            /**
             * @brief function that call all drawing element
             * 
             */
            void draw();

            /**
             * @brief function Handle client event
             *
             */
            void event();

        protected:
        private:
            raylib::Window _window;
            raylib::AudioDevice _audio;
            bool _exitWindow = false;
            std::shared_ptr<Data> _data;
            Menu _menu;
            Gameplay _gameplay;
    };
}

#endif /* !RAYLIB_HPP_ */
