/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

#include "IComponent.hpp"
#include <vector>
#include "Pin.hpp"

class AComponent : public nts::IComponent {
    public:
        AComponent(const std::string &name);
        ~AComponent();
        nts::Tristate compute(size_t pin = 1);
        void setLink(size_t pin, nts::IComponent &other, size_t otherPin);
        void dump() const;
        Pin *getPinInput(size_t pin) const;
        Pin *getPinOutput(size_t pin) const;
        void changeStatePinInput(nts::Tristate state, size_t pin);
        void changeStatePinOutput(nts::Tristate state, size_t pin);
        void setName(std::string name);
        std::string getName() const;
    protected:
        std::vector<Pin *> *_input;
        std::vector<Pin *> *_output;
    private:
        std::string _name;
};

#endif /* !ACOMPONENT_HPP_ */
