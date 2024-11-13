/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:39:00 by linyao            #+#    #+#             */
/*   Updated: 2024/11/13 22:55:29 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
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

    return 0;
}
