/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** TimeUnit
*/

#ifndef TIMEUNIT_HPP_
#define TIMEUNIT_HPP_
    #include <iostream>

namespace Zappy {
    class TimeUnit {
        public:
            TimeUnit();
            ~TimeUnit();

            /**
             * @brief Get the TimeUnit 
             * 
             * @return int 
             */
            int getTimeUnit() const;

            /**
             * @brief Set the TimeUnit
             * 
             */
            void setTimeUnit(int);

            /**
             * @brief Set the Fps 
             * 
             * @param fps 
             */
            void setFps(float fps);

            float getFps() const;

            float getSecondPerFrame() const;

            float getActionTime(float action);

        protected:
        private:
            int _timeUnit;
            float _secondPerFrame;
            float _fps;
    };
}

#endif /* !TIMEUNIT_HPP_ */
