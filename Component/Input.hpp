/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Input
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include "../Pin.hpp"
#include "../IComponent.hpp"
#include "../AComponent.hpp"

class Input : public AComponent {
    public:
        Input(const std::string &name, size_t state);
        ~Input();
            nts::Tristate compute(size_t pin = 1);
            void dump() const;
            void setState(size_t state);
    protected:
    private:
};

#endif /* !INPUT_HPP_ */
