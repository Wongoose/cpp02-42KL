/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:04:33 by zwong             #+#    #+#             */
/*   Updated: 2023/05/26 13:04:36 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iomanip>

int main(void) {
	std::cout << std::endl;
	std::cout << "--- SUBJECT PDF TEST---" << std::endl;
	
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << "a is: " << a << std::endl;
	std::cout << "++a is: " << ++a << std::endl;
	std::cout << "a is: " << a << std::endl;
	std::cout << "a++ is: " << a++ << std::endl;
	std::cout << "a is: " << a << std::endl;
	std::cout << "a++ is: " << a++ << std::endl;
	std::cout << "a is: " << a << std::endl;

	std::cout << "b is: " << b << std::endl;

	std::cout << "Max is: " << Fixed::max(a, b) << std::endl;

	a += b;

	std::cout << " a += b called" << std::endl;

	std::cout << "a is: " << a << std::endl;

	std::cout << std::endl;


	// Fixed a;
	// Fixed const b(10);
	// Fixed const c(42.72f);
	// Fixed const d(b);

	// a = Fixed(1234.1234f);

	// std::cout << std::endl;
	
	// std::cout << "a is " << a << std::endl;
	// std::cout << "b is " << b << std::endl;
	// std::cout << "c is " << c << std::endl;
	// std::cout << "d is " << d << std::endl;

	// std::cout << std::endl;

	// std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	// std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	// std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	// std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	
	// std::cout << std::endl;
	return (0);
}
