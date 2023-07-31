/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** IRessource
*/

#ifndef IRESSOURCE_HPP_
#define IRESSOURCE_HPP_

namespace Zappy {
    class IRessource {
        public:
            virtual ~IRessource() = default;

            virtual int getQuantity() const = 0;

            virtual void setQuantity(int) = 0;

        protected:
        private:
    };
}

#endif /* !IRESSOURCE_HPP_ */
