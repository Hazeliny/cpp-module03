/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:17:24 by linyao            #+#    #+#             */
/*   Updated: 2024/11/14 13:17:36 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0){
    std::cout << "default constructor of the base class ClapTrap called" << std::endl;
}
        
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
    std::cout << "constructor of the base class ClapTrap with the name " << _name << " called" << std::endl;
}
        
ClapTrap::ClapTrap(ClapTrap const &other) {
    std::cout << "copy constructor of the base class ClapTrap called" << std::endl;
    *this = other;
}
        
ClapTrap::~ClapTrap(void) {
    std::cout << "destructor of the base class ClapTrap called" << std::endl;
}
        
ClapTrap &ClapTrap::operator=(ClapTrap const &other) {
    std::cout << "reloaded assignment operator of the base class ClapTrap called" << std::endl;
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return (*this);
}
        
void ClapTrap::attack(const std::string& target) {
    if (this->_hitPoints < 1 && this->_energyPoints < 1)
        std::cout << "\033[31mClapTrap " << this->_name << " cannot attack " << target << " because he has neither hit points nor energy points\033[0m" << std::endl;
    else if (this->_energyPoints < 1)
        std::cout << "\033[31mClapTrap " << this->_name << " cannot attack " << target << " because he's run out of energy points\033[0m" << std::endl;
    else if (this->_hitPoints < 1)
        std::cout << "\033[31mClapTrap " << this->_name << " cannot attack " << target << " because he's run out of hit points\033[0m" << std::endl;
    else {
        this->_energyPoints--;
        std::cout << "\033[32mClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!";
        std::cout << " And losing 1 energy point! Currently his energy points is " << this->_energyPoints << "\033[0m" << std::endl;
    }
}
        
void ClapTrap::takeDamage(unsigned int amount) {
    if ((this->_hitPoints <= amount && this->_hitPoints > 0) || this->_hitPoints == 0) {
        std::cout << "\033[33mClapTrap " << this->_name << " is already dead\033[0m" << std::endl;
        this->_hitPoints = 0;
        return ;
    }
    if (this->_hitPoints > amount)
        this->_hitPoints -= amount;
    std::cout << "\033[31mClapTrap " << this->_name << " loses " << amount << " hit points, currently his hit points is " << this->_hitPoints << "\033[0m" << std::endl;
}
        
void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_energyPoints > 0 && this->_hitPoints > 0 && this->_hitPoints + amount <= 101) {
        this->_hitPoints += amount;
        this->_energyPoints--;
        std::cout << "ClapTrap " << this->_name << " has been repaired for " << amount << " hit points, his current hit points is " << this->_hitPoints;
        std::cout << ", costing 1 energy point, his current energy points is " << this->_energyPoints << std::endl;
    }
    else if (this->_energyPoints == 0)
        std::cout << "ClapTrap " << this->_name << " has no energy points left, cannot be repaired" << std::endl;
    else if (this->_hitPoints == 0)
        std::cout << "ClapTrap " << this->_name << " has no hit points left, he's dead, cannot be repaired" << std::endl;
    else
        std::cout << "ClapTrap " << this->_name << " has already reached full health, cannot be repaired" << std::endl;
}
