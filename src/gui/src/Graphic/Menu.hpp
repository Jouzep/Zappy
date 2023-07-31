/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

    #include <map>
    #include <string>
    #include <memory>

    #include "raylib-cpp.hpp"
    #include "Cube.hpp"
    #include "Rectangle.hpp"

namespace Zappy {
    class Menu {
        public:
            Menu();
            ~Menu();

            void setData(std::shared_ptr<Data>);
            void setCamera();
            void setTexture();
            void setCube();
            void setRectangle();
            void setMusic();
            void run();

            void event();
            void settingsEvent();
            void settingsButtonEvent();
            void volumeEvent(std::string);

            void howToPlayEvent();
            void drawHowToPlay();

            void draw();
            void drawText();
            void drawLogo();
            void drawButton();
            void drawBackground();
            void drawSettings();
            void drawVolume();
            void drawFramerate();

            void mouseHovering();
            void mouseClicking();

            bool getPrincipaleMenu();
            void drawReturnButton();

        protected:
        private:
            raylib::Camera3D _cameraMenu;

            std::map<std::string, raylib::Texture2D> _texture;
            std::map<std::string, std::shared_ptr<Rect>> _rectangle;
            std::map<std::string, Cube> _cube;
            std::shared_ptr<Data> _data;

            Music _music;
            Sound _click;

            bool _principalMenu = true;
            bool _howToPlay = false;
            bool _settings = false;
            bool _return = false;
            float _volume = 0.0;
            bool _isVolume = false;
            bool _isFramerate = false;
            Rectangle _rect = { 470, 356, 50, 88};
            Rectangle _rect2 = { 470, 656, 50, 88};
            Vector2 offset = { 0, 0 };
            int _fps = 30;
            const int _maxFps = 90;
            const int _minFps = 30;

            int _volumePercentage = 1;

    };
}

#endif /* !MENU_HPP_ */