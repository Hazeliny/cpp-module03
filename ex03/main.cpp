/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:39:00 by linyao            #+#    #+#             */
/*   Updated: 2024/11/14 15:43:56 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

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
/*
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
*/
/*
	std::cout << "\033[34mConstructing...\033[0m" << std::endl;
	FragTrap e;
	FragTrap f("Alice");

	std::cout << "\033[34mTesting...\033[0m" << std::endl;
	e.highFivesGuys();
	e.attack("Mary");
	e.takeDamage(101);
	e.beRepaired(100);
	e.highFivesGuys();
	e.takeDamage(1);
	e.attack("ET");
	f.highFivesGuys();
	for(int i = 0; i < 6; i++)
		f.attack("savage");
	f.takeDamage(99);
	f.beRepaired(100);
	f.highFivesGuys();
	std::cout << "\033[34mDeconstructing...\033[0m" << std::endl;
*/

	std::cout << "\033[34mConstructing...\033[0m" << std::endl;
	DiamondTrap a;
	DiamondTrap b("brilliance");
	DiamondTrap c(a);

	std::cout << "\033[34mTesting...\033[0m" << std::endl;
	a.whoAmI();
	a.attack("darkness");
	b.whoAmI();
	b.attack("prejudice");
	c.whoAmI();
	std::cout << "\033[34mDeconstructing...\033[0m" << std::endl;
				
    return 0;
}
