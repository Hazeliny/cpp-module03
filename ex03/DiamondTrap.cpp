/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:51:10 by linyao            #+#    #+#             */
/*   Updated: 2024/11/14 17:48:30 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("defaultDT_clap_name") {
    this->_name = "defaultDT";
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
    std::cout << "defaultDT: constructor of DiamondTrap called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name") {
    this->_name = name;
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
    std::cout << this->_name << ": constructor of DiamondTrap called" << std::endl;
}
        
DiamondTrap::DiamondTrap(DiamondTrap const &other) : ClapTrap(other), ScavTrap(other), FragTrap(other) {
    *this = other;
    std::cout << this->_name << ": copy constructor of DiamondTrap called" << std::endl;
}
        
DiamondTrap::~DiamondTrap(void) {
    std::cout << this->_name << ": destructor of DiamondTrap called" << std::endl;
}
        
DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other) {
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
        std::cout << this->_name << ": reloaded assignment operator of DiamondTrap called" << std::endl;
    }
    return (*this);
}
        
void DiamondTrap::attack(std::string const &target) {
    ScavTrap::attack(target);
    std::cout << this->_name << ": attack " << target << " within DiamondTrap class from ScavTrap" << std::endl;
}
        
void DiamondTrap::whoAmI(void) {
    std::cout << "I am " << this->_name << " from DiamondTrap, and I am originated from ClapTrap class named ";
    std::cout << ClapTrap::_name << std::endl;
}
