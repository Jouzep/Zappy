/*
** EPITECH PROJECT, 2023
** gui
** File description:
** Error
*/

#ifndef ERROR_HPP_
    #define ERROR_HPP_
    #include <exception>
    #include <string>

class Error : public std::exception {
    public:
        Error(const std::string message);
        Error(const std::string message, const std::string label);

        virtual const char* what() const noexcept;

    protected:
    private:
        std::string _message;
};

#endif /* !ERROR_HPP_ */