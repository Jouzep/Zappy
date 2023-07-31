/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** DrawText3d
*/

#ifndef DRAWTEXT3D_HPP_
    #define DRAWTEXT3D_HPP_

    #include <memory>
    #include "raylib-cpp.hpp"
    #include <rlgl.h>


namespace Zappy {
    class DrawText3d {
        public:
            DrawText3d();
            ~DrawText3d();

            void DrawText3D(Font font, const char *text, Vector3 position, Color tint, float size);
            void DrawTextCodepoint3D(Font font, int codepoint, Vector3 position, float fontSize, bool backface, Color tint);

        protected:
        private:
    };
}

#endif /* !DRAWTEXT3D_HPP_ */