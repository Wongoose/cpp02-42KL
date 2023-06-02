/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:04:28 by zwong             #+#    #+#             */
/*   Updated: 2023/06/02 15:23:28 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Objective: Printing in std::cout for my custom Fixed class "<<"

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
		std::cout << GREEN << "---- Number as Fixed and Integer ----" << std::endl;
		float f1 = 999.9f;
		float f2 = 0.0001f;
		
		Fixed a;
		Fixed const b(10);
		Fixed const c(42.72f);
		Fixed const d(b);

		a = Fixed(1234.1234f);

		std::cout << std::endl;
		
		// Show inaccuracy of original float
		std::cout << "f1 is " << f1 << std::endl;
		std::cout << "f2 is " << f2 << std::endl;
		std::cout << "f2 - f2 is " << f1 - f2 << std::endl;
		// Can't test fixed minus in ex01, haven't assigned operator for Fixed class

		std::cout << std::endl;
		
		std::cout << "a is " << a  << " as Fixed" << std::endl;
		std::cout << "b is " << b  << " as Fixed" << std::endl;
		std::cout << "c is " << c  << " as Fixed" << std::endl;
		std::cout << "d is " << d  << " as Fixed" << std::endl;

		std::cout << std::endl;

		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;		
	}
	{
		std::cout << std::endl;
		std::cout << MAGENTA << "---- Rawbits vs Fixed comparison ----" << std::endl;
		// Everything in binary base 2
		// Whole number starts from 2^8 onwards
		// 2^0 to 2^7 are reserved for Fractional number (aka decimals)
		// 0.5 is 2^-1 which is 128 rawbits

		Fixed a;
		Fixed b;

		a.setRawBits(256);
		b = Fixed(1); 

		std::cout << "a is " << a  << " as Fixed" << std::endl;
		std::cout << "b is " << b  << " as Fixed" << std::endl;
		std::cout << "b is " << b.getRawBits()  << " as Rawbits" << std::endl;
	}

	return (0);
}
