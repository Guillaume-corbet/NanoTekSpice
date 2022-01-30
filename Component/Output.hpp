/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Output
*/

#ifndef OUTPUT_HPP_
#define OUTPUT_HPP_

#include "../Pin.hpp"
#include "../IComponent.hpp"
#include "../AComponent.hpp"

class Output : public AComponent {
    public:
        Output(const std::string &name);
        ~Output();
            nts::Tristate compute(size_t pin = 1);
            void dump() const;
    protected:
    private:
};

#endif /* !OUTPUT_HPP_ */
