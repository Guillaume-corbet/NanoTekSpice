/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <iostream>
#include <vector>
#include <fstream>
#include <string_view>
#include <string>
#include "Pin.hpp"
#include "Circuit.hpp"
#include "Component/Component4001.hpp"

class Parser {
    public:
        Parser();
        ~Parser();
        int parser(int argc, char **argv);
        std::vector<std::string> *getArgs() const;
        std::vector<std::string> *getInputs() const;
        std::vector<std::string> *getLinks() const;
        void setArgs(std::vector<std::string> *args);
        void setInputs(std::vector<std::string> *inputs);
        void setLinks(std::vector<std::string> *links);
        void removeArgs(size_t pos);
        void addArgs(std::string args);
    protected:
    private:
        std::vector<std::string> readFile(std::string filename);
        std::string cleanLine(std::string line);
        std::vector<std::string> cleanFile(std::vector<std::string> vecFile);
        bool isInputError(std::vector<std::string> input);
        bool isOutputError(std::vector<std::string> output);
        bool isError(std::vector<std::string> vecFile);
        std::vector<std::string> *_vecArgs;
        std::vector<std::string> *_vecInputs;
        std::vector<std::string> *_vecLinks;
};

#endif /* !PARSER_HPP_ */