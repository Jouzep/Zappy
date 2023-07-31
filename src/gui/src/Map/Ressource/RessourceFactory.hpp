/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** RessourceFactory
*/

#ifndef RESSOURCEFACTORY_HPP_
#define RESSOURCEFACTORY_HPP_
    #include <memory>
    #include <map>
    #include <functional>

    #include "Sibur.hpp"
    #include "Thystame.hpp"
    #include "Phiras.hpp"
    #include "Mendiane.hpp"
    #include "Linemate.hpp"
    #include "Deraumere.hpp"
    #include "Food.hpp"
    #include "Error.hpp"

namespace Zappy {
    class RessourceFactory {
        public:
            RessourceFactory();
            ~RessourceFactory();

            std::shared_ptr<IRessource> createRessource(std::string &, int);

        protected:
        private:
            std::map<std::string, std::function<std::shared_ptr<IRessource>(int)>> _builder;
    };
}

#endif /* !RESSOURCEFACTORY_HPP_ */
