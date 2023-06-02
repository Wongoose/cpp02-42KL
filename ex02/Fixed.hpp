/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:04:32 by zwong             #+#    #+#             */
/*   Updated: 2023/06/02 14:39:27 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#define DEFAULT "\033[39m"
#define BLACK "\033[30m"
#define GREY "\033[90m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[94m"
#define MAGENTA "\033[35m"

#include <cmath>
#include <iostream>

class Fixed {
	public:
		Fixed();
		Fixed(const int i);
		Fixed(const float f);
		~Fixed();
		Fixed(const Fixed &fixed);

		// Overload operators
		Fixed &operator=(Fixed fixed);
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);
		Fixed operator+=(const Fixed &rhs);
		Fixed operator-=(const Fixed &rhs);
		Fixed operator*=(const Fixed &rhs);
		Fixed operator/=(const Fixed &rhs);

		static Fixed &min(Fixed &f1, Fixed &f2);
		static const Fixed &min(const Fixed &f1, const Fixed &f2);
		static Fixed &max(Fixed &f1, Fixed &f2);
		static const Fixed &max(const Fixed &f1, const Fixed &f2);

		void swap(Fixed &first, Fixed &second);
		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;

	private:
		int raw_value_;
		static const int fractional_bits_ = 8;

};

// OVERLOADED functions - C++ allows to specify more than one function of the same name
// Different result or use depending on the types and number of arguments
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

bool operator==(const Fixed &lhs, const Fixed &rhs);
bool operator!=(const Fixed &lhs, const Fixed &rhs);
bool operator<(const Fixed &lhs, const Fixed &rhs);
bool operator>(const Fixed &lhs, const Fixed &rhs);
bool operator<=(const Fixed &lhs, const Fixed &rhs);
bool operator>=(const Fixed &lhs, const Fixed &rhs);

Fixed operator+(Fixed lhs, const Fixed &rhs);
Fixed operator-(Fixed lhs, const Fixed &rhs);
Fixed operator*(Fixed lhs, const Fixed &rhs);
Fixed operator/(Fixed lhs, const Fixed &rhs);

#endif