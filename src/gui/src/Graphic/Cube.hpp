/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Cube
*/

#ifndef CUBE_HPP_
    #define CUBE_HPP_

    #include <raylib.h>
    #include <rlgl.h>
    #include "Shaders.hpp"
    #include <memory>
    #include "raylib-cpp.hpp"
    #include "Data.hpp"

namespace Zappy {
    class Cube {
        public:
            /**
             * @brief Construct a new Cube object
             * 
             */
            Cube(unsigned int top, unsigned int side, unsigned int bot, Shader _shader);
            Cube(unsigned int top, unsigned int side, unsigned int bot);
            Cube(unsigned int item);
            Cube(){};
            ~Cube();

            /**
             * @brief Set the Texture object
             * 
             */
            void setTexture(); 

            /**
             * @brief Set the Position object
             * 
             */
            void setPosition();

            /**
             * @brief Set the Scale object
             * 
             */
            void setScale();

            /**
             * @brief Destroy the Cube object
             * 
             */
            void drawBlockTexture(Vector3 position, Vector3 size, Color color);
            void drawWaterTexture(Vector3 position, Vector3 size, Color color);

        protected:
        private:
            unsigned int _top;
            unsigned int _side;
            unsigned int _bot;
            unsigned int _item;

            std::shared_ptr<Shaders> _shader;

            bool ret = false;
            float itemBounce = 0;
            float seconds = 0;
            float itemRotation = 0;
    };
}

#endif /* !CUBE_HPP_ */
