/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:16:18 by linyao            #+#    #+#             */
/*   Updated: 2024/11/14 13:13:02 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
    std::cout << "default constructor of the derived class ScavTrap called" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}
        
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "constructor of the derived class ScavTrap for the name " << this->_name << " called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &other) : ClapTrap(other) {
    std::cout << "copy constructor of the derived class ScavTrap called" << std::endl;
}

ScavTrap::~ScavTrap(void) {
    std::cout << "destructor of the derived class ScavTrap for " << this->_name << " called" << std::endl;
}
        
ScavTrap &ScavTrap::operator=(ScavTrap const &other) { // overloaded assignment operator
    std::cout << "assignment operator of the derived class ScavTrap called" << std::endl;
//    this->_name = other._name;
//    this->_hitPoints = other._hitPoints;
//    this->_energyPoints = other._energyPoints;
//    this->_attackDamage = other._attackDamage;
    ClapTrap::operator=(other);
    return (*this);
}
        
void ScavTrap::attack(std::string const &target) {
    if (this->_hitPoints < 1 && this->_energyPoints < 1)
        std::cout << "\033[31mScavTrap " << this->_name << " cannot attack " << target << " because he has neither hit points nor energy points\033[0m" << std::endl;
    else if (this->_energyPoints < 1)
        std::cout << "\033[31mScavTrap " << this->_name << " cannot attack " << target << " because he's run out of energy points\033[0m" << std::endl;
    else if (this->_hitPoints < 1)
        std::cout << "\033[31mScavTrap " << this->_name << " cannot attack " << target << " because he's run out of hit points\033[0m" << std::endl;
    else {
        this->_energyPoints--;
        std::cout << "\033[32mScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!";
        std::cout << " And losing 1 energy point! Currently his energy points is " << this->_energyPoints << "\033[0m" << std::endl;
    }
}
        
void  ScavTrap::guardGate(void) {
    if (this->_hitPoints < 1)
        std::cout << "\033[31mScavTrap " << this->_name << " cannot guard the gate because he's run out of hit points and is dead\033[0m" << std::endl;
    else
        std::cout << "\033[32mScavTrap " << this->_name << " guards the gate, keeping it safe from any intruders\033[0m" << std::endl;
}
