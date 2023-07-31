/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** main
*/

#include "Error.hpp"
#include "Parser.hpp"
#include "Gui.hpp"
#include "macro.hpp"

void show_usage(char *binary)
{
    std::cout << "USAGE: " << binary << " -p port -h machine" << std::endl;
    std::cout << "\tport\tis the port number" << std::endl;
    std::cout << "\tmachine\tis the name of the machine; localhost by default" << std::endl;
}

int main(const int ac, char *const *av)
{
        if (ac == 2 && std::strcmp(av[1], "-help") == 0) {
            show_usage(av[0]);
            return MY_EXIT_SUCCESS;
        }

        try {
            Zappy::Parser parser(ac, av);
            Zappy::Gui Gui(parser.getPort(), parser.getMachine());
            Gui.run();
        }
        catch (Error &e)
        {
            std::cerr << e.what() << std::endl;
            return MY_EXIT_FAILURE;
        }
        return MY_EXIT_SUCCESS;
    return 0;
}