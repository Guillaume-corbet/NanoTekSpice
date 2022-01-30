/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** main
*/

#include "Parser.hpp"
#include "Nano.hpp"

int main(int argc, char **argv)
{
    Parser parse;
    Nano nano;

    parse.parser(argc, argv);

    nano.terminal(&parse);
    return (0);
}