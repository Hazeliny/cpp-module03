/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:33:24 by linyao            #+#    #+#             */
/*   Updated: 2024/11/14 16:34:59 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
    std::cout << "default constructor of the derived class FragTrap called" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "constructor of the derived class FragTrap for the name " << this->_name << " called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &other) : ClapTrap(other) {
    std::cout << "copy constructor of the derived class FragTrap called" << std::endl;
}

FragTrap::~FragTrap(void) {
    std::cout << "destructor of the derived class FragTrap for " << this->_name << "called" << std::endl;
}
        
FragTrap &FragTrap::operator=(FragTrap const &other) {
    std::cout << "assignment operator of the derived class FragTrap called" << std::endl;
    ClapTrap::operator=(other);
    return (*this);
}

void FragTrap::highFivesGuys(void) {
    if (this->_hitPoints < 1)
        std::cout << "\033[31mFragTrap " << this->_name << " cannot high five more for being dead already\033[0m" << std::endl;
    else
        std::cout << "\033[32mFragTrap " << this->_name << " High Fives Everyone!\033[0m" << std::endl;
}
