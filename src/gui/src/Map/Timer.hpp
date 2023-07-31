/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Timer
*/

#ifndef TIMER_HPP_
#define TIMER_HPP_

namespace Zappy {
    class Timer {
        public:
            Timer(float);


            ~Timer();

        protected:
        private:
            float _clock;
            float _current;
    };
}

#endif /* !TIMER_HPP_ */
