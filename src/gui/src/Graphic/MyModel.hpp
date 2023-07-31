/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** MyModel
*/

#ifndef MYMODEL_HPP_
#define MYMODEL_HPP_

    #include <memory>
    #include <map>
    #include <math.h>

    #include "Data.hpp"
    #include "raylib-cpp.hpp"

namespace Zappy
{
    enum Animation
    {
        laying_egg = 0,
        drop,
        eject,
        incancation,
        marche,
        victory_danse1,
        ramassage,
        victory_danse2,
    };

    class MyModel
    {
    public:
        MyModel(std::string path, unsigned int animsCount, std::string texture);

        MyModel(std::string path, unsigned int animsCount);

        ~MyModel();

        void setCamera(raylib::Camera3D camera);

        bool getSelectedModel(Vector3 position, float size);

        void changeSkin(std::string skin);

        void draw(Vector3 pose, float, std::size_t, bool selected);
        void draw(Vector3 pose, std::size_t, std::pair<std::size_t, std::size_t>, Color);

        void moveAnimation(int i, int frame);

        void moveAnimation(int i);

        void moveAnimationToStart(int i);
        int getAnimCount(int i);

        std::size_t level = 1;

    protected:
    private:
        raylib::Camera3D _camera;
        raylib::Model _model;
        ModelAnimation *_animation;
        raylib::Texture2D _texture;
        BoundingBox _boundingBox;
        float _size;
        int i = 1;
        int _animFrameCounter = 3;
    };
} // namespace Zappy


#endif /* !MYMODEL_HPP_ */
