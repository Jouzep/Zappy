/*
** EPITECH PROJECT, 2023
** gui
** File description:
** OptionsParser
*/

#ifndef OPTIONSPARSER_HPP_
    #define OPTIONSPARSER_HPP_
    #include <unistd.h>

class OptionsParser {
    public:
        static int getopt(int argc, char * const argv[], const char *optstring);
        static char *getOptarg();
    protected:
    private:
};

#endif /* !OPTIONSPARSER_HPP_ */