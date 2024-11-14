/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:39:00 by linyao            #+#    #+#             */
/*   Updated: 2024/11/14 13:22:23 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void) {
/*
    ClapTrap a;
    ClapTrap b("Bob");

    a.attack("John");
    a.takeDamage(6);
    a.takeDamage(3);
    a.beRepaired(5);
    a.attack("David");
    b.beRepaired(3);
    for (int i = 0; i < 12; i++)
        b.attack("Adam");
    b.beRepaired(3);
*/
    std::cout << "\033[34mConstructing ScavTrap...\033[0m" << std::endl;
	ScavTrap c;
	ScavTrap d("Adam");

	std::cout << "\033[34mTesting...\033[0m" << std::endl;
	c.attack("Henry");
	for (int i = 0; i < 8; i++)
	 	c.attack("Henry");
	c.beRepaired(30);
	c.takeDamage(21);
	c.beRepaired(15);
	c.guardGate();
	d.attack("Savage");
	d.takeDamage(120);
	d.beRepaired(32);
	d.attack("ET");
	std::cout << "\033[34mDeconstructing ScavTrap...\033[0m" << std::endl;

    return 0;
}
