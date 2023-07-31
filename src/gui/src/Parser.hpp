/*
** EPITECH PROJECT, 2023
** gui
** File description:
** Parser
*/

#ifndef PARSER_HPP_
    #define PARSER_HPP_
    #include "Error.hpp"

namespace Zappy {
    class Parser {
        public:
            Parser(const int ac, char *const *av);
            ~Parser();

            int getPort();
            std::string getMachine();

        protected:
        private:
            int _port = -1;
            std::string _machine = "localhost";
    };
}

#endif /* !PARSER_HPP_ */