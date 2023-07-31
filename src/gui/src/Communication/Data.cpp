/*
** EPITECH PROJECT, 2023
** gui
** File description:
** Data
*/

#include "Data.hpp"

Zappy::Data::Data(std::string machine, int port) : _socket(machine, port), _select(_socket._socket)
{
    _machine = machine;
    setUpdateFunction();
    char graphic[] = "GRAPHIC\n";
    writeToServer(graphic);
}

Zappy::Data::~Data()
{

}

void Zappy::Data::updateGame()
{
    try {
        _select.doSelect();
        if (FD_ISSET(_socket._socket, &(_select._readfds)))
            readFromServer();
    } catch (const Error &e) {
        std::cout << e.what() << std::endl;
    }
}

void Zappy::Data::readFromServer()
{
    char tmp[6];
    int x = read(_socket._socket, &tmp, sizeof(tmp));
    buffer.append(tmp, x);
    std::memset(tmp, 0, sizeof(tmp));
    validResponse();
}

void Zappy::Data::validResponse()
{
    std::size_t pos = buffer.find('\n');
    std::string response;
    std::string tmp;
    while (pos != std::string::npos) {
        response = buffer.substr(0, pos);
        updateData(response);
        buffer = buffer.substr(pos + 1);
        pos = buffer.find('\n');
    }
}

void Zappy::Data::updateData(std::string response)
{
    try {
        parseResponse(response);
    } catch (const Error &e) {
        std::cout << e.what() << std::endl;
    }
}

void Zappy::Data::sendPinProtocol(std::size_t id)
{
    char tmp[1024] = "pin ";
    strcat(tmp, std::to_string(id).c_str());
    strcat(tmp, "\n");
    write(_socket._socket, tmp, sizeof(tmp));
}

void Zappy::Data::writeToServer(char *str)
{
    write(_socket._socket, str, sizeof(str));
}

/**
 * @brief Split a string into words
 * 
 * @param content 
 * @return std::vector<std::string> 
 */
static std::vector<std::string> splitStringIntoWords(std::string &content)
{
    std::vector<std::string> words;
    std::istringstream iss(content);
    std::string word;

    while (iss >> word)
        words.push_back(word);
    if (words.size() == 0)
        throw Error("Error Server Reponse", "The size of the vector is 0");
    return words;
}

void Zappy::Data::parseResponse(std::string &response)
{
    std::vector<std::string> words = splitStringIntoWords(response);
    std::string guiProtocol = words[0];

    words.erase(words.begin());
    if (_gameUpdater.count(guiProtocol) == 0)
        throw Error("First argument of server response is not valid", guiProtocol);
    _gameUpdater[guiProtocol](words);

}

void Zappy::Data::setUpdateFunction()
{
    // std::function<void(std::string)> func = [this](std::string &value)// { _gameData.msz(value); };
    _gameUpdater.insert({"msz", [this](std::vector<std::string> &value) {_gameData.msz(value);}});
    _gameUpdater.insert({"bct", [this](std::vector<std::string> &value) {_gameData.bct(value);}});
    _gameUpdater.insert({"tna", [this](std::vector<std::string> &value) {_gameData.tna(value);}});
    _gameUpdater.insert({"pnw", [this](std::vector<std::string> &value) {_gameData.pnw(value);}});
    _gameUpdater.insert({"ppo", [this](std::vector<std::string> &value) {_gameData.ppo(value);}});
    _gameUpdater.insert({"plv", [this](std::vector<std::string> &value) {_gameData.plv(value);}});
    _gameUpdater.insert({"pin", [this](std::vector<std::string> &value) {_gameData.pin(value);}});
    _gameUpdater.insert({"pex", [this](std::vector<std::string> &value) {_gameData.pex(value);}});
    _gameUpdater.insert({"pbc", [this](std::vector<std::string> &value) {_gameData.pbc(value);}});
    _gameUpdater.insert({"pic", [this](std::vector<std::string> &value) {_gameData.pic(value);}});
    _gameUpdater.insert({"pie", [this](std::vector<std::string> &value) {_gameData.pie(value);}});
    _gameUpdater.insert({"pfk", [this](std::vector<std::string> &value) {_gameData.pfk(value);}});
    _gameUpdater.insert({"pdr", [this](std::vector<std::string> &value) {_gameData.pdr(value);}});
    _gameUpdater.insert({"pgt", [this](std::vector<std::string> &value) {_gameData.pgt(value);}});
    _gameUpdater.insert({"pdi", [this](std::vector<std::string> &value) {_gameData.pdi(value);}});
    _gameUpdater.insert({"enw", [this](std::vector<std::string> &value) {_gameData.enw(value);}});
    _gameUpdater.insert({"ebo", [this](std::vector<std::string> &value) {_gameData.ebo(value);}});
    _gameUpdater.insert({"eht", [this](std::vector<std::string> &value) {_gameData.edi(value);}});
    _gameUpdater.insert({"sgt", [this](std::vector<std::string> &value) {_gameData.sgt(value);}});
    _gameUpdater.insert({"sst", [this](std::vector<std::string> &value) {_gameData.sst(value);}});
    _gameUpdater.insert({"seg", [this](std::vector<std::string> &value) {_gameData.seg(value);}});
    _gameUpdater.insert({"smg", [this](std::vector<std::string> &value) {_gameData.smg(value);}});
    _gameUpdater.insert({"suc", [this](std::vector<std::string> &value) {_gameData.suc(value);}});
    _gameUpdater.insert({"sbp", [this](std::vector<std::string> &value) {_gameData.sbp(value);}});
}

