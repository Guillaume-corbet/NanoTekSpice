/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Nano
*/

#include "Nano.hpp"

Nano::Nano()
{
}

Nano::~Nano()
{
}

void Nano::changeClock(Parser *parse)
{
    size_t c;
    size_t d;
    std::string type;
    std::string name;

    for (size_t i = 0; i < parse->getInputs()->size(); i++) {
        c = parse->getInputs()->at(i).find(' ', 0);
        if (c == std::string::npos)
            c = parse->getInputs()->at(i).find('\t', 0);
        type = parse->getInputs()->at(i).substr(0, c);
        name = parse->getInputs()->at(i).substr(c + 1, parse->getInputs()->at(i).size() - c);
        if (type == "clock") {
            for (size_t j = 0; j < parse->getArgs()->size(); j++) {
                c = parse->getArgs()->at(j).find('=', 0);
                if (name == parse->getArgs()->at(j).substr(0, c)) {
                    if (parse->getArgs()->at(j).substr(c + 1, 1) == "1") {
                        parse->removeArgs(j);
                        parse->addArgs(name + "=0");
                    } else {
                        parse->removeArgs(j);
                        parse->addArgs(name + "=1");
                    }
                }
            }
        }
    }
}

void Nano::setCircuit(Parser *parse, Circuit *circuit)
{
    Factory *factory = new Factory(parse->getArgs());
    std::string type;
    std::string name;
    size_t c;

    circuit->getOutput()->clear();
    circuit->getComponent()->clear();
    for (size_t i = 0; i < parse->getInputs()->size(); i++) {
        c = parse->getInputs()->at(i).find(' ', 0);
        if (c == std::string::npos)
            c = parse->getInputs()->at(i).find('\t', 0);
        type = parse->getInputs()->at(i).substr(0, c);
        name = parse->getInputs()->at(i).substr(c + 1, parse->getInputs()->at(i).size() - c);
        if (type == "output")
            circuit->addOneOutput(factory->createComponent(type, name).release());
        else
            circuit->addOneComponent(factory->createComponent(type, name).release());
    }
}

void Nano::setAllLink(Parser *parse, Circuit *circuit)
{
    size_t c;
    size_t d;
    std::string name;
    std::string namesec;
    std::string nb;
    std::string nbsec;
    size_t len;
    size_t lensec;

    for (size_t y = 0; y < parse->getLinks()->size(); y++) {
        d = parse->getLinks()->at(y).find(':', 0);
        c = parse->getLinks()->at(y).find(' ', 0);
        if (c == std::string::npos)
            c = parse->getLinks()->at(y).find('\t', 0);
        name = parse->getLinks()->at(y).substr(0, d);
        nb = parse->getLinks()->at(y).substr(d + 1, c - d - 1);
        d = parse->getLinks()->at(y).find(':', c);
        namesec = parse->getLinks()->at(y).substr(c + 1, d - c - 1);
        nbsec = parse->getLinks()->at(y).substr(d + 1, parse->getLinks()->at(y).size());
        sscanf(nb.c_str(), "%zu", &len);
        sscanf(nbsec.c_str(), "%zu", &lensec);
        circuit->getOneComponentByName(name)->setLink(len, *circuit->getOneComponentByName(namesec), lensec);
    }
}

void Nano::simulate(Parser *parse, Circuit *circuit)
{
    AComponent *comp;
    
    setCircuit(parse, circuit);
    setAllLink(parse, circuit);
    for (size_t z = 0; z < circuit->getOutput()->size(); z++) {
        comp = dynamic_cast<AComponent *>(circuit->getOutput()->at(z));
        comp->compute(1);
    }
    changeClock(parse);
}

void Nano::display(Circuit *circuit)
{
    AComponent *comp;

    for (size_t z = 0; z < circuit->getOutput()->size(); z++) {
        comp = dynamic_cast<AComponent *>(circuit->getOutput()->at(z));
        std::cout << comp->getName() << "=" << comp->compute(1) << std::endl;
    }
}

void Nano::changeInput(Parser *parse, std::string enter)
{
    size_t pos = enter.find('=', 0);
    size_t nb = 0;

    while (nb < parse->getArgs()->size()) {
        if (parse->getArgs()->at(nb).find(enter.substr(0, pos), 0) != std::string::npos) {
            parse->removeArgs(nb);
            parse->addArgs(enter);
            break;
        }
        nb = nb + 1;
    }
}

void Nano::dumpAll(Circuit *circuit)
{
    for (size_t i = 0; i < circuit->getComponent()->size(); i++) {
        circuit->getComponent()->at(i)->dump();
    }
    for (size_t i = 0; i < circuit->getOutput()->size(); i++) {
        circuit->getOutput()->at(i)->dump();
    }
}

void Nano::terminal(Parser *parse)
{
    std::string enter;
    Circuit *circuit = new Circuit();

    this->simulate(parse, circuit);
    this->display(circuit);
    while (1) {
        std::cout << "> ";
        if (!std::getline(std::cin, enter))
            break;
        if (enter == "exit")
            break;
        else if (enter == "simulate")
            this->simulate(parse, circuit);
        else if (enter == "display")
            this->display(circuit);
        else if (enter.find('=', 0) != std::string::npos)
            this->changeInput(parse, enter);
        else if (enter == "dump")
            this->dumpAll(circuit);
    }
}