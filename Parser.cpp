/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Parser
*/

#include "Parser.hpp"

Parser::Parser()
{
    this->_vecArgs = new std::vector<std::string>;
    this->_vecInputs = new std::vector<std::string>;
    this->_vecLinks = new std::vector<std::string>;
}

Parser::~Parser()
{
}

std::vector<std::string> Parser::readFile(std::string filename)
{
    std::vector<std::string> vecFile;
    std::string line;
    std::ifstream file;

    file.open(filename);
    while (file.is_open() && getline (file,line))
    {
        vecFile.push_back(line);
    }
    file.close();
    return (vecFile);
}

std::string Parser::cleanLine(std::string line)
{
    size_t i = 0;

    while (i < line.size()) {
        if (line.at(i) == ' ' || line.at(i) == '\t') {
            if (line.at(i - 1) != ':')
                i = i + 1;
            while (i < line.size() && (line.at(i) == ' ' || line.at(i) == '\t'))
                line.erase(line.begin() + i);
            if (line.at(i) == ':')
                line.erase(line.begin() + i - 1);
        }
        if (line.at(i) == '#') {
            while (i < line.size())
                line.erase(line.begin() + i);
        }
        i = i + 1;
    }
    return (line);
}

std::vector<std::string> Parser::cleanFile(std::vector<std::string> vecFile)
{
    size_t i = 0;

    while (i < vecFile.size()) {
        vecFile.at(i) = this->cleanLine(vecFile.at(i));
        if (vecFile.at(i).size() == 0) {
            vecFile.erase(vecFile.begin() + i);
            i = i - 1;
        }
        i = i + 1;
    }
    return (vecFile);
}

std::vector<std::string> *Parser::getArgs() const
{
    return (this->_vecArgs);
}

std::vector<std::string> *Parser::getInputs() const
{
    return (this->_vecInputs);
}

std::vector<std::string> *Parser::getLinks() const
{
    return (this->_vecLinks);
}

void Parser::setArgs(std::vector<std::string> *args)
{
    this->_vecArgs = args;
}

void Parser::setInputs(std::vector<std::string> *input)
{
    this->_vecInputs = input;
}

void Parser::setLinks(std::vector<std::string> *link)
{
    this->_vecLinks = link;
}

bool Parser::isInputError(std::vector<std::string> input)
{
    size_t i = 0;
    size_t found = 0;
    size_t j = 0;
    std::string list[19] = {"input", "output", "4001", "4008", "4011",
    "4013", "4017", "4030", "4040", "4069", "4071", "4081", "4094",
    "4514", "4801", "2716", "clock", "true", "false"};

    while (i < input.size()) {
        while (j < list->size()) {
            if (list[j] == input.at(i).substr(0, list[j].size()))
                break;
            j = j + 1;
        }
        if (j == list->size())
            return (true);
        j = 0;
        found = input.at(i).find(' ', 0);
        if (found == std::string::npos)
            found = input.at(i).find('\t', 0);
        if (found == std::string::npos)
            return (true);
        i = i + 1;
    }
    return (false);
}

bool Parser::isOutputError(std::vector<std::string> output)
{
    return (false);
}

bool Parser::isError(std::vector<std::string> vecFile)
{
    size_t i = 1;

    if (vecFile.at(0) != ".chipsets:")
        return (true);
    while (i < vecFile.size()) {
        if (vecFile.at(i) == ".links:")
            break;
        this->_vecInputs->push_back(vecFile.at(i));
        i = i + 1;
    }
    if (i == vecFile.size())
        return (true);
    i = i + 1;
    while (i < vecFile.size()) {
        this->_vecLinks->push_back(vecFile.at(i));
        i = i + 1;
    }
    return (isInputError(*this->_vecInputs) || isOutputError(*this->_vecLinks));
}

void Parser::removeArgs(size_t pos)
{
    this->_vecArgs->erase(this->_vecArgs->begin() + pos);
}

void Parser::addArgs(std::string args)
{
    this->_vecArgs->push_back(args);
}

int Parser::parser(int argc, char **argv)
{
    int i = 2;
    std::vector<std::string> vecFile;

    if (argc < 2) {
        std::cerr << "ET LE FICHIER LA CON DE TOI" << std::endl;
        return (84);
    }
    while (i < argc) {
        this->_vecArgs->push_back(argv[i]);
        i = i + 1;
    }
    vecFile = this->readFile(argv[1]);
    vecFile = this->cleanFile(vecFile);
    this->isError(vecFile);
    //if (isError(vecFile))
    //    throw std::exception();
    return (0);
}