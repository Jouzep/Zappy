/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Shaders
*/

#ifndef SHADERS_HPP
    #define SHADER_HPP

    #include <raylib.h>
    #include <rlgl.h>

namespace Zappy {
    class Shaders {
        public:
            Shaders(Shader shader);
            ~Shaders();
            int getSecondLock();
            Shader _shader;
        protected:
        private:
    };
}

#endif
