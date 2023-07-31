/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Rectangle
*/

#ifndef RECTANGLE_HPP_
    #define RECTANGLE_HPP_

    #include <raylib.h>
    #include <rlgl.h>


namespace Zappy {
    class Rect {
        public:
            /**
             * @brief Construct a new Rect object
             * 
             * @param Texture2D  
             */
            Rect(Texture2D text);

            /**
             * @brief draw rectangle
             * 
             * @param width 
             * @param height 
             * @param position 
             */
            void drawRect(float width, float height, Vector2 position);

            /**
             * @brief Set the Texture object
             * 
             * @param text 
             */
            void setTexture(Texture2D text);

            /**
             * @brief Get the Rect object
             * 
             * @param position 
             * @return Vector2 
             */
            Rectangle getRect();
            /**
             * @brief Destroy the Rect object
             * 
             */
            ~Rect();

        protected:
        private:
            Texture2D _text;
            Rectangle _dest;
    };
}

#endif /* !RECTANGLE_HPP_ */
