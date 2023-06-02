/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:04:33 by zwong             #+#    #+#             */
/*   Updated: 2023/06/02 15:24:18 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iomanip>

// A fixed point number has a specific number of bits (or digits) reserved for the integer part (the part to the left of the decimal point)
// and a specific number of bits reserved for the fractional part (the part to the right of the decimal point).
// IIIII.FFFFF, 99999.00001
// Fixed vs Float:
// Fixed can store smaller numbers, with high accuracy and precision
// Float can store larger numbers, with low accuracy
// e.g. For floats, 999.9 - 0.000000000001 = 999.9 (no change cause 0.00000000001 is too precise, rounded off to 0.00000)
// e.g. For Fixed, I can set left and right side to a certain size. Hence, 999.9000 - 0.0001 = 999.8999 (doesn't round off, cuz it's set as 2 separate allocation)

// ALSO, float are usually stored with 00000000+eXX bits for numbers, remembering where the decimal is, and exponential
int main(void) {
	{
		std::cout << std::endl;
		std::cout << GREEN << "--- Float vs Fixed TEST---" << std::endl;

		float f1 = 999.9f;
		float f2 = 0.0001f;

		std::cout << "FLOAT RESULT:" << std::endl;
		std::cout << "f1 - f2 = " << f1 - f2 << std::endl;

		std::cout << std::endl;
		
		Fixed fixed1 = Fixed(999.9f);
		Fixed fixed2 = Fixed(0.0001f);
		std::cout << "FIXED RESULT:" << std::endl;
		std::cout << "fixed1 - fixed2 = " << fixed1 - fixed2 << std::endl;
		
	}
	{
		std::cout << std::endl;
		std::cout << MAGENTA << "--- SUBJECT PDF TEST---" << std::endl;
		
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
	}
	return (0);
}
