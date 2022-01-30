/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Nano
*/

#ifndef NANO_HPP_
#define NANO_HPP_

#include "Parser.hpp"
#include "Circuit.hpp"
#include "Factory.hpp"

class Nano {
    public:
        Nano();
        ~Nano();
        void setCircuit(Parser *parse, Circuit *circuit);
        void setAllLink(Parser *parse, Circuit *circuit);
        void terminal(Parser *parse);
        void dumpAll(Circuit *circuit);
        void changeInput(Parser *parse, std::string enter);
        void display(Circuit *circuit);
        void simulate(Parser *parse, Circuit *circuit);
        void changeClock(Parser *parse);
    protected:
    private:
};

#endif /* !NANO_HPP_ */
